#include <iostream>
using namespace std;

int main()
{
	int arr[100][100] = {0};
	int b[2] = {0,1};//b[1]表示纵坐标  b[0]表示横坐标
	
	int n;//回形矩阵的行和列
	cin>>n; 
	
	int num = 1;//需要填写的数 
	int k = n;//2 * k - 1 表示半圈需要填充数字的长度 
	int t = 1;//用作数组转动 
	while(num <= n*n)
	{
		for(int i = 1; i <= 2 * k - 1; i++)
		{
			//当 i > n 时  横向填充数据  
			//当 i <= n 时 竖着填充数据
			b[i / (k + 1)] += t;
			arr[b[0]][b[1]] = num;
			num++;
		}
		
		t *= -1;//前半圈 和 后半圈坐标的变化 
		k--;
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			cout<<arr[i][j]<<' ';
		cout<<endl;
	}
	return 0;
} 
