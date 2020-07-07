#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

#include "Objects/Object.h"

#include "Lib/Arrays/Arrays.h"

//Создать и подготовить поле
void PrepareField( Cls_Array2D< char > &SomeField );
//Скопировать некий объект с символами в общее поле
void CopyObjectToField( Str_Object &Oject, Cls_Array2D< char > &SomeField );
//Скопировать одно поле в другое
void CopyFieldToField( Str_Geminus< unsigned int > &OffSet, Cls_Array2D< char > &From, Cls_Array2D< char > &To );

//Добавить границы к полю
void AddBordresToField( char Symbol, Cls_Array2D< char > &GameField );
//Заполнить спиксок случайными элементами
std::list< Str_Object > AddRandomElementsToList( char Symbol, int Count, Cls_Array2D< char > &GameField );
//Скопировать объекты из списка в игровое поле
void CopyListToField( std::list< Str_Object > List001, Cls_Array2D< char > &GameField );

void PlaceObjectToField( Str_Object &Oject, Cls_Array2D< char > &SomeField );
//Сравнить по направлению о наличии там одного элемента из списка
bool ChekLet( Str_Object &Oject, Str_Geminus< int > &OffSet, Cls_Array2D< char > &SomeField, char *ArrayToCompare );
bool ChekLet( Str_Object &Oject, Cls_Array2D< char > &SomeField, char *ArrayToCompare );
void MoveObject( Str_Object &Oject, Str_Geminus< int > &OffSet );
void MoveSnake( std::list< Str_Object > &Snake, Str_Geminus< int > &OffSet );

bool Compare( Str_Geminus< unsigned int > First, Str_Geminus< unsigned int > Second );


#endif
