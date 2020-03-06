#include <iostream>
using namespace std;

int path[12][12] = {0};
int maxpath = 0;
int num = 0;
int dis[2][2] = {{-1,0},{0,1}};//上，右两个方向 

void dfs(int row,int col,int n,int p)
{
	if(row == 0 && col == n-1)
	{
		if(p > maxpath)
		{
			maxpath = p;
			num = 1;
		}
		else if(p == maxpath)
			num++;
			
		return ;
	}
	
	for(int i = 0; i < 2; i++)
	{
		int x = dis[i][0] + row;
		int y = dis[i][1] + col;
		
		//判断是否超出范围
		if(x < 0 || y >= n)
			continue;
		
		dfs(x,y,n,p+path[row][col]);
	}
} 

int main()
{
	int n;
	cin>>n;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin>>path[i][j];
			
	dfs(9,0,n,0);
	
	cout<<num<<' '<<maxpath + path[0][n-1]<<endl;
}
