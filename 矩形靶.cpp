#include <iostream>
#include <cstring>
using namespace std;

char target[700][700] = {'\0'};
char show[700][700] = {'\0'};
int n,m,l,r;//靶子的大小   以及子弹的大小  

void ruin(int row,int col)
{
	//先击倒中心位置 
	show[row][col] = '1';
	//cout<<row<<"  "<<col<<endl;
	for(int i = 0; i < (2*l+1); i++)
	{
		int x = row - l + i;//cout<<"x = "<<x<<endl;
		//判断x是否超范围
		if(x < 0 || x >= n)
			continue;
		
		for(int j = 0; j < (2*r+1); j++)
		{
			int y = col - r	+ j;
			//判断y是否超范围
			if( y < 0 || y >= m)
				continue;
			
			show[x][y] = '1';
			//cout<<x<<' '<<y<<endl;
		}
		
	}
		
}

void slove()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(target[i][j] == '1')
				ruin(i,j);
			else if(!show[i][j])
				show[i][j] = '0';
		}
	}
}

int main()
{
	
	cin>>n>>m>>l>>r;
	
	for(int i = 0; i < n; i++)
		cin>>target[i];
	 
	slove(); 
	
	//打印靶子 
	for(int i = 0; i < n; i++)
		cout<<show[i]<<endl;

		
	
	return 0;
}
