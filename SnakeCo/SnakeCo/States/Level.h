#ifndef LEVEL_H
#define LEVEL_H

#include "Objects/Timer.h"

#include "GamesStates.h"

#include "Game/GameFunctions.h"

#include "Lib/Value.h"

//Класс стадия интро - начальной заставки
class Cls_Level : public Cls_GameState
{
private:
	//Номер текущего уровня
	int NumberLevel;
	//Сложность
	int Difficulty;
	//Основное поле
	Cls_Array2D< char > MainField;
	//Название уровня
	Str_Object Title;

	//Показать субменю
	bool ShowSubMenu;

	//Координаты СубМеню и поле СубМеню
	Str_Geminus< unsigned int > SubMenuKoords;
	Cls_Array2D< char > SubMenuField;

	//Номер кнопки и положения указателя на кнопку
	Cls_ValueCycled< int > NumberButton;
	//Кнопки выход и старт
	Str_Object *Buttons;
	Str_Object Marker;

	//Игровое поле
	Str_Geminus< unsigned int > GameFieldKoords;
	Cls_Array2D< char > GameField;
	//Препятствия
	std::list< Str_Object > Obstacles;

	//Массив с направлениями
	Cls_Array1DStrII< int > Directions;
	//Массив с кодами клавиш по направлениям
	Cls_Array1D< unsigned int > ArrayKeys;

	//Сама змея
	std::list< Str_Object > Snake;
	Str_Geminus< unsigned int > CurrentHearKoords;
	Str_Geminus< int > CurrentDirection;
	int OldNumber;

	//То, что собирать
	Str_Object FoodUp;
	//Счётчик появления уменьшающей еды
	Cls_ValueCycled< int > CounterFood;
	std::list< Str_Object > FoodDown;

	//Количество очков
	Str_Object Scores;
	unsigned int ContScores;

	//Состояние игры
	//0 игра продолжается
	//> 0 игра выиграна
	//< 0 игра проиграна
	int GameState;
	//Игра начата
	bool GameStarted;

	//Сообщение о победе или поражении
	Str_Object Greerings;

	//Таймер смещения
	Cls_ValueCycled< int > MoveCounter;
	
public:
	//Конструктор
	Cls_Level( int Difficulty001, int LevelIterator001, Cls_Timer &TimerTransfer );
	//Деструктор
	~Cls_Level();
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