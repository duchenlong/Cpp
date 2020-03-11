#include <iostream>
using namespace std;

int main()
{
	//逆推法
	int dis = 500;//距离起点的路程
	int capacity = 500;//加油站的容量 
	int num = 1;//加油站的编号 
	
	do
	{
		cout<<"第 "<<num<<" 个加油站，距离起点 "<<1000 - dis<<" km";
		cout<<",加油站容量 "<<capacity<<" L"<<endl;
		num++;
		capacity = num * 500; //每一个加油站的油均是总容量的整数倍
		dis += 500 / (2 * num - 1);
		
	}while(dis < 1000); 
	
	//初始位置的存储油量应该减去向下一个加油站运送是，最后一次单趟送油多消耗的油 
	cout<<"初始位置的油量 "<<500 * (num - 1) + (1000 - dis) * (2 * num -1)<<" L"<<endl; 
	
	return 0;
} 
