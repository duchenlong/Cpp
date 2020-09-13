#define _CRT_SECURE_NO_WARNINGS 1

#include "head.hpp"
#include "first.hpp"
#include "second.hpp"
#include "third.hpp"
#include "fourth.hpp"
#include "fifth.hpp"

void test1() {
	unordered_map<int, set<int> > map_t;	// 由每个区域组成的无向图
	ReadPath(map_t, "1-p.txt");
	cout << "起点到村庄：" << endl;
	first f;
	vector<int> path = BFS(1, 15, map_t, 28);		// 起点到终点
	int day = 1;
	vector<int> ans;
	f.GetExpend(path, ans, day);
	f.showInfo(path, day);

	cout << "村庄到矿山" << endl;
	path = BFS(15, 12, map_t, 28);		// 起点到矿山
	ans.clear();
	f.GetExpend(path, ans, day);
	f.showInfo(path, day);

	cout << "挖矿列表：" << endl;
	for (int end = 11; end <= 23; end++) {
		f.GetMining(11, end);
	}

	cout << "矿山到村庄，再到终点：" << endl;
	ans.clear();
	path = BFS(12, 27, map_t, 28);	// 矿山到终点
	for (int i = 12; i < 21; i++) {
		printf("%d 天出发 ：", i);
		vector<int> ans;
		f.GetExpend(path, ans, i);
		f.showInfo(path, i);
		f.GetVD(map_t);
	}
}

void test2() {
	unordered_map<int, set<int> > map_t;	// 由每个区域组成的无向图
	ReadPath(map_t, "2-p.txt");
	second f;
	cout << "起点到村庄39 " << endl;
	vector<int> path = BFS(1, 39, map_t, 65);
	int day = 1;
	vector<int> ans;
	f.GetExpend(path, ans, day);
	f.showInfo(path, day);

	cout << "村庄39 到 矿山 55" << endl;
	day = 11;
	path = BFS(39, 55, map_t, 65);
	ans.clear();
	f.GetExpend(path, ans, day);
	f.showInfo(path, day);

	cout << "挖矿： " << endl;
	for (int end = 14; end < 28; end++) {
		f.GetMining(14, end);
	}

	cout << "矿山55 到 村庄62 到终点64 " << endl;
	path = BFS(55, 62, map_t, 65);
	for (int i = 15; i <= 26; i++) {
		printf("%d 天出发 ：", i);
		vector<int> ans;
		f.GetExpend(path, ans, i);
		f.showInfo(path, i);
		f.GetVD(map_t);
	}
}

void test3(int statu = 0) {
	unordered_map<int, set<int> > map_t;	// 由每个区域组成的无向图
	ReadPath(map_t, "3-p.txt");

	third f(statu);//全是晴朗天气
	cout << "起点到终点" << endl;
	vector<int> path = BFS(1, 13, map_t, 14);
	int day = 1;
	vector<int> ans;
	f.GetExpend(path, ans, day);
	f.showInfo(path, day);
	cout << "----------------------------" << endl;
	cout << "起点到矿山，再到终点" << endl;
	path = BFS(1, 9, map_t, 14);
	day = 1;
	f.GetExpend(path, ans, day);
	f.showInfo(path, day);

	cout << "挖矿" << endl;
	for (int end = 4; end < 8; end++) {
		f.GetMining(4, end);
	}
	cout << "矿山到终点" << endl;
	path = BFS(9, 13, map_t, 14);
	for (int i = 5; i <= 8; i++) {
		printf("%d 天出发 ：", i);
		f.GetExpend(path, ans, i);
		f.showInfo(path, i);
	}
}

void test4(int stau = 0) {
	unordered_map<int, set<int> > map_t;	// 由每个区域组成的无向图
	ReadPath(map_t, "4-p.txt");
	fourth f(stau);
	cout << "起点到村庄14 " << endl;
	vector<int> path = BFS(1, 14, map_t, 26);
	int day = 1;
	vector<int> ans;
	f.GetExpend(path, ans, day);
	f.showInfo(path, day);

	cout << "村庄14 到 矿山 18" << endl;
	day = 6;
	path = BFS(14, 18, map_t, 26);
	f.GetExpend(path, ans, day);
	f.showInfo(path, day);

	cout << "挖矿： " << endl;
	for (int end = 8; end < 23; end++) {
		f.GetMining(8, end);
	}

	cout << "矿山18 终点25 " << endl;
	path = BFS(18, 25, map_t, 26);
	for (int i = 9; i <= 23; i++) {
		printf("%d 天出发 ：", i);
		vector<int> ans;
		f.GetExpend(path, ans, i);
		f.showInfo(path, i);
	}
}

void test5() {
	unordered_map<int, set<int> > map_t;	// 由每个区域组成的无向图
	ReadPath(map_t, "3-p.txt");

	fifth f;//全是晴朗天气
	cout << "起点到终点" << endl;
	vector<int> path = BFS(1, 13, map_t, 14);
	int day = 1;
	vector<int> ans;
	f.GetExpend(path, ans, day);
	f.showInfo(path, day);
	cout << "----------------------------" << endl;
	cout << "起点到矿山，再到终点" << endl;
	path = BFS(1, 9, map_t, 14);
	day = 1;
	f.GetExpend(path, ans, day);
	f.showInfo(path, day);

	cout << "挖矿" << endl;
	for (int end = 4; end < 8; end++) {
		f.GetMining(4, end);
	}
	cout << "矿山到终点" << endl;
	path = BFS(9, 13, map_t, 14);
	for (int i = 5; i <= 8; i++) {
		printf("%d 天出发 ：", i);
		f.GetExpend(path, ans, i);
		f.showInfo(path, i);
	}
}

int main() {
	cout << "test 1 begin " << endl;
	test1();
	cout << endl << "test 1 end " << endl;

	cout << "test 2 begin " << endl;
	test2();
	cout << endl << "test 2 end " << endl;

	cout << "test 3 begin " << endl;
	cout << "全是晴朗天气" << endl;
	test3(0);
	cout << endl << "全是高温天气" << endl;
	test3(1);
	cout << endl << "test 3 end " << endl;

	cout << "test 4 begin " << endl;
	cout << "全是晴朗天气" << endl;
	test4(0);
	cout << endl << "全是高温天气" << endl;
	test4(1);
	cout << endl << "test 4 end " << endl;

	cout << "test 5 begin " << endl;
	test5();
	cout << endl << "test 5 end " << endl;
	return 0;
}
