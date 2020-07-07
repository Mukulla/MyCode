#include "Calculator.h"

double Calculate(std::string String001)
{
	//Если строка пустая, то передаём ноль
	if (String001 == "")
	{
		return 0;
	}
	//Добавляем нулевой символ, если его нет
	if (String001[String001.length() - 1] != '\0')
	{
		String001 += '\0';
	}
	//Создаём временную строку
	std::string PreparedStirng = "";

	//Заполняем разрешёнными символами
	PrepareString(String001, PreparedStirng);
	//Если в итоге эта строка пустая, выходим из функции и передаём ноль
	if (PreparedStirng == "")
	{
		return 0;
	}

	//Получаем границы всей строки для вычисления
	Str_Borders FullStringBorders;
	FullStringBorders.Min = PreparedStirng.c_str();
	FullStringBorders.Max = PreparedStirng.c_str() + PreparedStirng.length();

	return CalculateSubString(FullStringBorders);
}
void PrepareString(std::string& Original, std::string& Recycled)
{
	//Указатель на начало строки
	const char* Pointer = Original.c_str();
	//Ищем разрешённые смиволы и добавляем их в строку
	while (*Pointer)
	{
		//Добавляем разрешённые символы в строку
		if (Compare(*Pointer, "0123456789,.") || Compare(*Pointer, "+-*/^") || Compare(*Pointer, "()"))
		{
			Recycled += *Pointer;
		}
		++Pointer;
	}
}
double CalculateSubString(Str_Borders& StringBorders)
{
	//Создаём список исполнительных единиц
	std::list< Str_ExecUnit > List001 = FillList(StringBorders);
	//Передаём итоговый результат
	return CalculateList(List001);
}
std::list< Str_ExecUnit > FillList(Str_Borders& BordersString)
{
	//Создаём список исполнительных единиц
	std::list< Str_ExecUnit > List001;

	//Структура для передачи
	Str_ExecUnit Transfer;
	Transfer.Action = 0;
	Transfer.Value = 0;

	//Создаём указатель на начало строки
	const char* IteratorString = BordersString.Min;

	//Знак числа
	int Sign = 1;

	//Так как может быть слева максимум только два знака и ближайший из двух обязательно минус,
	//то создаём массив с двумя значениями действий
	//Значения по умолчанию отрицательные, так как таких индексов действий нет
	int Actions[] = { -1, -1 };

	//Границы для вычисления в скобках
	Str_Borders HookBorders;

	//Ищем первый числовой символ
	//или пропускаем все нечисловые до следующего числового
	while (IteratorString < BordersString.Max)
	{
		if (*IteratorString == '(')
		{
			//Заполняем массив с действиями
			FillAction(BordersString, IteratorString, &Actions[0], 2);
			//На его основе
			//Получаем знак
			Sign = GetSign(&Actions[0], 2);
			//Получаем номер действия
			Transfer.Action = GetAction(&Actions[0], 2);

			//Запоминаем левую скобку
			HookBorders.Min = (IteratorString + 1);
			//Пропускаем до последней
			IteratorString = SkipHooks(BordersString, IteratorString);
			//Запоминаем последнюю
			HookBorders.Max = IteratorString;

			//Вычисляем выражение в скобках и передаём в текущий массив
			Transfer.Value = CalculateSubString(HookBorders);
			//PrintValue( Transfer.Value );

			//Добавляем в список вычиселнное значение со знаком
			List001.push_back(Transfer);
		}
		if (Compare(*IteratorString, "0123456789,."))
		{
			//Заполняем массив с действиями
			FillAction(BordersString, IteratorString, &Actions[0], 2);
			//На его основе
			//Получаем знак
			Sign = GetSign(&Actions[0], 2);
			//Получаем номер действия
			Transfer.Action = GetAction(&Actions[0], 2);
			//Получаем строку с дсятичным числом, собрав все находящиеся рядом числовые символы и умножив на полученный знак
			Transfer.Value = Sign * StringToDouble(CollectNumbers(BordersString, IteratorString));

			//Добавляем в список вычиселнное значение со знаком
			List001.push_back(Transfer);

			//Пропускаем до следующего знака действия
			while (Compare(*IteratorString, "0123456789,.") && IteratorString < BordersString.Max)
			{
				++IteratorString;
			}
		}
		++IteratorString;
	}
	return List001;
}
const char* SkipHooks(Str_Borders& BordersString, const char* Iterator)
{
	//Счётчик скобок
	int Count = 0;
	while (Iterator < BordersString.Max)
	{
		if (*Iterator == '(')
		{
			++Count;
		}
		if (*Iterator == ')')
		{
			--Count;
		}
		if (!Count)
		{
			break;
		}
		++Iterator;
	}
	return Iterator;
}
void FillAction(Str_Borders& BordersString001, const char* Iterator, int* ArrayActions, int Length001)
{
	//Сбрасываем значения в массиве
	ArrayActions[0] = -1;
	ArrayActions[1] = -1;
	//Счётчик и индекс массива
	int Counter = 1, Access = 0;
	//Ищем слева от числа знаки и записываем два первых из них до первого попавшегося симола числа или левого конца строки
	while ((Iterator - Counter) >= BordersString001.Min)
	{
		//Если это символ действия
		if ( Compare(*(Iterator - Counter), "+-*/^"))
		{
			//Записываем его
			ArrayActions[Access] = NumberAction(*(Iterator - Counter));
			//Увеличиваем индекс
			++Access;
			//Если больше индекса последнего элемента, выходим из цикла
			if (Access > (Length001 - 1))
			{
				break;
			}
		}
		//Как только попадается первый числовой символ, сбрасываем
		if (Compare(*(Iterator - Counter), "0123456789,."))
		{
			break;
		}
		++Counter;
	}
}
int GetSign(int* ArrayActions, int Length001)
{
	//В соответствии со значениями массива передаём действие
	//Если кроме знака минус слева ничего нет, то его и передаём
	//Число положительное
	if (ArrayActions[0] == AC_SUBSTRACT && ArrayActions[1] < 0)
	{
		return 1;
	}
	//Если кроме знака минус есть любой другой знак,
	//то передаём этот знак
	//Знак числа в таком случае будет отрицательным
	if (ArrayActions[0] == AC_SUBSTRACT && ArrayActions[1] > -1)
	{
		return -1;
	}
	//Если же первый знак не минус, то независимо от второго значения передаём этот первый знак
	//Число положительное
	return 1;
}
int GetAction(int* ArrayActions, int Length001)
{
	//Если слева от числа нет никаких других, то смысла в любом действии нет
	//Передаём нулевое
	if (ArrayActions[0] < 0)
	{
		return 0;
	}
	//В соответствии со значениями массива передаём действие
	//Если кроме знака минус слева ничего нет, то его и передаём
	//Число положительное
	if (ArrayActions[0] == AC_SUBSTRACT && ArrayActions[1] < 0)
	{
		return ArrayActions[0];
	}
	//Если кроме знака минус есть любой другой знак,
	//то передаём этот знак
	//Знак числа в таком случае будет отрицательным
	if (ArrayActions[0] == AC_SUBSTRACT && ArrayActions[1] > -1)
	{
		return ArrayActions[1];
	}
	//Если же первый знак не минус, то независимо от второго значения передаём этот первый знак
	//Число положительное
	return ArrayActions[0];
}
int NumberAction(char Symbol001)
{
	//Символы для сравнения
	const char* Alpha = "+-*/^";
	//Итератор
	int Iterator = 0;
	//Проверяем и передаём номер действия
	while (*Alpha)
	{
		if (*Alpha == Symbol001)
		{
			return Iterator;
		}
		++Iterator;
		++Alpha;
	}
	//Если совпадения не нашлось, то передаём -1
	return -1;
}
std::string CollectNumbers(Str_Borders& BordersString001, const char* Iterator)
{
	//Временная строка для передачи числа в строке
	std::string TempoString = "";
	//Если найдена хотя бы одна точка или запятая
	bool Finded = false;
	while (Iterator < BordersString001.Max)
	{
		//Находим первую попавшуюся точку или запятую и добавляем её в строку
		if (!Finded && Compare(*Iterator, ",."))
		{
			TempoString += *Iterator;
			Finded = true;
			continue;
		}
		if (Compare(*Iterator, "0123456789"))
		{
			TempoString += *Iterator;
		}
		//Если попадается неразрешённый символ, прерываем
		if (!Compare(*Iterator, "0123456789,."))
		{
			break;
		}
		++Iterator;
	}
	//Передаём число
	return TempoString;
}
double StringToDouble(std::string String001)
{
	//Временное значение для накопления результата
	double Value = 0;
	//Получаем длинну строки
	unsigned int Length = String001.length();
	//Индекс точки или запятой
	unsigned int NumberDot = 0;
	for (unsigned int i = 0; i < Length; ++i)
	{
		if (Compare(String001[i], ",."))
		{
			NumberDot = i;
			break;
		}
	}

	//Если точки или запятой нет
	if (!NumberDot)
	{
		//Вычисляем только десятичную часть
		for (unsigned int i = 0; i < Length; ++i)
		{
			Value += (double)(String001[i] - '0') * MyPower(10.0, (double)(Length - i - 1));
		}
	}
	else
	{
		//Вычисляем только десятичную часть
		for (unsigned int i = 0; i < NumberDot; ++i)
		{
			Value += (double)(String001[i] - '0') * MyPower(10.0, (double)(NumberDot - i - 1));

		}
		//Вычисляем дробную часть
		for (unsigned int i = NumberDot + 1; i < Length; ++i)
		{
			Value += (double)(String001[i] - '0') / MyPower(10.0, (double)(i - NumberDot));
		}
	}
	//Передаём значение
	return Value;
}
double CalculateList(std::list< Str_ExecUnit> &List001)
{
	//Накопитель с итоговым результатом
	double Hoarder = 0.0, TempoHoarder = 0.0;
	//Указатель на следующий элемент списка
	auto Next = List001.begin();
	//Вычисляем
	for (auto Current = List001.begin(); Current != List001.end(); ++Current)
	{
		//Смещаем на следующий элемент списка
		if (Next != List001.end())
		{
			++Next;
		}
		//Если номер действия не отрицательный
		if (Current->Action > -1)
		{
			if (Next != List001.end())
			{
				//Если текущее действие меньше чем умножение, а следующее больше чем вычитание по приоритету
				if (Current->Action < AC_MULTIPLY && Next->Action > AC_SUBSTRACT)
				{
					DoAction(TempoHoarder, *Current);
					while (Next->Action > AC_SUBSTRACT)
					{
						DoAction(TempoHoarder, *Next);
						++Next;
						++Current;
						if (Next == List001.end())
						{
							break;
						}
					}
					Hoarder += TempoHoarder;
					TempoHoarder = 0;
					continue;
				}
			}
		}
		//Во всех остальных случаях просто вычисляем и добавляем в накопитель		
		DoAction(Hoarder, *Current);
	}
	return Hoarder;
}
void DoAction(double& Hoarder, Str_ExecUnit& ExecUnit001)
{
	//В соответствии с ExecUnit001.Action выполняем одно из действий
	switch (ExecUnit001.Action)
	{
	case AC_ADD:
		Hoarder += ExecUnit001.Value;
		break;
	case AC_SUBSTRACT:
		Hoarder -= ExecUnit001.Value;
		break;
	case AC_MULTIPLY:
		Hoarder *= ExecUnit001.Value;
		break;
	case AC_DIVIDE:
		Hoarder /= ExecUnit001.Value;
		break;
	case AC_POWER:
		Hoarder = MyPower(Hoarder, ExecUnit001.Value);
		break;
	}
}
double MyPower(double Number001, double Power001)
{
	//Накопитель
	double Hoarder = 1.0;
	//Если степень числа меньше нуля
	if (Power001 < 0)
	{
		//Делим число само на себя Power001 раз
		for (int i = 0; i < Power001; ++i)
		{
			Hoarder /= Number001;
		}
		return Hoarder;
	}
	//Если больше
	if (Power001 >= 1)
	{
		//Умножаем число само на себя Power001 раз
		for (int i = 0; i < Power001; ++i)
		{
			Hoarder *= Number001;
		}
		return Hoarder;
	}
	if (Power001 > 0 && Power001 < 1)
	{
		Hoarder = exp(Power001 * log(Number001));
	}
	//Передаём итоговое число
	return Hoarder;
}
bool Compare(char Symbol001, const char* AlphaToCompare)
{
	//Если символ совпадает с одним из списка, то передаём истина
	while (*AlphaToCompare)
	{
		if (Symbol001 == *AlphaToCompare)
		{
			return true;
		}
		AlphaToCompare++;
	}
	return false;
}