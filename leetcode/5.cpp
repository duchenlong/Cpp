#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

map<string,set<string> > mp;
set<string> l;
int n;

void bfs() {
	stack<string> st;
	st.push(*(l.begin()));
	l.erase(l.begin());
	
	while(!st.empty()) {
		string f = st.top();
		st.pop();
		
		set<string> ss = mp[f];
		set<string>::iterator it = ss.begin();
		while(it != ss.end()) {
			//cout << *it << " ";
			if(l.count(*it) == 0) {
				it++;
				continue;
			}
			st.push(*it);
			l.erase(l.find(*it));
			it++;
			
		}
	}
}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		string le,ri;
		cin >> le >> ri;
		l.insert(le);
		l.insert(ri);
		mp[le].insert(ri);
		mp[ri].insert(le);
	}
	
	int ans = 0;
	while(!l.empty()) {
		bfs();
		ans++;
	}
	cout << ans << endl;
	return 0;
}
