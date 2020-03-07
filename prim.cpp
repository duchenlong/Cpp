#include <iostream>
#include <queue>
#include <vector> 
using namespace std;

#define MAX 100000
#define MAX_VAL 0x00ffffff

//储存无向图的每个点可以到达的点 
struct node
{
	int to;//顶点的一个终点 
	int val;//边的权值 
	int next;//同一顶点的下一个终点 
}dir[MAX];

vector<int> path;//依次生成最小树的节点的顺序 
int head[MAX] = {0};//头结点的 

//链式存储无向图 
void add(int from,int to,int val,int len)
{
	dir[len].to = to;
	dir[len].val = val;
	dir[len].next = head[from];
	head[from] = len;
} 

//选择以1号点为树的跟节点 
void Prim(int n,int m)
{
	int visit[MAX] = {0};//判断找到树节点
	
	path.push_back(1); 
	visit[1] = 1;
	
	//依次找到其他的最小节点 
	for(int i = 1; i < m; i++)
	{
		 int min_val = MAX_VAL;
		 int min_to = 0;//本次循环可以找到的最小边 
		 //从所有已经选择的点开始遍历 
		 for(int j = 0; j < path.size(); j++)
		 {
		 	int from = path[j];
		 	//查找该点可以到达的点，找到一条最小的边 
		 	for(int k = head[from]; k != 0; k = dir[k].next)
		 	{
		 		int to = dir[k].to;
		 		//如果该点没有被访问，并且边的权值小于当前找到的，进行更新 
		 		if(!visit[to] && min_val > dir[k].val)
		 		{
		 			min_val = dir[k].val;
		 			min_to = to; 
				}
			}
		 }
		 
		 if(min_val == MAX_VAL)
		 {
		 	cout<<"无法生成最小树"<<endl;
			return ; 
		 } 
		 
		 visit[min_to] = 1; 
		 path.push_back(min_to);
	}
} 

int main()
{
	int m;//点的范围
	cin>>m;
	 
	int n;//边的数目
	cin>>n;
	
	int len = 1;
	for(int i = 1; i <= n; i++)
	{
		int u,v,val;
		cin>>u>>v>>val;
		add(u,v,val,len);//u -> v 
		len++;
		add(v,u,val,len);//v -> u
		len++;
	}
	
	Prim(n,m);
//	cout<<endl;
//	for(int i = 1; i <= n; i++)
//	{
//		for(int j = head[i]; j != 0; j = dir[j].next)
//			cout<<dir[j].to<<' '<<dir[j].val<<' '<<i<<endl;
//	}
	
	//依次打印生成树节点的顺序 
	for(int i = 0; i < path.size(); i++)
		cout<<path[i]<<endl;
	
	return 0;
}
 
