class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int f[N][N];
        memset(f,0x00,sizeof f);
        for(auto p : mines) f[p[0]][p[1]] = 1;

        int ans = 0;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) {
                if(f[i][j] == 1) continue;
                int cur = 0;
                int t = 0;
                // left
                for(int k = j; k >= 0 && f[i][k] != 1; k--) t++;
                cur = t;    // 左边连续的1的数量
                if(cur <= ans) continue;

                // right
                t = 0;
                for(int k = j; k < N && f[i][k] != 1; k++) t++;
                cur = min(cur,t);
                if(cur <= ans) continue;

                // up
                t = 0;
                for(int k = i; k >= 0 && f[k][j] != 1; k--) t++;
                cur = min(cur,t);
                if(cur <= ans) continue;

                // down
                t = 0;
                for(int k = i; k < N && f[k][j] != 1; k++) t++;
                cur = min(cur,t);
                
                ans = max(cur,ans); 
            }
        
        return ans;
    }
};


在一个大小在 (0, 0) 到 (N-1, N-1) 的2D网格?grid?中，除了在?mines?中给出的单元为?0，其他每个单元都是?1。网格中包含?1?的最大的轴对齐加号标志是多少阶？返回加号标志的阶数。如果未找到加号标志，则返回 0。

一个?k" 阶由?1?组成的“轴对称”加号标志具有中心网格??grid[x][y] = 1?，以及4个从中心向上、向下、向左、向右延伸，长度为?k-1，由?1?组成的臂。下面给出?k" 阶“轴对称”加号标志的示例。注意，只有加号标志的所有网格要求为 1，别的网格可能为 0 也可能为 1。

?

k 阶轴对称加号标志示例:

阶 1:
000
010
000

阶 2:
00000
00100
01110
00100
00000

阶 3:
0000000
0001000
0001000
0111110
0001000
0001000
0000000
?

示例 1：

输入: N = 5, mines = [[4, 2]]
输出: 2
解释:

11111
11111
11111
11111
11011

在上面的网格中，最大加号标志的阶只能是2。一个标志已在图中标出。
?

示例 2：

输入: N = 2, mines = []
输出: 1
解释:

11
11

没有 2 阶加号标志，有 1 阶加号标志。
?

示例 3：

输入: N = 1, mines = [[0, 0]]
输出: 0
解释:

0

没有加号标志，返回 0 。
?

提示：

整数N 的范围：?[1, 500].
mines 的最大长度为?5000.
mines[i] 是长度为2的由2个?[0, N-1]?中的数组成.
(另外,使用 C, C++, 或者?C# 编程将以稍小的时间限制进行??判断.)
?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-plus-sign
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
