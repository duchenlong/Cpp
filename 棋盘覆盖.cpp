#include <iostream>
#include <cstdio> 
#include <cmath>
using namespace std;

int board[100][100] = {0};//棋盘 
int count = 1;//依次处理方格的顺序 
int dis[4][2] = {{0,0},{0,1},{1,0},{1,1}};//本身，右，下，右下角三个位置 

void show(int size)
{
	for(int i = 1; i <= size; i++)
	{
		for(int j = 1; j <= size; j++)
			printf("%3d ",board[i][j]);
		cout<<endl;
	}
}

void Cover(int tx,int ty,int x,int y,int size)
{
	//处理只有一个格子的情况 
	if(size < 2)
		return ;
	
	size /= 2; 
	int num = count++;
	
	for(int i = 0; i < 4; i++)
	{
		//分成四个方块，row,col分别为四个方块的左上角位置 
		int row = dis[i][0] * size + tx;
		int col = dis[i][1] * size + ty;
		//cout<<size<<' '<<row<<' '<<col<<endl;
		
		//如果缺少的格子不在当前范围，就把新加的残缺格补上 
		if(!(x >= row && x < (row + size) &&\
			 y >= col && y < (col + size)) )
			 {
			 	//r,c 为新加的残缺格位置 
			 	int r = dis[3 - i][0] * (size-1) + row;
			 	int c = dis[3 - i][1] * (size-1) + col;
				board[r][c] = num; 
				Cover(row,col,r,c,size); 
			 	//cout<<"---"<<r<<' '<<c<<endl;
			 }
		else
			Cover(row,col,x,y,size);
	} 
}

int main()
{
	int k;
	cin>>k;//2^k  2^k的棋盘
	
	int size = pow(2,k);//棋盘的行数 
	//cout<<size; 
	
	int x,y;//残缺格的位置
	cin>>x>>y;
	board[x][y] = -1;
	
	Cover(1,1,x,y,size);
	
	show(size);
	return 0;
}
