#include <iostream>
#include <cmath>
using namespace std;

int dp[1005][1005] = {0};
const int div = 10000;

int slove(int n)
{
	int ans = n;
	//赋值前两列 
	for(int i = 1; i <= n; i++)
	{
		dp[i][1] = n;
		dp[i][2] = i;
	}
	int j = 3;
	int flag;
	do
	{
		flag = 0;
		for(int i = 1; i <= n; i++)
		{
			if(dp[i][j-1] == 0)
				continue;
			
			dp[i][j] = abs(dp[i][j-1] - dp[i][j-2]);
			if(dp[i][j])
				dp[i][j] -= 1;

			if(dp[i][j])
			{
				ans += dp[i][j];
				flag = 1;
				ans %= div;
			}	
		}
		j++;
	}while(flag);//如果当前列的元素均小于0，则退出 
	
	return ans;
}

int main()
{
	int n;
	cin>>n;
	
	int ans = slove(n);
	
	cout<<ans<<endl;
	return 0;
}
