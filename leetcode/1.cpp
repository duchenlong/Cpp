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
int n;
double f[4];
double t[4];
double k[4];

int main() {
	cin >> n;
	for(int i = 0; i < 4; i++)
		cin >> f[i];
	
	for(int i = 0; i < n; i++) {
		char ch;
		double kg,r;
		cin >> ch >> kg >> r;
		if(ch == 'M') {
			k[0] += kg;
			t[0] += (kg / 100.0) * r;
		} else if(ch == 'V'){
			k[1] += kg;
			t[1] += (kg / 100.0) * r;
		} else if(ch == 'R') {
			k[2] += kg;
			t[2] += (kg / 100.0) * r;
		} else if(ch == 'S') {
			k[3] += kg;
			t[3] += (kg / 100.0) * r;
		}
	}
	
	double rr = t[0] + t[1] + t[2] + t[3];
	double ans = (k[0] * f[0] + k[1] * f[1] + ((k[2] <= 200)?0:(200-k[2])) *\
					f[2] + k[3] * f[3]) / 100.0;
	
	if(rr < 900.0) {
		ans = ans * 0.9;
	}
	//cout << ((double)((int)(ans * 100)) / 100) << endl;
	printf("%.2f\n",ans);
	return 0;
}
