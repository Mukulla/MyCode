#ifndef GAME_STATES_H
#define GAME_STATES_H

#include "Lib/Arrays/Arrays.h"

//Пречисление стадий
enum En_States
{
	STATE_NULL,
	STATE_INTRO,
	STATE_MENU,
	STATE_LEVEL,
	STATE_OUTRO,
	STATE_EXIT
};

//Вирутальный класс для классов стадий
class Cls_GameState
{
public:
	//Общий деструктор
	virtual ~Cls_GameState(){};
	//Загрузка 
	virtual void Loading( Str_Geminus< unsigned int > &FieldSizes ) = 0;
	//Обработка нажатий клавиш клавиатуры
	virtual void KeyBoardEvents( int SomeButton ) = 0;	
	//Для физики или иных, обрабатываемых в фоне явлений
	virtual void Logic() = 0;	
	//Отображение всего, что есть в стадии
	virtual void Render() = 0;	
};

void ChangeState( int NextState001, int Diffculty001, int NumberLevel, bool IsGameFinished );

#endif