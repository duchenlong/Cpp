#pragma once

#include "head.hpp"

const int maxA5 = 14;
const int maxW5 = 1200;		//	�����
const int maxD5 = 10;		//	�������
const int basicM5 = 200;	//	��������
const int initM5 = 10000;	//	��ʼ�ʽ�
goods _water5(0, 3, 5, 3, 9, 10);		// ˮ������������Ӧ�������ĵ���
goods _food5(1, 2, 10, 4, 9, 10);		// ʳ�������������Ӧ�������ĵ���


class fifth {
public:
	fifth() {
		_info._money = 0x3f3f3f3f;
		_weather.resize(maxD5 + 1, -1);
		ReadWeather(_weather, "5-w.txt");
	}

	/////////////////////////////////////////
	//////	���������õ����Ļ�����Դ�����ͼ۸�
	/////////////////////////////////////////
	pair<int, int> GetBasic(int day, int statu) {
		int we = _weather[day];
		int money = _water5._expend[we] * _water5._basicM + _food5._expend[we] * _food5._basicM;
		int weight = _water5._expend[we] * _water5._weightA + _food5._expend[we] * _food5._weightA;


		return make_pair(weight * statu, money * statu);
	}

	////////////////////////////////////////
	///		����·���õ���Ҫ���ĵ���Դ
	///////////////////////////////////////
	bool GetExpend(vector<int>& path, vector<int>& ans, int day) {
		ans.clear();
		_info._money = 0x3f3f3f3f;
		int n = path.size();

		dfs(0, n - 1, day, path, ans, 0, 0);	//��ǰ�����뵱ǰ����
		if (ans.size() == 0) return false;
		return true;
	}

	////////////////////////////////////////////
	////	��ӡ���ٵ���Ϣ
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
		printf("%d ��󻨷ѣ�%d  �����: %d ��ʱ %d ��\n", path.back(), _info._money, _info._weight, _info._day - day + 1);
	}

	/////////////////////////////////////////////
	////		��ׯ���յ�
	/////////////////////////////////////////////
	void GetVD(unordered_map<int, set<int> >& map_t) {
		//��ׯ���յ�
		vector<int> path = BFS(62, 64, map_t, maxA5);
		vector<int> ans;
		int day = _info._day;
		GetExpend(path, ans, day + 1);
		showInfo(path, day + 1);
		cout << endl;
	}

	///////////////////////////////////////////////
	////	�ڿ������������
	//////////////////////////////////////////////
	void GetMining(int start, int end) {
		int wight = 0;
		int money = 0;
		int num = 0;	//�ڿ�����

		for (int i = start; i <= end; i++) {
			auto ret = GetBasic(i, 3);
			wight += ret.first;
			money += ret.second;
			num += basicM5;
		}
		if (wight <= maxW5)
			printf("%d : %d �ڿ󣬻������棺%d ���ĵĸ��أ� %d  ���ĵĽ�Ǯ�� %d\n", start, end, num, wight, money);
	}
private:
	void dfs(int idx, int end, int day, vector<int>& path, vector<int>& ans, int curW, int curM) {
		if (curW > maxW5 || curM > initM5 || day > maxD5 || (end - idx + day > maxD5)) return;
		if (idx == end) {
			/*show(path, ans);
			cout << "����� �� " << curW << " ��󻨷ѣ�" << curM << endl;*/
			if (curM < _info._money) {
				_info._path = ans;
				_info._money = curM;
				_info._weight = curW;
				_info._day = day - 1;
			}
			return;
		}

		auto wait = GetBasic(day, 1);
		// ͣ��
		ans.push_back(1);
		dfs(idx, end, day + 1, path, ans, curW + wait.first, curM + wait.second);
		ans.pop_back();

		if (_weather[day] == 2) return;	//ɳ���첻��ǰ��
		auto go = GetBasic(day, 2);
		// ����
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
	vector<int> _weather;	//��Ӧÿ�������
};