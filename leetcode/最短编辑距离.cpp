#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010;
int n,m;
char s[N],t[N];
int f[N][N];

int main() {
    cin >> n >> s + 1;
    cin >> m >> t + 1;
    
    for(int i = 1; i <= n; i++) f[i][0] = i;
    for(int j = 1; j <= m; j++) f[0][j] = j;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) {
            f[i][j] = min(f[i-1][j],f[i][j-1]) + 1;
            if(s[i] == t[j]) f[i][j] = min(f[i][j],f[i-1][j-1]);
            else f[i][j] = min(f[i][j],f[i-1][j-1] + 1);
        }
    cout << f[n][m] << endl;
    return 0;
}

给定两个字符串A和B，现在要将A经过若干操作变为B，可进行的操作有：

删除–将字符串A中的某个字符删除。
插入–在字符串A的某个位置插入某个字符。
替换–将字符串A中的某个字符替换为另一个字符。
现在请你求出，将A变为B至少需要进行多少次操作。

输入格式
第一行包含整数n，表示字符串A的长度。

第二行包含一个长度为n的字符串A。

第三行包含整数m，表示字符串B的长度。

第四行包含一个长度为m的字符串B。

字符串中均只包含大写字母。

输出格式
输出一个整数，表示最少操作次数。

数据范围
1≤n,m≤1000
输入样例：
10 
AGTCTGACGC
11 
AGTAAGTAGGC
输出样例：
4
