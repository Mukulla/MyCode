#ifndef INTRO_H
#define INTRO_H

#include "GamesStates.h"

#include "Game/GameFunctions.h"

//Класс стадия интро - начальной заставки
class Cls_Intro : public Cls_GameState
{
private:
	//Игра была пройдена
	bool IsEnd;

	Cls_Array2D< char > MainField;

	Str_Object Title;

	Str_Object GameName;

	Str_Object Greeting;

public:
	//Конструктор
	Cls_Intro( bool IsEnd001 );
	//Деструктор
	~Cls_Intro();
	//Загрузка изображений
	void Loading( Str_Geminus< unsigned int > &FieldSizes );
	//Обработка нажатий клавишь клавиватуры
	void KeyBoardEvents( int SomeButton );
	//Обработка логики
	void Logic();
	//Отображение Меню и других объектов
	void Render();
};

#endif