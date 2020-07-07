#ifndef LEVEL_H
#define LEVEL_H

#include "Objects/Timer.h"

#include "GamesStates.h"

#include "Game/GameFunctions.h"

#include "Lib/Value.h"

//����� ������ ����� - ��������� ��������
class Cls_Level : public Cls_GameState
{
private:
	//����� �������� ������
	int NumberLevel;
	//���������
	int Difficulty;
	//�������� ����
	Cls_Array2D< char > MainField;
	//�������� ������
	Str_Object Title;

	//�������� �������
	bool ShowSubMenu;

	//���������� ������� � ���� �������
	Str_Geminus< unsigned int > SubMenuKoords;
	Cls_Array2D< char > SubMenuField;

	//����� ������ � ��������� ��������� �� ������
	Cls_ValueCycled< int > NumberButton;
	//������ ����� � �����
	Str_Object *Buttons;
	Str_Object Marker;

	//������� ����
	Str_Geminus< unsigned int > GameFieldKoords;
	Cls_Array2D< char > GameField;
	//�����������
	std::list< Str_Object > Obstacles;

	//������ � �������������
	Cls_Array1DStrII< int > Directions;
	//������ � ������ ������ �� ������������
	Cls_Array1D< unsigned int > ArrayKeys;

	//���� ����
	std::list< Str_Object > Snake;
	Str_Geminus< unsigned int > CurrentHearKoords;
	Str_Geminus< int > CurrentDirection;
	int OldNumber;

	//��, ��� ��������
	Str_Object FoodUp;
	//������� ��������� ����������� ���
	Cls_ValueCycled< int > CounterFood;
	std::list< Str_Object > FoodDown;

	//���������� �����
	Str_Object Scores;
	unsigned int ContScores;

	//��������� ����
	//0 ���� ������������
	//> 0 ���� ��������
	//< 0 ���� ���������
	int GameState;
	//���� ������
	bool GameStarted;

	//��������� � ������ ��� ���������
	Str_Object Greerings;

	//������ ��������
	Cls_ValueCycled< int > MoveCounter;
	
public:
	//�����������
	Cls_Level( int Difficulty001, int LevelIterator001, Cls_Timer &TimerTransfer );
	//����������
	~Cls_Level();
	//�������� �����������
	void Loading( Str_Geminus< unsigned int > &FieldSizes );
	//��������� ������� ������� �����������
	void KeyBoardEvents( int SomeButton );
	//��������� ������
	void Logic();
	//����������� ���� � ������ ��������
	void Render();
};

#endif