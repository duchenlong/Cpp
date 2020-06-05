给定一个?m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。

示例?1:

输入: 
[
? [1,1,1],
? [1,0,1],
? [1,1,1]
]
输出: 
[
? [1,0,1],
? [0,0,0],
? [1,0,1]
]
示例?2:

输入: 
[
? [0,1,2,0],
? [3,4,5,2],
? [1,3,1,5]
]
输出: 
[
? [0,0,0,0],
? [0,4,5,0],
? [0,3,1,0]
]
进阶:

一个直接的解决方案是使用 ?O(mn)?的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m?+?n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个常数空间的解决方案吗？



class Solution {
public:
    struct node
    {
        int _x,_y;
        int _dir[2];

        node(int x,int y,int dir[2])
        {
            _x = x;
            _y = y;
            _dir[0] = dir[0];
            _dir[1] = dir[1];
        }
    };
    int up[2] = {1,0};
    int down[2] = {-1,0};
    int left[2] = {0,-1};
    int right[2] = {0,1};
    int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    void setZeroes1(vector<vector<int>>& matrix) {
        queue<node> que;
        int row = matrix.size();
        if(row == 0) return;
        int col = matrix[0].size();  
    
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j] == 0) Add(que,i,j);
            }
        
        while(!que.empty())
        {
            int size = que.size();

            for(int i = 0; i < size; i++)
            {
                node f = que.front();
                que.pop();

                int x = f._x;
                int y = f._y;
                if(x < 0 || x >= row || y < 0 || y >= col)
                    continue;
                matrix[x][y] = 0;
                int tx = x + f._dir[0];
                int ty = y + f._dir[1];
                node tmp(tx,ty,f._dir);
                que.push(tmp);
            }
        }


    }

    void Add(queue<node>& que,int x,int y)
    {
        for(int i = 0; i < 4; i++)
        {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            
            node tmp(tx,ty,dir[i]);
 
            que.push(tmp);
        }
    }



    void setZeroes(vector<vector<int>>& matrix)
    {
        int row = matrix.size();
        if(row == 0) return;
        int col = matrix[0].size();
        bool row0 = false, col0 = false;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(matrix[i][j] == 0)
                {
                    if (i == 0) row0 = true;
                    if (j == 0) col0 = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        
        for(int i = 1; i < row; i++)
            for(int j = 1; j < col; j++)
                if((matrix[i][0] == 0) || (matrix[0][j] == 0))
                    matrix[i][j] = 0;
         if(col0)
            for (int i = 0; i < row; i++) matrix[i][0] = 0;
        if (row0)
            for (int j = 0; j < col; j++) matrix[0][j] = 0;
    }
};
