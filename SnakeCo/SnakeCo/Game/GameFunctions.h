#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include "Objects/Object.h"

#include "Lib/Arrays/Arrays.h"

//������� � ����������� ����
void PrepareField( Cls_Array2D< char > &SomeField );
//����������� ����� ������ � ��������� � ����� ����
void CopyObjectToField( Str_Object &Oject, Cls_Array2D< char > &SomeField );
//����������� ���� ���� � ������
void CopyFieldToField( Str_Geminus< unsigned int > &OffSet, Cls_Array2D< char > &From, Cls_Array2D< char > &To );

//�������� ������� � ����
void AddBordresToField( char Symbol, Cls_Array2D< char > &GameField );
//��������� ������� ���������� ����������
std::list< Str_Object > AddRandomElementsToList( char Symbol, int Count, Cls_Array2D< char > &GameField );
//����������� ������� �� ������ � ������� ����
void CopyListToField( std::list< Str_Object > List001, Cls_Array2D< char > &GameField );

void PlaceObjectToField( Str_Object &Oject, Cls_Array2D< char > &SomeField );
//�������� �� ����������� � ������� ��� ������ �������� �� ������
bool ChekLet( Str_Object &Oject, Str_Geminus< int > &OffSet, Cls_Array2D< char > &SomeField, char *ArrayToCompare );
bool ChekLet( Str_Object &Oject, Cls_Array2D< char > &SomeField, char *ArrayToCompare );
void MoveObject( Str_Object &Oject, Str_Geminus< int > &OffSet );
void MoveSnake( std::list< Str_Object > &Snake, Str_Geminus< int > &OffSet );

bool Compare( Str_Geminus< unsigned int > First, Str_Geminus< unsigned int > Second );


#endif
