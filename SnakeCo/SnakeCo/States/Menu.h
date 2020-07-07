#ifndef MENU_H
#define MENU_H

#include "GamesStates.h"

#include "Game/GameFunctions.h"

#include "Lib/Value.h"

//Класс стадия интро - начальной заставки
class Cls_Menu : public Cls_GameState
{
private:
	Cls_Array2D< char > MainField;

	Str_Object Title;

	Str_Object GameName;

	//Номер кнопки и положения указателя на кнопку
	Cls_ValueCycled< int > NumberButton;
	//Кнопки выход и старт
	Str_Object *Buttons;
	Str_Object Marker;

	//Кнопки выбора сложности
	bool ShowSubButtons;
	Cls_ValueCycled< int > NumberSubButton;
	Str_Object *SubButtons;

public:
	//Конструктор
	Cls_Menu();
	//Деструктор
	~Cls_Menu();
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