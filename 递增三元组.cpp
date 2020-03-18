
/*在数列 a[1], a[2], ..., a[n] 中，如果对于下标 i, j, k 满足 0<i<j<k<n+1 且 a[i]<a[j]<a[k]，则称 a[i], a[j], a[k] 为一组递增三元组，a[j]为递增三元组的中心。
　　给定一个数列，请问数列中有多少个元素可能是递增三元组的中心。
输入格式
　　输入的第一行包含一个整数 n。
　　第二行包含 n 个整数 a[1], a[2], ..., a[n]，相邻的整数间用空格分隔，表示给定的数列。
输出格式
　　输出一行包含一个整数，表示答案。
样例输入
5
1 2 5 3 5
样例输出
2
*/

#include <iostream>
using namespace std;

int dp[1005][2] = {0};
int arr[1005] = {0};

void slove(int n)
{
	//找右边比他大的 
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(arr[i] < arr[j])
				dp[i][1]++;
		}
	}
	
	//找左边比他小的 
	for(int i = n-1; i >= 0; i--)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if(arr[i] > arr[j])
				dp[i][0]++;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	
	for(int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	
	slove(n);
	int ans = 0;
	for(int i = 0; i < n; i++)
		if(dp[i][0] && dp[i][1])
			ans++;
			
	cout<<ans<<endl;
	return 0;
}
