#pragma once

///////////////////////////////////////////
///		公共代码，头文件
//////////////////////////////////////////

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <unordered_map>
#include <set>
#include <queue>

using namespace std;

// 食物重量，金额，每种天气的消耗
struct goods {
	int _id;		//	0 水，1 食物
	int _weightA;	//	每箱质量
	int _basicM;	//	基准价格
	int _expend[3];	// 每天的基础消耗 0 晴朗天，1 高温天，2 沙暴天

	goods(int id, int w, int b, int n1, int n2, int n3)
		:_id(id), _weightA(w), _basicM(b)
	{
		_expend[0] = n1;
		_expend[1] = n2;
		_expend[2] = n3;
	}
};

struct node {
	vector<int> _path;
	int _weight;
	int _money;
	int _day;
};


void DFS(int idx, int to, vector<int>& ans, unordered_map<int, set<int> >& map_t, vector<int>& arr, bool& flag);
vector<int> BFS(int start, int end, unordered_map<int, set<int> >& map_t, int n);
void ReadPath(unordered_map<int, set<int> >& map_t, const string filename);
void ReadWeather(vector<int>& w, const string fileName);

///////////////////////////////////////////
////	广度优先搜索 得到指定两点的最短路径
//////////////////////////////////////////
vector<int> BFS(int start, int end, unordered_map<int, set<int> >& map_t, int n) {
	vector<int> arr(n, -1);
	queue<int> que;

	que.push(start);
	int idx = 1;
	arr[start] = idx++;

	while (que.empty() == false) {
		int size = que.size();
		bool flag = false;

		while (size--) {
			int from = que.front();
			que.pop();
			for (int to : map_t[from]) {
				if (arr[to] != -1)	continue;
				que.push(to);
				arr[to] = idx;
				if (to == end)	flag = true;
			}
		}

		idx++;
		if (flag == true) break;
	}

	// dfs 从后向前推出路径
	vector<int> ans;
	bool flag = false;
	DFS(idx - 1, end, ans, map_t, arr, flag);
	reverse(ans.begin(), ans.end());

	return ans;
}

/////////////////////////////////////////////////
////////	dfs  从后向前推路径
////////////////////////////////////////////////
void DFS(int idx, int to, vector<int>& ans, unordered_map<int, set<int> >& map_t, vector<int>& arr, bool& flag) {
	if (idx == 1) {
		ans.push_back(to);
		flag = true;
		return;
	}

	ans.push_back(to);
	for (int from : map_t[to]) {
		if (arr[from] != idx - 1) continue;

		DFS(idx - 1, from, ans, map_t, arr, flag);
		if (flag == true) return;
	}
	ans.pop_back();
}


/////////////////////////////////////////////
/////		读取文件中边与边的关系
////////////////////////////////////////////
void ReadPath(unordered_map<int, set<int> >& map_t, const string fileName) {
	ifstream  fp;
	fp.open(fileName.c_str(), ios::in);
	int u = 0;
	int v = 0;

	while (!fp.eof()) {
		fp >> u >> v;
		//cout << u << ' ' << v<<endl;
		map_t[u].insert(v);
		map_t[v].insert(u);
	}

	fp.close();
}

///////////////////////////////////////////////
///////		去读文件中每天的天气情况
//////////////////////////////////////////////
void ReadWeather(vector<int>& w, const string fileName) {
	ifstream  fp;
	fp.open(fileName.c_str(), ios::in);
	int id = 0;
	int stauts = 0;

	while (!fp.eof()) {
		fp >> id >> stauts;
		/*if (stauts == 0) cout << "晴朗 ";
		else if (stauts == 1) cout << "高温 ";
		else cout << "沙暴 ";*/
		w[id] = stauts;
	}

	fp.close();
}