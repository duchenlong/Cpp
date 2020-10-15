#include <iostream>

using namespace std;

int main() {
	int cur = 10000;
	int t = 0;
	int flag = 0;
	
	while(cur > 0) {
		if(flag < 60) {
			cur -= 10;
		} else {
			cur += 5;
		}
		
		t++;
		flag++;
		if(flag == 120) flag = 0;
	}
	
	cout << t <<  endl;	
	return 0;
}
