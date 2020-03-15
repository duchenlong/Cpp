#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int n,m;
char show[1005][1005] = {'0'};
char src[1005][1005] = {'0'};
int k;
int dis[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void group(int row,int col)
{
	for(int i = 0; i < 4; i++)
	{
		int x = row + dis[i][0];
		int y = col + dis[i][1];
		
		if(x < 0 || x >= n || y < 0 || y >= m)
			continue;
			
		show[x][y] = 'g'; 
	}
}

void slove()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(src[i][j] == 'g')
				group(i,j);
				
	for(int i = 0; i < n; i++)
		strcpy(src[i],show[i]);
}

int main()
{
	cin>>n>>m;
	for(int i  = 0; i < n; i++)
	{
		cin>>src[i];
		strcpy(show[i],src[i]);
	}
		
	cin>>k;
	
	while(k--)
	{
		slove();
	}
	
	for(int i = 0; i < n; i++)
		cout<<show[i]<<endl;
	return 0;
}
