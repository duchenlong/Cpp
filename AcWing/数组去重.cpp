#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;
int n;

int get_unique_count(int f[], int n) {
    int res = 1;
    for(int i = 1; i < n; i ++) {
        if(f[i] != f[i - 1])
            res ++;
    }
    return res;
}

int main() {
    cin >> n;
    int f[n] = {0};
    
    for(int i = 0; i < n; i++)
        cin >> f[i];
    sort(f,f + n);
    cout << get_unique_count(f,n) << endl;
    return 0;
}

给定一个长度为 n 的数组 a，请你编写一个函数：

int get_unique_count(int a[], int n);  // 返回数组前n个数中的不同数的个数
输入格式
第一行包含一个整数 n。

第二行包含 n 个整数，表示数组 a。

输出格式
共一行，包含一个整数表示数组中不同数的个数。

数据范围
1≤n≤1000
输入样例：
5
1 1 2 4 5
输出样例：
4
