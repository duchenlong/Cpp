#include <iostream>

using namespace std;

class Data {
public:
	Data(int y,int m,int d) {
		_y = y;
		_m = m;
		_d = d;
	}
	
	int check(Data& v) {
		int ret = 0;
		cout<<_y<<" "<<_m<<" "<<_d<<endl;
		while(isS(v) == false) {
			*this += 1;
			ret++;
			//cout<<_y<<" "<<_m<<" "<<_d<<endl;
		}
		cout<<_y<<" "<<_m<<" "<<_d<<endl;
		return ret;
	}
	
	int Md(int y,int m) {
		static int M[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
		int ret = M[m];
		if(m == 2 && isY(y)) ret++;
		return ret;
	}
	
	bool isY(int y) {
		if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) return true;
		return false;
	}
	
	void operator+=(int v) {
		_d += v;
		int md = Md(_y,_m);
		if(_d > md) {
			_d = 1;
			_m ++;
			if(_m == 13) {
				_m = 1;
				_y ++;
			}
		}
	}
	
	bool isS(Data& d){
		return _y == d._y && _m == d._m && _d == d._d;
	}
private:
	int _y;
	int _m;
	int _d;
};

int main() {
	Data d(1921,7,23);
	Data d1(2020,7,1);
	cout << d.check(d1) * 24 * 60 << endl;
	return 0;
}



