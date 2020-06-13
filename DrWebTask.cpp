#include "stdafx.h"

#include "DrWebTask.h"

char *TrimRight( char *s )
{
	//���� ������ ������, ������� �� �������
	if( !*s )
	{
		return NULL;
	}

	//������� ���������� ���������
	unsigned long long Count = 0;
	//��������� �� ������ ������ ������
	char *Pointer = s;

	//��������� ����
	while( *Pointer )
	{
		//���� ������ ����� ������, ��������� ����
		if( *Pointer == '\n' )
		{
			break;
		}
		Count++;		
		Pointer++;
	}

	//������� ����� ��������� �� ������� �� ������� �������
	do	
	{
		Count--;
		Pointer--;
	}while( *Pointer == ' ' );
	//����������� ������� ��� �������� ������ �� ������� ������ � ���������� ���� ������� ����� ������
	Count++;

	//������ ������
	char *TrimmedString;
	TrimmedString = new char[ Count ];
	//��������� ���������� �������� ������ ����� ������
	TrimmedString[ Count ] = '\0';
	//������ ����� ��������� ��� ����� ������ ��� �����������
	char *NewPointer = TrimmedString;

	//���������� ������ ��������� �� ������ ������ ��� ������
	Pointer = s;

	//�������� �� ����� ����� ������
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
	//���� ������ ������, ������� �� �������
	if( !*s )
	{
		return NULL;
	}
	//������� ���������� ���������
	unsigned long long Count = 0;
	//��������� �� ������ ������ ������
	char *End = s, *Start = s;
	//��������� ����
	while( *End )
	{
		//���� ������ ����� ������, ��������� ����
		if( *End == '\n' )
		{
			break;
		}
		//���� ������ ������, ������� ���������
		if( *Start  == ' ' )
		{
			Start++;
		}				
		End++;
	}
	//������� ����� ��������� �� ������� �� ������� �������
	do	
	{
		Count--;
		End--;
	}while( *End == ' ' );
	//��������� ���������� ���������
	Count = End - Start;
	//����������� ������� ��� �������� ������ �� ������� ������ � ���������� ���� ������� ����� ������
	Count++;

	//������ ������
	char *TrimmedString;
	TrimmedString = new char[ Count ];
	//��������� ���������� �������� ������ ����� ������
	TrimmedString[ Count ] = '\0';
	//������ ����� ��������� ��� ����� ������ ��� �����������
	char *NewPointer = TrimmedString;

	//��������� �� ������ ������ �� ������
	char *Pointer = Start;

	//�������� �� ����� ����� ������
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
	//���� ������ ������, ������� �� �������
	if( !*s )
	{
		return NULL;
	}

	//������� ���������� ���������
	unsigned long long Count = 0;
	//��������� �� ������ ������ ������
	char *Pointer = s;

	//��������� ����
	while( *Pointer )
	{
		//���� ������ ����� ������, ��������� ����
		if( *Pointer == '\n' )
		{
			break;
		}
		//����������� ������ ���� ������ �� ������
		if( *Pointer != ' ' )
		{
			Count++;
		}
		Pointer++;
	}	

	//������ ������
	char *TrimmedString;
	TrimmedString = new char[ Count ];
	//��������� ���������� �������� ������ ����� ������
	TrimmedString[ Count ] = '\0';
	//������ ����� ��������� ��� ����� ������ ��� �����������
	char *NewPointer = TrimmedString;

	//���������� ������ ��������� �� ������ ������ ��� ������
	Pointer = s;

	//�������� �� ����� ����� ������
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