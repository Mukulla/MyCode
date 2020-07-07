#ifndef INTRO_H
#define INTRO_H

#include "GamesStates.h"

#include "Game/GameFunctions.h"

//����� ������ ����� - ��������� ��������
class Cls_Intro : public Cls_GameState
{
private:
	//���� ���� ��������
	bool IsEnd;

	Cls_Array2D< char > MainField;

	Str_Object Title;

	Str_Object GameName;

	Str_Object Greeting;

public:
	//�����������
	Cls_Intro( bool IsEnd001 );
	//����������
	~Cls_Intro();
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