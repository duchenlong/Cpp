//题目描述
//根据输入的日期，计算是这一年的第几天。。

//详细描述：

//输入某年某月某日，判断这一天是这一年的第几天？。

// 
//输入描述:
//输入三行，分别是年，月，日

//输出描述:
//成功:返回outDay输出计算后的第几天;
//                                           失败:返回-1

//示例1
//输入
//复制
//2012
//12
//31
//输出
//复制
//366

#include <iostream>
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
    
    int slove()
    {
        //判断当前日期是否合法
        if(GetMonthDay(_year,_month) < _day)
            return -1;
        int ans = _day;
        int i = 1;
        while(i < _month)
        {
            ans += GetMonthDay(_year,i);
            i++;
        }
        return ans;
    }
private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    int year,month,day;
    while(cin>>year>>month>>day)
    {
        Date d(year,month,day);
        cout<<d.slove()<<endl;
    }
    return 0;
}
