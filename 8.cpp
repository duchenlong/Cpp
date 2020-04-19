#include <iostream>
using namespace std;

int m,n;
int arr[1005] = {0};
int ans = 0;

void slove()
{
	for(int i = 1; i <= m; i++)
	{
		cout<<arr[i]<<' '; 
	}
	cout<<endl;
}

void dfs(int index)
{
	if(index == m+1)
	{
		slove();
		ans = (ans + 1) % 10000;
		return;
	}
	
	if(index&1)//奇数
	{
		//i比前一项大 
		for(int i = arr[index-1]+1; i <= n; i++)
		{
			arr[index] = i;
			dfs(index+1);
		}
	}
	else
	{
		// i 比前一项小
		for(int i = arr[index-1]-1; i >= 1; i--)
		{
			arr[index] = i;
			dfs(index+1);
		}
	}

}

int main()
{
	//while(1)
	//{
	cin>>m>>n;
	//m = 3, n =4;
	if(m == 1)
	{
		cout<<n<<endl;
	}
	else if(n == 2)
	{
		cout<<1<<endl;
	}
	else if(n == 1)
	{
		cout<<0<<endl;
	}
	for(int i = 2; i <= n; i++)
	{
		arr[1] = i;
		dfs(2);
	}
	cout<<ans<<endl;
	ans = 0;
	//}
	
	return 0;
}
