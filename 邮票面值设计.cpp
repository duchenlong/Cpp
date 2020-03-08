#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000000;

int n,k;//n 指最多可以粘贴的邮票数  k 指邮票的种类数 
int p[100] = {0};//每一次判断使用的合适面值数组 
int tag[100] = {0};//存储合适的面值 
int ans = 0; 

//kind 当前所使用邮票的种类数  val  
void dfs(int kind,int val)
{
	if(kind == k)
		return ;
	p[kind] = val;
	int dp[10000] = {0};//dp[i]  表示i种邮票最少需要贴多少张 
	memset(dp,MAX,sizeof(dp));
	dp[0] = 0;
	int sum = 1;
	
	//i 使用的邮票的面值 
	for(int i = 1; ; i++)
	{
		//j 表示邮票的面值 
		for(int j = 0; j <= kind && i >= p[j]; j++)
			dp[i] = min(dp[i],dp[i - p[j]] + 1);
		
		if(dp[i] > n)
			break;
		
		sum = max(sum,i);
		//cout<<i<<endl; 
	}
	
	//如果本次求得的组成数字大，则把邮票的面值拷贝到tag[]数组 
	if(sum > ans)
	{
		for(int i = 0; i <= kind; i++)
			tag[i] = p[i];
		
		ans = sum;
	}
	
	for(int i = val+1; i <= sum + 1; i++)
		dfs(kind+1,i); 
}

int main()
{
	cin>>n>>k;
	
	dfs(0,1);
	
	for(int i = 0; i < k; i++)
		cout<<tag[i]<<' ';
	cout<<endl;
	
	cout<<"MAX="<<ans<<endl;
	return 0;
}
