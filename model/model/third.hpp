#pragma once

#include "head.hpp"

const int maxA3 = 14;
const int maxW3 = 1200;		//	最大负重
const int maxD3 = 10;		//	最大天数
const int basicM3 = 200;	//	基础收益
const int initM3 = 10000;	//	初始资金
goods _water3(0, 3, 5, 3, 9, 10);		// 水的质量，金额，对应天气消耗的量
goods _food3(1, 2, 10, 4, 9, 10);		// 食物的质量，金额，对应天气消耗的量


class third {
public:
	third(int statu = 0) {
		_info._money = 0x3f3f3f3f;
		_weather.resize(maxD3 + 1, statu);
	}

	/////////////////////////////////////////
	//////	根据天数得到消耗基础资源重量和价格
	/////////////////////////////////////////
	pair<int, int> GetBasic(int day, int statu) {
		int we = _weather[day];
		int money = _water3._expend[we] * _water3._basicM + _food3._expend[we] * _food3._basicM;
		int weight = _water3._expend[we] * _water3._weightA + _food3._expend[we] * _food3._weightA;


		return make_pair(weight * statu, money * statu);
	}

	////////////////////////////////////////
	///		根据路径得到需要消耗的资源
	///////////////////////////////////////
	bool GetExpend(vector<int>& path, vector<int>& ans, int day) {
		ans.clear();
		_info._money = 0x3f3f3f3f;
		int n = path.size();

		dfs(0, n - 1, day, path, ans, 0, 0);	//当前负重与当前消耗
		if (ans.size() == 0) return false;
		return true;
	}

	////////////////////////////////////////////
	////	打印最少的信息
	////////////////////////////////////////////
	void showInfo(vector<int>& path, int day) {
		int idx = 0;
		int num = 0;
		if (_info._money >= 0x3f3f3f3f) return;
		for (size_t i = 0; i < _info._path.size(); i++) {
			if (_info._path[i] == 1) {
				num++;
				continue;
			}

			if (num == 0)
				printf("%d->", path[idx++]);
			else
				printf("%d(%d)->", path[idx++], num);
			num = 0;
		}
		printf("%d 最大花费：%d  最大负重: %d 用时 %d 天\n", path.back(), _info._money, _info._weight, _info._day - day + 1);
	}

	/////////////////////////////////////////////
	////		村庄到终点
	/////////////////////////////////////////////
	void GetVD(unordered_map<int, set<int> >& map_t) {
		//村庄到终点
		vector<int> path = BFS(62, 64, map_t, maxA3);
		vector<int> ans;
		int day = _info._day;
		GetExpend(path, ans, day + 1);
		showInfo(path, day + 1);
		cout << endl;
	}

	///////////////////////////////////////////////
	////	挖矿的收益与消耗
	//////////////////////////////////////////////
	void GetMining(int start, int end) {
		int wight = 0;
		int money = 0;
		int num = 0;	//挖矿收益

		for (int i = start; i <= end; i++) {
			auto ret = GetBasic(i, 3);
			wight += ret.first;
			money += ret.second;
			num += basicM3;
		}
		if (wight <= maxW3)
			printf("%d : %d 挖矿，基础收益：%d 消耗的负重： %d  消耗的金钱： %d\n", start, end, num, wight, money);
	}
private:
	void dfs(int idx, int end, int day, vector<int>& path, vector<int>& ans, int curW, int curM) {
		if (curW > maxW3 || curM > initM3 || day > maxD3 || (end - idx + day > maxD3)) return;
		if (idx == end) {
			/*show(path, ans);
			cout << "最大负重 ： " << curW << " 最大花费：" << curM << endl;*/
			if (curM < _info._money) {
				_info._path = ans;
				_info._money = curM;
				_info._weight = curW;
				_info._day = day - 1;
			}
			return;
		}

		auto wait = GetBasic(day, 1);
		// 停留
		ans.push_back(1);
		dfs(idx, end, day + 1, path, ans, curW + wait.first, curM + wait.second);
		ans.pop_back();

		if (_weather[day] == 2) return;	//沙暴天不可前进
		auto go = GetBasic(day, 2);
		// 行走
		ans.push_back(0);
		dfs(idx + 1, end, day + 1, path, ans, curW + go.first, curM + go.second);
		ans.pop_back();
	}

	void show(vector<int>& path, vector<int>& ans) {
		cout << endl;
		for (auto& eoch : ans) cout << eoch << ' ';
		cout << endl;
		int idx = 0;
		int num = 0;
		for (size_t i = 0; i < ans.size(); i++) {
			if (ans[i] == 1) {
				num++;
				continue;
			}

			if (num == 0)
				printf("%d->", path[idx++]);
			else
				printf("%d(%d)->", path[idx++], num);
			num = 0;
		}
		printf("\b\b");
	}
private:
	node _info;
	vector<int> _weather;	//对应每天的天气
};