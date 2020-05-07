#define _CRT_SECURE_NO_WARNINGS 1

#include "tree.h"

//读取数据
vector<point> ReadData()
{
	ifstream fp;
	fp.open("data.txt", ios::in);	//以读模式打开数据文件
	vector<point> temp;
	string str;
	while (getline(fp, str))
	{
		//cout << str << endl;
		point p;
		char ch = '\t';
		int start = 0;
		int len = 0;	//截取字符串长度
		//读取点的序号
		auto pos = find(str.begin(), str.end(), ch);
		len = pos - str.begin() - start;
		string t = str.substr(start, len);
		p._id = stoi(t);
		start += len + 1;
		//读取点的类型
		pos = find(str.begin() + start, str.end(), ch);
		len = pos - str.begin() - start;
		p._type = str.substr(start, len);
		start += len + 1;
		//读取横坐标
		pos = find(str.begin() + start, str.end(), ch);
		len = pos - str.begin() - start;
		t = str.substr(start, len);
		p._row = stoi(t);
		start += len + 1;
		//读取纵坐标
		len = str.end() - str.begin() - start;
		t = str.substr(start, len);
		p._col = stoi(t);

		temp.push_back(p);
	}

	fp.close();	//关闭文件
	return temp;
}

//查找二级供水站开始的位置
int FindSecond(vector<point>& points)
{
	for (size_t i = 1; i < points.size(); i++)
		if (points[i]._type[0] == 'P')
			return i;
	return points.size();//没有第二级点返回末尾位置
}

double com(point l, point r)
{
	return sqrt(pow(abs(l._row - r._row), 2) +
		pow(abs(l._col - r._col), 2));
}

side Path(point l, point r)
{
	side tmp;
	tmp._start = l._id;
	tmp._end = r._id;
	tmp._distance = com(l, r);
	//cout << tmp._start << ' ' << tmp._end << ' ' << tmp._distance << endl;
	//Sleep(500);
	return tmp;
}

//构成边
vector<side> SetSide(vector<point>& left, vector<point>& right)
{
	size_t len1 = left.size();
	size_t len2 = right.size();

	vector<side> tmp;
	//left 与 right
	for (size_t i = 0; i < len1; i++)
		for (size_t j = 0; j < len2; j++)
			tmp.push_back(Path(left[i], right[j])); //计算i点到j点的边

	//right 与 right
	for (size_t i = 0; i < len2; i++)
		for (size_t j = i + 1; j < len2; j++)
			tmp.push_back(Path(right[i], right[j])); //计算i点到j点的边
	return tmp;
}

//从小到大排序
bool cmp(const side a, const side b)
{
	return a._distance < b._distance;
}
//排列一级站与原点的距离
bool point_cmp(const point a, const point b)
{
	static point center = { 0, "A", 26, 31 };
	return com(a, center) < com(b, center);
}

//按边的距离从大到小排序
bool side_cmp(const side a, const side b)
{
	return a._distance > b._distance;
}

//在并查集中查找根节点的位置
int GetRoot(int k, vector<int>& V)
{
	while (k != V[k])
		k = V[k];//只有根节点才满足 k = V[k]
	return k;
}

//判断该管道是否为一级管道
bool FindP(int start, int end, vector<point>& one)
{
	int ans = 0;
	for (size_t i = 0; i < one.size(); i++)
	{
		if (one[i]._id == start || one[i]._id == end)
			ans++;
	}
	if (start == 0 || end == 0)
		ans++;
	return ans != 2;
}
//Kruskal 算法
double Kruskal(vector<side>& sides, vector<point>& points, vector<side>& sideTwo,vector<point>& one)
{
	double sum = 0;
	//排序,按照边的大小从小到大
	sort(sides.begin(), sides.end(), cmp);
	cout << "对所有的边安装从小到大的顺序进行排序" << endl;
	int pointNum = points.size();
	vector<int> V(pointNum, 0);//定义并查集数组
	//初始化每一个结点都是根节点，并查集中
	for (int i = 0; i < pointNum; i++)
		V[i] = i;

	//筛选
	int len = sides.size();//边的数目
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		int start = GetRoot(sides[i]._start, V);
		int end = GetRoot(sides[i]._end, V);
		if (start != end)
		{
			V[start] = end;
			sum += sides[i]._distance;

			if (FindP(sides[i]._start, sides[i]._end,one))
			{	//添加二级管道到数组中
				sideTwo.push_back(sides[i]);
				count++;
				if (count <= 89)
					cout << sides[i]._end << endl;
				//cout << points[sides[i]._start]._row << ' '<< points[sides[i]._start]._col <<' '<< points[sides[i]._end]._row << ' ' << points[sides[i]._end]._col << endl;
			}
			else
			{
				cout << points[sides[i]._start]._row << ' ' << points[sides[i]._start]._col << ' ' << points[sides[i]._end]._row << ' ' << points[sides[i]._end]._col << endl;
			}
			//cout << "第 " << i + 1 << " 次，选择 " << sides[i]._start << " 和 " << sides[i]._end << " 两个点，成功合并" << endl;
			//printf("选择 %3d 和 %3d 两点连接一条水管，长度为 %.2lf\n", sides[i]._start, sides[i]._end, sides[i]._distance);
		}
		/*else
		{
			cout << "第 " << i + 1 << " 次，选择 " << sides[i]._start << " 和 " << sides[i]._end << " 两个点，在一个集合中，无法合并" << endl;
		}*/
	}
	//cout << count/2 << endl;
	return sum;
}

//插入边  text2
void InsertSide(vector<side>& tmp, side s)
{
	if (tmp.size() < 2)
		tmp.push_back(s);
	else if (s._distance > tmp[1]._distance)
		tmp[1] = s;
	sort(tmp.begin(), tmp.end(), side_cmp);//从大到小排列
}

//广度搜索40公里长度的管道 --text3
void bfs(vector<vector<int> >& map, vector<vector<double> >& length, vector<int>& visit, vector<point>& one, int index,double& path)
{
	//广度优先
	queue<int> que;
	que.push(index);

	while (!que.empty())
	{
		size_t size = que.size();
		for (size_t i = 0; i < size; i++)
		{
			int start = que.front();//起点编号
			que.pop();

			for (size_t j = 0; j < map[start].size(); j++)
			{
				int end = map[start][j];//终点编号
				double len = length[start][j];
				if (visit[end] || len > path)
					continue;
				visit[end] = 1;
				path -= len;
				que.push(end);
			}
		}
	}
}