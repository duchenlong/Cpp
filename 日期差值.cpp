//题目描述
//有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
//输入描述:
//有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
//输出描述:
//每组数据输出一行，即日期差值
//示例1
//输入
//复制
//20110412
//20110422
//输出
//复制
//11

#include<iostream>
using namespace std;

class Date
{
public:
    Date(char* str)
    {
        _year = StrToNum(str,0,4);
        _month = StrToNum(str,4,6);
        _day = StrToNum(str,6,8);
    }
    //字符串转化为数字
    int StrToNum(char* str,int left,int right)
    {
        int num = 0;
        while(left < right)
            num = num * 10 + str[left++] - '0';
        return num;
    }
    //获取当前月份的最大天数
    int GetMonthDay(int year,int month)
    {
        static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = days[month];//拿到当前月除了2.29的最大日期

		//如果出现2月29日
		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			day += 1;
		}

		return day;
    }
    //天数+1操作
    Date& operator+=(int day)
	{
		_day += day;
		int maxDay = GetMonthDay(_year, _month);//获取当前月的最大天数
		while (maxDay < _day)
		{
			_day -= maxDay;//减掉当前月的天数
			_month++;//月+1
			//如果月超了，年+1，月变成1月
			if (_month == 13)
			{
				_month = 1;
				_year++;
			}
			maxDay = GetMonthDay(_year, _month);
		}
		return *this;
	}
    
    // >运算符重载 //判断日期大小
	bool operator>(const Date& d)
	{
		////根据年直接比
		//if (_year > d._year)
		//	return true;
		////年相等比月
		//if (_year == d._year && _month > d._month)
		//	return true;
		////年月相等比天
		//if (_year == d._year && _month == d._month && _day > d._day)
		//	return true;
		if ((_year > d._year) || \
			(_year == d._year && _month > d._month) || \
			(_year == d._year && _month == d._month && _day > d._day))
			return true;
		return false;

	}
    // ==运算符重载
	bool operator!=(const Date& d)
	{
		return _day != d._day ||\
			_month != d._month ||\
			_year != d._year;
	}
    //日期相减
    int operator-(const Date& d)
	{
		Date small = *this;
		Date big = d;
		if (*this > d)
		{
			big = *this;
			small = d;
		}
		//累加法
		int numDay = 0;
		while (small!=big)
		{
			small+=1;
			numDay++;
		}
		return numDay + 1;
	}
private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    char str1[10] = {'\0'};
    char str2[10] = {'\0'};
    cin>>str1>>str2;
    Date d1(str1);
    Date d2(str2);
    
    cout<<d1-d2<<endl;
    return 0;
}
