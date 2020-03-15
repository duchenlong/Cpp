#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int num;//上场顺序
	int val;//好看值 
}arr[100005];

bool node_cmp(struct node c,struct node d)
{
	if(c.val != d.val)
		return d.val < c.val;
	else
		return d.num < c.num;
}

bool node_cmp_s(struct node c,struct node d)
{
	return d.num > c.num;
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i = 0; i < n; i++)
	{
		cin>>arr[i].val;
		arr[i].num = i;
	}
	
	sort(arr,arr+n,node_cmp);
	
	sort(arr,arr+m,node_cmp_s);
	
	for(int i = 0; i < m; i++)
	{
		cout<<arr[i].val<<' ';
	} 
	return 0;
}
