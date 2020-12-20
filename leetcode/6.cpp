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
const int N = 1010;
int f[N][2];
int n,m;

int main() {
	cin >> n >> m; 
	for(int i = 1; i <= n; i++) {
		cin >> f[i][0] >> f[i][1];
	}
	
	int ans = -1;
	double t = 0x3f3f3f3f; // ½Ç¶È
#define pi 3.1415926535
	for(int i = 1; i <= n; i++) {
		if(i == m) continue;
		double tt = atan2(f[i][0] - f[m][0],f[i][1] - f[m][1]) * 180 / pi;
		if(tt < 0) tt += 360;
		if(tt < t) {
			t = tt;
			ans = i;
		}
	}
	
	cout << ans << endl;
	return 0;
}
