#include "DrWebTask.h"

char *TrimRight( char *s )
{
	//Если строка пустая
	if( !*s )
	{
		//То передаём строку с одним символом
		char *TrimmedString = MakeString( 1 );
		return TrimmedString;
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
		Pointer++;
	}
	
	//Смещаем назад указатель до первого не символа пробела
	do	
	{
		//Если указатель вышел за пределы строки слева, выходим из цикла
		if( Pointer < s )
		{
			break;
		}
		Pointer--;
	}while( *Pointer == ' ' );
	//Вычисляем итоговую длинну строки с учётом нулевого символа
	Count = Pointer - s + 2;
	//Если длинна строки меньше двух
	if( Count < 2 )
	{
		//То передаём строку с одним символом
		char *TrimmedString = MakeString( 1 );
		return TrimmedString;
	}

	//Создаём строку
	char *TrimmedString = MakeString( Count );
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
	//Если строка пустая
	if( !*s )
	{
		//То передаём строку с одним символом
		char *TrimmedString = MakeString( 1 );
		return TrimmedString;
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
		//Если адреса сравнялись, выходим из цикла
		if( Start == End )
		{
			break;
		}
		End--;
	}while( *End == ' ' );
	//Вычисляем итоговую длинну строки с учётом нулевого символа
	Count = ( End - Start ) + 2;
	//Если длинна строки меньше двух
	if( Count < 2 )
	{
		//То передаём строку с одним символом
		char *TrimmedString = MakeString( 1 );
		return TrimmedString;
	}

	//Создаём строку
	char *TrimmedString = MakeString( Count );
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
	//Если строка пустая
	if( !*s )
	{
		//То передаём строку с одним символом
		char *TrimmedString = MakeString( 1 );
		return TrimmedString;
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

	//Если длинна строки меньше двух
	if( Count < 2 )
	{
		//То передаём строку с одним символом
		char *TrimmedString = MakeString( 1 );
		return TrimmedString;
	}

	//Создаём строку
	char *TrimmedString = MakeString( Count );
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

char *MakeString( unsigned long long Length001 )
{
	//Создаём строку
	char *NewString;
	NewString = new char[ Length001 ];
	//Указываем последнему элементу символ конца строки
	NewString[ Length001 - 1 ] = '\0';
	//Передаём
	return NewString;
}
