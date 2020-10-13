#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;
typedef long long ll;

const int N = 12, M = 1 << N; // 1-11 列，2^11 个状态
ll f[N][M];             // f[i][j] 从第i-1列伸出，到i列，状态为j,  j 的二进制位为1表示当前行放置方格，为0表示不放置
vector<int> state[M];   // 每一种状态，对应可以放置的状态
bool st[M];             // 是否可以成功转移，j 状态放置 k状态后 是否合法

int n, m;

int main() {
    while(cin >> n >> m, n || m) {
        
        // 初始化
        for(int i = 0; i < (1 << n); i ++) {
            int cnt = 0;    // 前面连续0的数量
            bool is_valid = true;
            
            for(int j = 0; j < n; j ++) {
                if((i >> j) & 1) {      // 1 放置
                    if(cnt & 1) {       // 前面连续0位奇数，不合法
                        is_valid = false;
                        break;
                    }
                    cnt = 0;
                } else {    // 0 不放置，连续0 + 1
                    cnt++;
                }
            }
            
            if(cnt & 1) is_valid = false;   // 余下0位奇数个，不合法
            st[i] = is_valid;
        }
        
        for(int i = 0; i < (1 << n); i ++) {
            state[i].clear();
            for(int j = 0; j < (1 << n); j ++) 
                if((i & j) == 0 && st[i | j])   state[i].push_back(j);  // 对于状态i来说，可以插入的状态为j
        }
        
        memset(f,0x00,sizeof(f));
        f[0][0] = 1;
        for(int i = 1; i <= m; i ++)
            for(int j = 0; j < (1 << n); j++)
                for(auto& k : state[j]) f[i][j] += f[i - 1][k];
        
        cout << f[m][0] << endl;
    }
    return 0;
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
