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

string s;
string fr;

int main() {
	cin >> s;
	cin >> fr;
	
	int n = s.size();
	int i = 0;
	vector<string> ans;
	
	while(i < n) {
		int p = i;
		while(p < n && s[p] != '-')
			p++;
		if(p == n) break;
		
		string le="",ri="";
		int pl = p - 1;
		while(pl >= 0 && s[pl] != '[') {
			pl--;
		}
		le = s.substr(pl+1,p - pl - 1);
		
		int pr = p + 1;
		while(pr < n && s[pr] != ']') {
			pr++;
		}
		ri = s.substr(p+1,pr - p -1);
		
		//cout << le << " " << ri << endl;
		
		if(le == fr && ri == fr){
			
		} else if(le == fr) {
			ans.push_back(ri);
		} else if(ri == fr) {
			ans.push_back(le);
		}
		
		i = pr + 1;
	}
	
	int m  = ans.size();
	if(m == 0) {
		cout << "NULL" << endl;
	} else {
		for(int i = 0; i < m; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}
