#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int n,sum;
const int N = 1010;
int f[N];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> f[i];
		sum += f[i];
	}
	
	sum /= n;
	for(int i = 0; i < n; i++) {
		if(abs(f[i]) > sum) {
			cout << f[i] << " ";
		} 
	}
	cout <<endl;
	return 0;
}
