#include<iostream>
#include <bits/stdc++.h>
using namespace  std;

//到x星球旅行的游客都被发给一个整数，作为游客编号。
//x星的国王有个怪癖，他只喜欢数字3,5和7。
//国王规定，游客的编号如果只含有因子：3,5,7,就可以获得一份奖品。
//
//我们来看前10个幸运数字是：
//3 5 7 9 15 21 25 27 35 45
//因而第11个幸运数字是：49
//
//小明领到了一个幸运数字 59084709587505，他去领奖的时候，人家要求他准确地说出这是第几个幸运数字，否则领不到奖品。
//
//请你帮小明计算一下，59084709587505是第几个幸运数字。

const long long MAX =  59084709587505;

int main()
{
	set<long long> arr;//set容器，安装从小到大的顺序排列
	 
	int a[3] = {3,5,7};
	long long num = 1;
	while(1)
	{
		for(int i = 0; i < 3; i++)
		{
			long long count = num * a[i];
			
			//如果该数比最大值小，则记录在案 
			if(count <= MAX)
				arr.insert(count);
		}
		
		num = *arr.upper_bound(num);//找到第一个比num大的数 的位置
	
		if(num >= MAX)
			break;
	}
	
	cout<<arr.size()<<endl;
	
	return 0;
}
