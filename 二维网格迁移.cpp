//给你一个 m 行 n?列的二维网格?grid?和一个整数?k。你需要将?grid?迁移?k?次。

//每次「迁移」操作将会引发下述活动：

//位于 grid[i][j]?的元素将会移动到?grid[i][j + 1]。
//位于?grid[i][n?- 1] 的元素将会移动到?grid[i + 1][0]。
//位于 grid[m?- 1][n - 1]?的元素将会移动到?grid[0][0]。
//请你返回?k 次迁移操作后最终得到的 二维网格。



//示例 1：
//输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
//输出：[[9,1,2],[3,4,5],[6,7,8]]

//示例 2：
//输入：grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
//输出：[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]


class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();

        //计算K次之后每一列元素的列号
        vector<int> c(col,0);
        for(int i = 0; i < col; i++){
            c[i] = (i + k) % col;
        }

        vector<vector<int> > ans(row,vector<int> (col,0));

        for(int j = 0; j < col; j++){
            //判断当前列元素经过k次之后，改变了多少次
            int path = 0;
            int tmp = j;
            for(int i = 0; i < k; i++){
                tmp = (tmp + 1) % col;
                path += (tmp == 0) ? 1 : 0;
            }

            for(int i = 0; i < row; i++){
                int x = (i + path) % row;
                ans[x][c[j]] = grid[i][j];
            }
        }

        return ans;
    }
};
