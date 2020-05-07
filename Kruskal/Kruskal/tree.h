#pragma once

#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <queue>
using namespace std;


struct point
{
	int _id;		//点的序号
	string _type;	//点的类型
	int _row;		//点的横坐标
	int _col;		//点的纵坐标
};

struct side
{
	int _start;	//起始点的id
	int _end;	//终点的id
	double _distance;	//欧式距离
};

void Text2(vector<side>& sideTwo, vector<point> points);
double text1(vector<point>& points, vector<point>& zero, vector<point>& one, vector<point>& two);
void text3(vector<point>& points, vector<point>& zero, vector<point>& one, vector<point>& two);

//按边的距离从大到小排序
bool side_cmp(const side a, const side b);
//从小到大排序
bool cmp(const side a, const side b);
//排列一级站与原点的距离
bool point_cmp(const point a, const point b);
//计算点与点之间距离
double com(point l, point r);

//查找二级供水站开始的位置
int FindSecond(vector<point>& points);

//返回一条边
side Path(point l, point r);

//在并查集中查找根节点的位置
int GetRoot(int k, vector<int>& V);

//构成边
vector<side> SetSide(vector<point>& left, vector<point>& right);

//Kruskal 算法
double Kruskal(vector<side>& sides, vector<point>& points, vector<side>& sideTwo, vector<point>& one);

//展示点
void Show(vector<point>& a);

//插入一条边 text2
void InsertSide(vector<side>& tmp, side s);

//读取数据
vector<point> ReadData();

//深度搜索40公里长度的管道
void bfs(vector<vector<int> >& map, vector<vector<double> >& length, vector<int>& visit, vector<point>& one, int index, double& path);