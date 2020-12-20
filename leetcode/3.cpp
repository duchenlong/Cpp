#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct node {
	string name;
	string id;
	double a;
	string dan;
	int money;
	int sum;
	node(string s="",string i="",double _a=0.0,\
			string d="",int m=0,int ss=0) {
		name = s;
		id = i;
		a = _a;
		dan = d;
		money = m;
		sum = ss;
	}
};



bool c1(node a,node b) {
	return a.money > b.money;
}

bool c2(node a,node b) {
	return a.a > b.a;
}

bool c3(node a,node b) {
	return a.money * a.sum > b.money * b.sum;
}


const int N = 1010;
node f[N];
int n,m;

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> f[i].name >> f[i].id >> f[i].a >> f[i].dan \
			>> f[i].money >> f[i].sum;
	}
	// 0
	sort(f,f+n,c1);
	for(int i = 0; i < m; i++) {
		cout << f[i].a << " ";
	}
	cout << endl;
	
	// 1

	sort(f,f+n,c2);
	for(int i = 0; i < m; i++) {
		cout << f[i].id << " ";
	}
	cout << endl;
	
	//2

	sort(f,f+n,c3);
	for(int i = 0; i < m; i++) {
		cout << f[i].dan << " ";
	}
	cout << endl;
	return 0;
}
