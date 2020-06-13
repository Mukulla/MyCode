#include "DrWebTask.h"

char *TrimRight( char *s )
{
	//Если строка пустая, выходим из функции
	if( !*s )
	{
		return NULL;
	}

	//Счётчик количества элементов
	unsigned long long Count = 0;
	//Указатель на первый символ строки
	char *Pointer = s;

	//Запускаем цикл
	while( *Pointer )
	{
		//Если символ конец строки, прерываем цикл
		if( *Pointer == '\n' )
		{
			break;
		}
		Count++;		
		Pointer++;
	}

	//Смещаем назад указатель до первого не символа пробела
	do	
	{
		Count--;
		Pointer--;
	}while( *Pointer == ' ' );
	//Увеличиваем счётчик для создания строки на единицу больше и добавления туда символа конца строки
	Count++;

	//Создаём строку
	char *TrimmedString;
	TrimmedString = new char[ Count ];
	//Указываем последнему элементу символ конца строки
	TrimmedString[ Count ] = '\0';
	//Создаём новый указатель для новой строки для копирования
	char *NewPointer = TrimmedString;

	//Возвращаем старый указатель на начало строки для записи
	Pointer = s;

	//Копируем до конца новой строки
	while( *NewPointer )
	{		
		*NewPointer = *Pointer;
		NewPointer++;
		Pointer++;
	}
	return TrimmedString;
}

char *TrimLeftRight( char *s )
{
	//Если строка пустая, выходим из функции
	if( !*s )
	{
		return NULL;
	}
	//Счётчик количества элементов
	unsigned long long Count = 0;
	//Указатель на первый символ строки
	char *End = s, *Start = s;
	//Запускаем цикл
	while( *End )
	{
		//Если символ конец строки, прерываем цикл
		if( *End == '\n' )
		{
			break;
		}
		//Если символ пробел, смещаем указатель
		if( *Start  == ' ' )
		{
			Start++;
		}				
		End++;
	}
	//Смещаем назад указатель до первого не символа пробела
	do	
	{
		Count--;
		End--;
	}while( *End == ' ' );
	//Вычисляем количество элементов
	Count = End - Start;
	//Увеличиваем счётчик для создания строки на единицу больше и добавления туда символа конца строки
	Count++;

	//Создаём строку
	char *TrimmedString;
	TrimmedString = new char[ Count ];
	//Указываем последнему элементу символ конца строки
	TrimmedString[ Count ] = '\0';
	//Создаём новый указатель для новой строки для копирования
	char *NewPointer = TrimmedString;

	//Указатель на первый символ не пробел
	char *Pointer = Start;

	//Копируем до конца новой строки
	while( *NewPointer )
	{		
		*NewPointer = *Pointer;
		NewPointer++;
		Pointer++;
	}
	return TrimmedString;
}

char *TrimSpace( char *s )
{
	//Если строка пустая, выходим из функции
	if( !*s )
	{
		return NULL;
	}

	//Счётчик количества элементов
	unsigned long long Count = 0;
	//Указатель на первый символ строки
	char *Pointer = s;

	//Запускаем цикл
	while( *Pointer )
	{
		//Если символ конец строки, прерываем цикл
		if( *Pointer == '\n' )
		{
			break;
		}
		//Увеличиваем только если символ не пробел
		if( *Pointer != ' ' )
		{
			Count++;
		}
		Pointer++;
	}	

	//Создаём строку
	char *TrimmedString;
	TrimmedString = new char[ Count ];
	//Указываем последнему элементу символ конца строки
	TrimmedString[ Count ] = '\0';
	//Создаём новый указатель для новой строки для копирования
	char *NewPointer = TrimmedString;

	//Возвращаем старый указатель на начало строки для записи
	Pointer = s;

	//Копируем до конца новой строки
	while( *NewPointer )
	{		
		if( *Pointer != ' ' )
		{
			*NewPointer = *Pointer;
			NewPointer++;
		}		
		Pointer++;
	}
	return TrimmedString;
}
