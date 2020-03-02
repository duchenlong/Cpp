#include <iostream>
#include <vector>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

 
vector<int> ans;//需要的最少的巧克力数 
int eat[105] = {0};//需要吃掉的羊的数量 
int n,m;//羊的数量和需要吃掉的数量 

int dfs(map<pair<int, int>, int>&visit,int l,int r)
{
	if(l >= r)
	{
		return 0;
	}
	pair<int, int> p = make_pair(l, r);
    if(visit.find(p) != visit.end()) 
		return visit[p];
		
	int ans = INT_MAX;
	for(int i = 0; i < m && eat[i] <= r; i++)
	{
		//确保吃的羊在[l,r)区间内 
		if(eat[i] < l)
			continue;
		
		ans =  min(ans,dfs(visit,l,eat[i] - 1) + dfs(visit,eat[i]+1,r));
	}
	
	if(ans == INT_MAX)
		ans = 0;
	else
		ans += r-l;
		
	return visit[p] = ans;
}

int main()
{
	//减少cin cout 在标准输出输入流中消耗的世界 
	std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0); 
	int t;
	cin>>t;
	int num = t;
	while(t--)
	{
		cin>>n>>m;
		for(int i = 0; i < m; i++)
		{
			cin>>eat[i];
		}
		map<pair<int, int>, int> visit;
		ans.push_back(dfs(visit,1,n));
	}
	
	for(int i = 0; i < num; i++)
		cout<<ans[i]<<endl;
	
	return 0;
}
