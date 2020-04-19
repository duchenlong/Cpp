#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node
{
	int x;
	int y;
	int h;
}node[1005];

int pos[1005] = {0};//已选择村庄位置
int n;
double ans = 0.0;

int cmp(const void* c, const void* d)
{
	const struct node* a = (struct node*)c;
	const struct node* b = (struct node*)d;
	if(a->x != b->x)
		return a->x - b->x;
	if(a->y != b->y)
		return a->y - b->y;
	return a->h - b->h;
}

double cal(int l,int r)
{
	int x = abs(node[l].x - node[r].x);
	int y = abs(node[l].y - node[r].y);
	int h = abs(node[l].h - node[r].h);
	
	return sqrt(x*x + y*y) + h*h;
}

void Fun(int ret)
{
	int minc = 0;
	double minpath = cal(0,ret);
	for(int i = 1; i < ret; i++)
	{
		double len = cal(i,ret);
		if(len < minpath)
		{
			minpath = len;
			minc = i;
		}
	}
	ans += minpath;
} 

void slove()
{
	for(int i = 1; i < n; i++)
	{
		//计算和他距离最近的一个村庄
		Fun(i);	
	}
}

int main()
{
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>node[i].x>>node[i].y>>node[i].h;
	}
	
	qsort(node+1,n-1,sizeof(struct node),cmp);
	slove();
	
	printf("%.2lf\n",ans);
	
	//for(int i = 0; i < n; i++)
//	{
//		cout<<node[i].x<<node[i].y<<node[i].h<<endl;
//	}
	return 0;
} 
