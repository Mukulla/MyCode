#ifndef MENU_H
#define MENU_H

#include "GamesStates.h"

#include "Game/GameFunctions.h"

#include "Lib/Value.h"

//����� ������ ����� - ��������� ��������
class Cls_Menu : public Cls_GameState
{
private:
	Cls_Array2D< char > MainField;

	Str_Object Title;

	Str_Object GameName;

	//����� ������ � ��������� ��������� �� ������
	Cls_ValueCycled< int > NumberButton;
	//������ ����� � �����
	Str_Object *Buttons;
	Str_Object Marker;

	//������ ������ ���������
	bool ShowSubButtons;
	Cls_ValueCycled< int > NumberSubButton;
	Str_Object *SubButtons;

public:
	//�����������
	Cls_Menu();
	//����������
	~Cls_Menu();
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