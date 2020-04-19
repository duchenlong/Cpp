#include <iostream>
#include <cmath>
using namespace std;

struct node
{
	int x;
	int y;
	int r;
}node[50];

int ans = 0;
int n;
int visit[50] = {0};
int pos[50] = {0};
int num = 0;//当前选择的圆的数量 

int Judge(int l,int r)
{
	int x = abs(node[l].x - node[r].x);
	int y = abs(node[l].y - node[r].y);
	int lr = abs(node[l].r + node[r].r);
	int len = sqrt(x*x + y*y);
	if(len < lr)
		return 1;
	return 0;
}

void slove()
{
	int area = 0;
	for(int i = 0; i < num; i++)
	{
		area += node[pos[i]].r * node[pos[i]].r;
	}
	
	ans = max(area,ans);
}

void dfs(int index)
{
	if(index == n)
	{
		slove();
		return;
	}
	
	for(int i = index; i < n; i++)
	{
		if(!visit[i])
		{
			int flag = 1;
			for(int j = 0; j < num; j++)
			{
				if(Judge(pos[j],i))//为真表示冲突
				{
					flag = 0;
					break;
				} 
			}
			
			if(flag)
			{
				visit[i] = 1;
				pos[num++] = i;
				dfs(i+1);
				num--;
				visit[i] = 0;
			}
		}
	}
}

int main()
{
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>node[i].x>>node[i].y>>node[i].r;
	}
	
	dfs(0);
	
	cout<<ans<<endl;
	return 0;
} 
