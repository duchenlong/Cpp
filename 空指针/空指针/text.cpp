

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void Fun(int var)
{
	cout << "Fun(int var) " << var << endl;
}

void Fun(int* var)
{
	cout << "Fun(int* var) " << var << endl;
}

void Type()
{
#ifdef __cplusplus
	printf("This is c++ program %d\n", __cplusplus);
#else
	printf("This is c program");
#endif
}

class Test
{
public:
	Test(int a)
		:val(a)
	{}
	bool isSame(Test obj)
	{
		return val == obj.val;
	}
private:
	int val;
};

const class My_nullptr_t
{
public:
	template<class T>
	inline operator T*()const
	{
		return 0;
	}

	template<class T, class C>
	inline operator T C::*()const
	{
		return 0;
	}
private:
	void operator&()const;
}My_nullptr = {};


int main()
{
	Test a(10);
	cout << a.isSame(10) <<endl;



	Test* pa = &a;
	pa = My_nullptr;

	Test* pb = pa;





	int* p = NULL;
	cout << p << endl;
	int* p2 = NULL;
	cout << p2 << endl;




	Fun(p);
	Fun(NULL);

	char str[4] = { 'a', 'b', 'c',0};

	cout << str << endl;

	cout << "程序使用的语言 ： " ;
	Type();
	
	return 0;
}