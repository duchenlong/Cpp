#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010, M =20;
char s[N][M], f[M];
int t[M][M];
int n,m,k;

bool check(int id) {
    memset(t,0x00,sizeof t);
    
    for(int i = 1; s[id][i]; i++) t[i][0] = i;
    for(int i = 1; f[i]; i++) t[0][i] = i;
    int len1 = 0, len2 = 0;
    
    for(int i = 1; s[id][i] ; i ++) {
        len1 ++;
        len2 = 0;
        for(int j = 1; f[j]; j ++) {
            if(s[id][i] == f[j]) t[i][j] = t[i-1][j-1];
            else t[i][j] = min(t[i-1][j-1],min(t[i-1][j], t[i][j-1])) + 1;
            len2 ++;
        }
    }

    return (t[len1][len2] <= k) ? true : false;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> s[i] + 1;
    
    for(int i = 0; i < m; i++) {
        cin >> f + 1 >> k;
        
        int res = 0;
        for(int j = 0; j < n; j++) 
            if(check(j)) res ++;
        
        cout << res << endl;
    }
    
    return 0;
}

给定n个长度不超过10的字符串以及m次询问，每次询问给出一个字符串和一个操作次数上限。

对于每次询问，请你求出给定的n个字符串中有多少个字符串可以在上限操作次数内经过操作变成询问给出的字符串。

每个对字符串进行的单个字符的插入、删除或替换算作一次操作。

输入格式
第一行包含两个整数n和m。

接下来n行，每行包含一个字符串，表示给定的字符串。

再接下来m行，每行包含一个字符串和一个整数，表示一次询问。

字符串中只包含小写字母，且长度均不超过10。

输出格式
输出共m行，每行输出一个整数作为结果，表示一次询问中满足条件的字符串个数。

数据范围
1≤n,m≤1000,

输入样例：
3 2
abc
acd
bcd
ab 1
acbd 2
输出样例：
1
3
