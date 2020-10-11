class Solution {
public:
    int n,m;
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int ans = 0;
        for(int i = 0; i < n - 2; i++)
            for(int j = 0; j < m - 2; j++)
                ans += check(grid,i,j) == true ? 1 : 0;
        return ans;
    }

    bool check(vector<vector<int> >& grid,int x,int y) {
        static int vis[10];
        memset(vis,0x00,sizeof(vis));

        int num = grid[x][y] + grid[x+1][y+1] + grid[x+2][y+2];
        if(num != grid[x][y+2] + grid[x+1][y+1] + grid[x+2][y]) return false;

        // 行，列，检验元素是否为 1-9
        for(int i = 0; i < 3; i++) {
            int r = 0, c = 0;
            for(int j = 0; j < 3; j++) {
                int idx = grid[x+i][y+j];
                if(idx > 9 || idx == 0 || vis[idx] == 1) return false;
                vis[idx] = 1;
                r += idx;

                // 列
                idx = grid[x+j][y+i];
                c += idx;
            }
            if(r != num || c != num) return false;
        }
        return true;
    }
};


3 x 3 的幻方是一个填充有从 1 到 9 的不同数字的 3 x 3 矩阵，其中每行，每列以及两条对角线上的各数之和都相等。

给定一个由整数组成的 grid，其中有多少个 3 × 3 的 “幻方” 子矩阵？（每个子矩阵都是连续的）。

?

示例：

输入: [[4,3,8,4],
      [9,5,1,9],
      [2,7,6,2]]
输出: 1
解释: 
下面的子矩阵是一个 3 x 3 的幻方：
438
951
276

而这一个不是：
384
519
762

总的来说，在本示例所给定的矩阵中只有一个 3 x 3 的幻方子矩阵。
提示:

1 <= grid.length?<= 10
1 <= grid[0].length?<= 10
0 <= grid[i][j] <= 15

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/magic-squares-in-grid
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
