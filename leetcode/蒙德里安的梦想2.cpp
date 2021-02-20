#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 12, M = 1 << 12;
long long f[N][M];
bool vis[M];
vector<int> st[M];
int n,m;

int main() {
    while(cin >> n >> m , n && m) {
        memset(f,0x00,sizeof f);
        
        for(int i = 0; i <= 1 << n; i++) {
            int cnt = 0;    // 连续的0的数量
            
            vis[i] = true;
            for(int j = 0; j < n; j ++) 
                if(i >> j & 1) {
                    if(cnt & 1) break;
                    
                    cnt = 0;
                } else {
                    cnt ++;
                }
            if(cnt & 1) vis[i] = false;
        }
        
        // 预处理每一个状态，可以转移的状态
        for(int j = 0; j <= 1 << n; j++) {
            st[j].clear();
            for(int k = 0; k <= 1 << n; k ++)
                if(vis[j | k] && (j & k) == 0) st[j].push_back(k);
        }
        
        f[0][0] = 1;
        for(int i = 1; i <= m; i++) 
            for(int j = 0; j < 1 << n; j++)
                for(auto& k : st[j])
                    f[i][j] += f[i-1][k];
        
        cout << f[m][0] << endl;
    }
}


求把N*M的棋盘分割成若干个1*2的的长方形，有多少种方案。

例如当N=2，M=4时，共有5种方案。当N=2，M=3时，共有3种方案。

如下图所示：

2411_1.jpg

输入格式
输入包含多组测试用例。

每组测试用例占一行，包含两个整数N和M。

当输入用例N=0，M=0时，表示输入终止，且该用例无需处理。

输出格式
每个测试用例输出一个结果，每个结果占一行。

数据范围
1≤N,M≤11
输入样例：
1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0
输出样例：
1
0
1
2
3
5
144
51205
