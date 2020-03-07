#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define MAX 100010

//会议时间的结构体 
struct node
{
	int start;
	int end;
	int id;//会议序号 
}t[MAX];

int pos[MAX] = {0}; 

bool node_cmp(node a,node b)
{
	//按照结束位置从小到大排序 
	return a.end < b.end;
}

int slove(int n)
{
	int ans = 0;
	int j = 1;
	pos[ans++] = t[j].id;
	for(int i = 2; i <= n; i++)
	{
		//如果下一个会议开始时间比上一个会议结束时间大，符合情况 
		if(t[i].start > t[j].end)
		{
			j = i;
			pos[ans++] = t[i].id;
		}
	}
	
	return ans;
}

int main()
{
	int n;//会议次数
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>t[i].start>>t[i].end;
		t[i].id = i;
	} 
	
	//排序 
	sort(t+1,t+n+1,node_cmp);
	
//	for(int i = 1; i <= n; i++)
//		cout<<t[i].start<<" "<<t[i].end<<endl;

	int num = slove(n);
	cout<<num<<endl;
		
	for(int i = 0; i < num; i++)
		cout<<pos[i]<<" ";
	return 0;
} 

