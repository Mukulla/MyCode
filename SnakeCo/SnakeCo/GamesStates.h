#ifndef GAME_STATES_H
#define GAME_STATES_H

#include "Lib/Arrays/Arrays.h"

//����������� ������
enum En_States
{
	STATE_NULL,
	STATE_INTRO,
	STATE_MENU,
	STATE_LEVEL,
	STATE_OUTRO,
	STATE_EXIT
};

//����������� ����� ��� ������� ������
class Cls_GameState
{
public:
	//����� ����������
	virtual ~Cls_GameState(){};
	//�������� 
	virtual void Loading( Str_Geminus< unsigned int > &FieldSizes ) = 0;
	//��������� ������� ������ ����������
	virtual void KeyBoardEvents( int SomeButton ) = 0;	
	//��� ������ ��� ����, �������������� � ���� �������
	virtual void Logic() = 0;	
	//����������� �����, ��� ���� � ������
	virtual void Render() = 0;	
};

void ChangeState( int NextState001, int Diffculty001, int NumberLevel, bool IsGameFinished );

#endif