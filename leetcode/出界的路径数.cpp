class Solution {
public:
    const int mod = 1e9 + 7;
    
    int findPaths(int m, int n, int N, int ii, int jj) {
        static int dir[4][2] = {1,0,-1,0,0,1,0,-1};

        int dp[m][n][2];
        memset(dp,0x00,sizeof dp);
        for(int k = 0; k < N; k++)
            for(int i = 0; i < m; i++)
                for(int j = 0; j < n; j++) {
                    dp[i][j][k % 2] = 0;    // 清除之前的状态
                    for(int d = 0; d < 4; d++) {
                        int x = i + dir[d][0];
                        int y = j + dir[d][1];
                        if(x < 0 || y < 0 || y >= n || x >= m) {
                            dp[i][j][k % 2] = (dp[i][j][k % 2] + 1) % mod;
                        } else {
                            dp[i][j][k % 2] = (dp[x][y][(k + 1) % 2] + dp[i][j][k % 2]) % mod; 
                        }
                    }  
                }
        return dp[ii][jj][(N + 1) % 2];

        // bfs
        // using key = pair<int,int>;
        // queue<key> que;
        // que.push(make_pair(i,j));

        // int ans = 0;
        // while(!que.empty() && N--) {
        //     int size = que.size();
        //     while(size --) {
        //         auto f = que.front();
        //         que.pop();

        //         for(int i = 0; i < 4; i++) {
        //             int x = f.first + dir[i][0];
        //             int y = f.second + dir[i][1];

        //             if(x < 0 || x >= m || y < 0 || y >= n) {
        //                 ans = (ans + 1) % mod;
        //                 continue;
        //             }
        //             que.push(make_pair(x,y));
        //         }
        //     }
        // }

        // return ans;
    }
};

给定一个 m × n 的网格和一个球。球的起始坐标为?(i,j)?，你可以将球移到相邻的单元格内，或者往上、下、左、右四个方向上移动使球穿过网格边界。但是，你最多可以移动?N?次。找出可以将球移出边界的路径数量。答案可能非常大，返回 结果 mod 109?+ 7 的值。

?

示例 1：

输入: m = 2, n = 2, N = 2, i = 0, j = 0
输出: 6
解释:

示例 2：

输入: m = 1, n = 3, N = 3, i = 0, j = 1
输出: 12
解释:

?

说明:

球一旦出界，就不能再被移动回网格内。
网格的长度和高度在 [1,50] 的范围内。
N 在 [0,50] 的范围内。
通过次数5,749提交次数15,332

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/out-of-boundary-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
