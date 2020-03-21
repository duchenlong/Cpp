题目描述
//给出年分m和一年中的第n天，算出第n天是几月几号。
//输入描述:
//输入包括两个整数y(1<=y<=3000)，n(1<=n<=366)。
//输出描述:
//可能有多组测试数据，对于每组数据，
//按 yyyy-mm-dd的格式将输入中对应的日期打印出来。
//示例1
//输入
//复制
//2000 3
//2000 31
//2000 40
//2000 60
//2000 61
//2001 60
//输出
//复制
//2000-01-03
//2000-01-31
//2000-02-09
//2000-02-29
//2000-03-01
//2001-03-01

#include<iostream>
using namespace std;

class Date
{
public:
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
    
    void slove(int year,int day)
    {
        int month = 1;
        int maxMonthDay = GetMonthDay(year,month);
        while(day > maxMonthDay)
        {
            day -= maxMonthDay;
            month++;
            if(month == 13)
            {
                month = 1;
                year++;
            }
            maxMonthDay = GetMonthDay(year,month);
        }
        _year = year;
        _month = month;
        _day = day;
    }

    void Print()
    {
        cout<<_year<<'-';
        if(_month < 10)
            cout<<'0';
        cout<<_month<<'-';
        if(_day < 10)
            cout<<'0';
        cout<<_day<<endl;
    }
private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    int year,day;
    while(cin>>year>>day)
    {
        Date d;
        d.slove(year,day);
        d.Print();
    }
    
    return 0;
}
