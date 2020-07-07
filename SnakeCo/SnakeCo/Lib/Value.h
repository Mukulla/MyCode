#ifndef VALUES_H
#define VALUES_H

//Класс зацикленного значения, 
//которое при выходы за пнижний предел получает максимальное значение и наоборот
template < typename Type001 >
class Cls_ValueCycled
{
private:
	//Само значение
	Type001 Value;
	//Нижний предел
	Type001 ValueMin;
	//Верхний предел
	Type001 ValueMax;
public:
	//Конструктор
	//Устанавливаем верхний и нижний пределы
	Cls_ValueCycled();
	//Деструктор
	~Cls_ValueCycled();
	//Установить значение
	void SetValue( Type001 Value001 );
	//Указать верхний и нижний пределы
	void SetMinMax( Type001 Min001, Type001 Max001 );
	//Добавить к значению
	void AddValue( Type001 Adder001 );
	//Получить значение
	Type001 GetValue();
	//Получить значение нижнего предела
	Type001 GetMin();
	//Получить значение верхнего предела
	Type001 GetMax();
};

#endif