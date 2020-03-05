#include <iostream>
using namespace std;

int arr[8][8] = {0};//存放原始数据

int fun(int src[8][8],int n)
{
	if(n == 1)
		return src[1][1];
		
	if(n == 2)
		return src[1][1] * src[2][2] - src[1][2] * src[2][1];
	
	int ans = 0; 
	int tmp[8][8] = {0};
	//选取第一行第i列的元素为乘数 
	for(int i = 1; i <= n; i++)
	{
		for(int row = 1; row < n; row++)
		{
			//把除了第1行第i列的元素，其他元素压缩到tmp数组的左上角部分 
			for(int col = 1; col < i; col++)
				tmp[row][col] = src[row+1][col];
			
			for(int col = i; col < n; col++)
				tmp[row][col] = src[row+1][col+1];	
		}
		//乘 1 还是 -1  因为拉普拉斯展开后，选择做乘数的是第一行的元素
		// 所以说就用 (1+i)  表示第一行第i列 
		ans += src[1][i] * fun(tmp,n-1) * (i%2==0?-1:1);
	} 
	return ans;
}

int main()
{
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin>>arr[i][j];
	
	cout<<fun(arr,n);
	
	return 0;
} 
