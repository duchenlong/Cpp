#define _CRT_SECURE_NO_WARNINGS 1

#include "tree.h"
#include <vld.h>

double text1(vector<point>& points, vector<point>& zero, vector<point>& one, vector<point>& two)
{
	//点与点之间构成边
	vector<side> first = SetSide(zero,one);
	vector<side> secend = SetSide(one, two);

	//合并所有边
	vector<side> newside = first;
	for (size_t i = 0; i < secend.size(); i++)
		newside.push_back(secend[i]);
	double path = Kruskal(newside, points, first,one);
	
	//解决第二问
	/*vector<side> sideTwo;
	double path = Kruskal(newside, points,sideTwo);
	Text2(sideTwo,points);*/
	cout << "水管总长度 " << path << endl;
	return path;
}

void Text2(vector<side>& sideTwo, vector<point> points)
{
	sort(sideTwo.begin(), sideTwo.end(), side_cmp);
	vector<vector<double> > ans(2, vector<double>(2, 0));//所选择升级的点，与优化的距离

	vector<side> tmp;
	//找到连接一级站的边中最长的两个
	for (size_t i = 0; i < sideTwo.size(); i++)
	{
		int start = sideTwo[i]._start;
		int end = sideTwo[i]._end;
		if (points[start]._type[0] == 'V' || points[end]._type[0] == 'V')
		{
			InsertSide(tmp, sideTwo[i]);
		}
	}
	for (int i = 0; i < 2; i++)
	{
		if (points[tmp[i]._start]._type[0] == 'V')
			ans[i][0] = tmp[i]._end;
		else
			ans[i][0] = tmp[i]._start;
		ans[i][1] = tmp[i]._distance;
	}

	//去掉一个点，叶子节点
	vector<vector<double> > leaf;//叶子节点与叶子节点的距离
	vector<int> visit(200, 0);
	for (size_t i = 0; i < sideTwo.size(); i++)
	{
		visit[sideTwo[i]._start]++;
		visit[sideTwo[i]._end]++;
	}
	//添加叶子节点 叶子节点只需要省掉它本身连接的长度
	for (size_t i = 0; i < sideTwo.size(); i++)
	{
		if (visit[sideTwo[i]._start] == 1)
			leaf.push_back({ (double)sideTwo[i]._start, sideTwo[i]._distance });
		if (visit[sideTwo[i]._end] == 1)
			leaf.push_back({ (double)sideTwo[i]._end, sideTwo[i]._distance });
	}
	//更新
	for (size_t i = 0; i < leaf.size(); i++)
	{
		if (ans[1][1] < leaf[i][1]) ans[1] = leaf[i];
		if (ans[0][1] < ans[1][1]) swap(ans[0], ans[1]);
	}

	//二级点与二级点所连的边
	for (size_t i = 0; i < sideTwo.size(); i++)
	{
		int start = sideTwo[i]._start;
		int end = sideTwo[i]._end;
		double sum = ans[0][1] + ans[1][1];//当前优化的最多距离
		if (sum > sideTwo[i]._distance)
			continue;
		if (points[start]._type[0] != 'V' && points[end]._type[0] != 'V')
		{
			//升级这个必须两个水站一起升级
			ans[0][0] = start;
			ans[1][0] = end;
			ans[0][1] = ans[1][1] = sideTwo[i]._distance / 2;//各优化一半
			cout << start << ' ' << end << ' ' << sideTwo[i]._distance << endl;
		}
	}

	/*for (auto& eoch : ans)
		cout << eoch[0] << ' ' << points[eoch[0]]._row << ' ' << points[eoch[0]]._col << endl;*/
	cout << ans[0][1] + ans[1][1] << endl;
}

void text3(vector<point>& points, vector<point>& zero, vector<point>& one, vector<point>& two)
{
	vector<side> sideTwo;//二级管道的边
	//点与点之间构成边
	vector<side> first = SetSide(zero, one);
	double path = Kruskal(first, points, sideTwo,one);
	vector<side> secend = SetSide(one, two);
	path += Kruskal(secend, points, sideTwo,one);

	//cout << path + com(points[45], points[83])<<endl;//打印总里程

	//制作点与点的无向图
	vector<vector<int> > map(200);//点与点
	vector<vector<double> > length(200);//点与点构成边的长度
	for (size_t i = 0; i < sideTwo.size(); i++)
	{
		int start = sideTwo[i]._start;
		int end = sideTwo[i]._end;
		double len = sideTwo[i]._distance;
		map[start].push_back(end);
		length[start].push_back(len);

		map[end].push_back(start);
		length[end].push_back(len);
	}
	//一级水站安装距离原点的距离从小到大排序
	sort(one.begin(), one.end(), point_cmp);

	vector<int> visit(200, 0);//记录那些点被搜索了

	for (size_t i = 0; i < one.size(); i++)
	{
		size_t id = one[i]._id;
		visit[id] = 1;
		for (size_t j = 0; j < map[id].size(); j++)
		{
			int end = map[id][j];
			double len = 40 - length[id][j];
			if (len < 0 || end == 0) continue;
			visit[end] = 1;
			bfs(map, length, visit, one, end, len);
		}
	}
	int num = 0;
	for (size_t i = 0; i < points.size(); i++)
	{
		if (visit[i])
		{
			//打印统计到的点的坐标
			cout << points[i]._row << ' ' << points[i]._col << endl;
		}
	}
}


int main()
{
	//从文件中读取所有的点
	vector<point>  points = ReadData();
	/*for (auto& eoch : points)
		cout << eoch._id << ' ' << eoch._type << ' ' << eoch._row << ' ' << eoch._col << endl;*/
	vector<point> zero;	//找到原点
	vector<point> one;	//一级水站
	vector<point> two;	//二级水站
	
	for (auto& eoch : points)
	{
		if (eoch._type[0] == 'A') zero.push_back(eoch);
		else if (eoch._type[0] == 'P') two.push_back(eoch);
		else one.push_back(eoch);
	}

	//text1 text2
	double path = text1(points,zero,one,two);

	//text3
	//vector<int> tmp;
	/*for (size_t i = 0; i < two.size(); i++)
	{
	int tx = two[i]._row;
	int ty = two[i]._col;
	if (tx >= 20 && tx <= 30 && ty <= 50 && ty >= 30)
	tmp.push_back((int)i);
	}*/

	/*one.push_back(two[8]);
	one.push_back(two[32]);
	one.push_back(two[70]);
	two.erase(two.begin() + 70);
	two.erase(two.begin() + 32);
	two.erase(two.begin() + 8);*/
	//text3(points, zero, one, two);
	return 0;
}