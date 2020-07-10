编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

?

示例 1：

输入：
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出：
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
示例 2：

输入：
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
输出：
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]




class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return;
        int m = matrix[0].size();
        vector<bool> row(n,false);
        vector<bool> col(m,false);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(matrix[i][j] == 0)
                    row[i] = col[j] = true;
        
        for(int i = 0; i < n; i++)
            if(row[i] == true)
                for(int j = 0; j < m; j++)
                    matrix[i][j] = 0;

        for(int j = 0; j < m; j++)
            if(col[j] == true)
                for(int i = 0; i < n; i++)
                    matrix[i][j] = 0;
    }
};
