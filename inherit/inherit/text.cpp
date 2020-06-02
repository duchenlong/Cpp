#define _CRT_SECURE_NO_WARNINGS 1

#include "inherit.hpp"

/*
void text1()
{
	Student S;
	People P = S;

	People* Pp = &P;
	Student* Sp3 = (Student*)Pp;//可以转换，但是访问子类对象的时候，会存在越界访问
	Sp3->ShowInfo();
	Sp3->_Sid = 123;
	cout << "Sp3->_Sid 可以访问" << endl;
}

void text2()
{
	Student S;

	People* Pp = &S;
	Student* Sp2 = (Student*)Pp;
	Sp2->ShowInfo();
	Sp2->_Sid = 123;
	cout << "Sp2->_Sid 可以访问" << endl;
}


void text3()
{
	Student S;

	S.People::ShowInfo();
	//S.ShowInfo();
}

void text4()
{
	Student S;

	Student S1(S);

	S1 = S;
}
*/
//void text5()
//{
//	A Aobj(55);
//	C Cobj;
//}

//void text6()
//{
//	B Bobj;
//	C Cobj;
//
//	Bobj._sum++;
//	Cobj._sum++;
//}

void text7()
{
	Grade Gobj;
	Gobj._name = "Windy_X";
	Gobj._age = 20;
}

void text8()
{
	D d;
	/*d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;*/
	cout << "d .size() = " << sizeof(d) << endl;
}



int main()
{
	//text2();
	//text3();
	//text4();
	//text5();
	text8();
	return 0;
}
