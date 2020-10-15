#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;
using key = pair<int,int>;

int main() {
	fstream fp("D:\\桌面\\prog.txt");
	if(fp == nullptr) cout<< " open error" << endl;
	
	stack<key> st;
	st.push(make_pair(1,0));
	string str("");
	getline(fp,str);
	
	int ans = 0;
	
	while(getline(fp,str)) {
		//cout<< str << endl;
		int n = str.size();
		int num = str[n-2] - '0';
			
		while(true) {
			auto t = st.top();
			if(t.second >= n) {	// 上一级  同一级 
				st.pop();
			} else if(t.second < n) { 	// 下一级 
				num *= t.first;
				break;
			}
		}
		
		if(str[n-1] == ':') {	// REPEAT 2:
			st.push(make_pair(num,n));
		} else {	// A = A + 4
			int v = st.top().first;
			ans += v * (str[n-1] - '0');
			//cout << v << " " << str[n-1] << endl;
		}
	} 
	
	cout << ans << endl;
	return 0;
} 
