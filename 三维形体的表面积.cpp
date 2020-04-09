//在?N?*?N?的网格上，我们放置一些?1 * 1 * 1??的立方体。

//每个值?v = grid[i][j]?表示?v?个正方体叠放在对应单元格?(i, j)?上。

//请你返回最终形体的表面积。

//?

//示例 1：

//输入：[[2]]
//输出：10
//示例 2：

//输入：[[1,2],[3,4]]
//输出：34
//示例 3：

//输入：[[1,0],[0,2]]
//输出：16
//示例 4：

//输入：[[1,1,1],[1,0,1],[1,1,1]]
//输出：32
//示例?5：

//输入：[[2,2,2],[2,1,2],[2,2,2]]
//输出：46


class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int area = 0;
        int len = grid.size();

        for(int i = 0; i < len; i++)
            for(int j = 0; j < len; j++)
            {
                int height = grid[i][j];
                //去掉没有方块的情况
                if(!height)
                    continue;

                area += height * 4 + 2;
                //去掉并排的上一个重叠部分的面积
                area -= j > 0 ? min(height, grid[i][j-1]) * 2 : 0;
                //去掉前一排重叠部分的面积
                area -= i > 0 ? min(height,grid[i-1][j]) * 2 : 0;
            }
        
        return area;
    }
};
