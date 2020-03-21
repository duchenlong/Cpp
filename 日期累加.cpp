//题目描述
//设计一个程序能计算一个日期加上若干天后是什么日期。
//输入描述:
//输入第一行表示样例个数m，接下来m行每行四个整数分别表示年月日和累加的天数。
//输出描述:
//输出m行，每行按yyyy-mm-dd的个数输出。
//示例1
//输入
//复制
//1
//2008 2 3 100
//输出
//复制
//2008-05-13

#include<iostream>
using namespace std;

class Date
{
public:
    Date(int year,int month,int day)
    {
        _year = year;
        _month = month;
        _day = day;
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
    
    Date& operator+=(int day)
    {
        int maxMonthDay = GetMonthDay(_year,_month);
        _day += day;
        while(_day > maxMonthDay)
        {
            _day -= maxMonthDay;
            _month++;
            if(_month == 13)
            {
                _month = 1;
                _year++;
            }
            maxMonthDay = GetMonthDay(_year,_month);
        }
        return *this;
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
    int m;
    cin>>m;
    int year,month,day,num;
    while(m--)
    {
        cin>>year>>month>>day>>num;
        Date d(year,month,day);
        d += num;
        d.Print();
    }
    
    return 0;
}
