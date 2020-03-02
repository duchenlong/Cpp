#include <iostream>
using namespace std;

#define MAX (105*10000) 

int dp[105][105] = {0};//dp[i][j] 用k快模板覆盖从i到j区间的最大面积
int height[105][105];//height[i][j] i开始，到j的最高木板的高度

int main()
{
	int n,m;
	cin>>n>>m;
	int board[105] = {0}; //木板的高度 
	for(int i = 1; i <= n; i++)
	{
		cin>>board[i];
	}
	
	//i开始，到j的最高木板的高度
	for(int i = 1; i <= n; i++)
	{
		height[i][i] = board[i];
		for(int j = i + 1; j <= n; j++)
		{
			height[i][j] = max(height[i][j-1],board[j]);
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		dp[i][1] = i * height[1][i];
		for(int j = 2; j <= i && j <= m; j++)
		{
			dp[i][j] = MAX;
			
			//k补丁矩形的宽 
			for(int k = 1; k <= (i-j+1); k++)
			{
				dp[i][j] = min(dp[i][j],dp[i-k][j-1] + k * height[i-k+1][i]);
				//cout<<dp[i][j]<<endl;
			}
		}
	}
	
	cout<<dp[n][m]<<endl;
	
	
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = 1; j <= n; j++)
//		{
//			cout<<height[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	return 0;
}
