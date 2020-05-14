//给定一个二维的矩阵，包含?'X'?和?'O'（字母 O）。

//找到所有被 'X' 围绕的区域，并将这些区域里所有的?'O' 用 'X' 填充。

//示例:

//X X X X
//X O O X
//X X O X
//X O X X
//运行你的函数后，矩阵变为：

//X X X X
//X X X X
//X X X X
//X O X X
//解释:

//被围绕的区间不会存在于边界上，换句话说，任何边界上的?'O'?都不会被填充为?'X'。 任何不在边界上，或不与边界上的?'O'?相连的?'O'?最终都会被填充为?'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。



class Solution {
public:
    void solve(vector<vector<char>>& board) {
    if(board.empty()||board[0].empty()) return;
        //运用深度优先搜索，沿着四边搜索，把每个在四边找的O深度优先搜索下去，凡是边缘找到的O都将它转换为"F"
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||i==m-1||j==0||j==n-1)
                    dfs(i,j,board);
            }
        } 
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='F')
                    board[i][j]='O';
            }
        }    
    }
    void dfs(int col,int row,vector<vector<char>>& board)
    {
        if(col<0||col>board.size()-1||row<0||row>board[0].size()-1)
            return;
        if(board[col][row]=='X'||board[col][row]=='F')
            return;
        else if(board[col][row]=='O')
        {
            board[col][row]='F';
            dfs(col-1,row,board);
            dfs(col+1,row,board);
            dfs(col,row-1,board);
            dfs(col,row+1,board);
        }
    }
    
};
