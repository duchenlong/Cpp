给定一个包含非负整数的 m?x?n?网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
? [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                int num = INT_MAX;
                if(i - 1 >= 0)  num = min(grid[i-1][j],num);
                if(j - 1 >= 0)  num = min(grid[i][j-1],num);

                grid[i][j] += num==INT_MAX ? 0 : num;
            }
        return grid[n-1][m-1];
    }
};
