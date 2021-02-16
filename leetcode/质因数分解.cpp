#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    for(int i = 2; ; i++) {
        if(n % i == 0) {
            n /= i;
            break;
        }
    }
    
    cout << n << endl;
    return 0;
}


已知正整数n是两个不同的质数的乘积，试求出较大的那个质数。

输入格式
输入只有一行，包含一个正整数n。

输出格式
输出只有一行，包含一个正整数p，即较大的那个质数。

数据范围
6≤n≤2?109
输入样例：
21
输出样例：
7
