#ifndef VALUES_H
#define VALUES_H

//����� ������������ ��������, 
//������� ��� ������ �� ������� ������ �������� ������������ �������� � ��������
template < typename Type001 >
class Cls_ValueCycled
{
private:
	//���� ��������
	Type001 Value;
	//������ ������
	Type001 ValueMin;
	//������� ������
	Type001 ValueMax;
public:
	//�����������
	//������������� ������� � ������ �������
	Cls_ValueCycled();
	//����������
	~Cls_ValueCycled();
	//���������� ��������
	void SetValue( Type001 Value001 );
	//������� ������� � ������ �������
	void SetMinMax( Type001 Min001, Type001 Max001 );
	//�������� � ��������
	void AddValue( Type001 Adder001 );
	//�������� ��������
	Type001 GetValue();
	//�������� �������� ������� �������
	Type001 GetMin();
	//�������� �������� �������� �������
	Type001 GetMax();
};

#endif