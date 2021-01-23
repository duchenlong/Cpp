#include <iostream>
using namespace std;

const int N = 110;
int f[N][N],n;

void slove() {
    for(int i = 1; i <= n; i++) {
        int t = 1;
        for(int j = i; j <= n; j++) f[i][j] = t++;
        t = 1;
        for(int j = i; j <= n; j++) f[j][i] = t++;
    }
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cout << f[i][j] << " ";
        cout << endl;
    }
}

int main() {
    
    while(cin >> n, n) {
        slove();
        cout << endl;
    }
    
    return 0;
}

输入整数N，输出一个N阶的二维数组。

数组的形式参照样例。

输入格式
输入包含多行，每行包含一个整数N。

当输入行为N=0时，表示输入结束，且该行无需作任何处理。

输出格式
对于每个输入整数N，输出一个满足要求的N阶二维数组。

每个数组占N行，每行包含N个用空格隔开的整数。

每个数组输出完毕后，输出一个空行。

数据范围
0≤N≤100
输入样例：
1
2
3
4
5
0
输出样例：
1

1 2
2 1

1 2 3
2 1 2
3 2 1

1 2 3 4
2 1 2 3
3 2 1 2
4 3 2 1

1 2 3 4 5
2 1 2 3 4
3 2 1 2 3
4 3 2 1 2
5 4 3 2 1

