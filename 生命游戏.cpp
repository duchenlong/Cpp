//根据?百度百科?，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

//给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。
//每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。
//每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

//如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
//如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
//如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
//如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
//根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。
//下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。

//?

//示例：

//输入： 
//[
//? [0,1,0],
//? [0,0,1],
//? [1,1,1],
//? [0,0,0]
//]
//输出：
//[
//? [0,0,0],
//? [1,0,1],
//? [0,1,1],
//? [0,1,0]
//]
//?

//进阶：

//你可以使用原地算法解决本题吗？请注意，面板上所有格子需要同时被更新：
//你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。
//本题中，我们使用二维数组来表示面板。原则上，面板是无限的
//，但当活细胞侵占了面板边界时会造成问题。你将如何解决这些问题？



class Solution {
public:
    //空间复杂度 O(mn)的算法
    void gameOfLife1(vector<vector<int>>& board) {
        vector<vector<int> > dp = board;
        int row = board.size();
        int col = board[0].size();

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                dp[i][j] = Slove(board,i,j,row,col);
            }
        }

        board = dp;
    }
    //空间复杂度 O(1)的算法
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                //该位置变成活细胞
                if(Slove(board,i,j,row,col))
                {
                    //原本是死细胞
                    if(!board[i][j])
                        board[i][j] = 2;
                }
                else //该位置变成死细胞
                {
                    //原本就是活细胞
                    if(board[i][j])
                        board[i][j] = -1;
                }
            }
        }

         for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(board[i][j] > 1)
                    board[i][j] = 1;
                else if(board[i][j] < 0)
                    board[i][j] = 0;
    }

    int Slove(vector<vector<int>>& board,int x,int y,int row,int col)
    {
        static int dir[8][2] = {1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};//8个方向
        int num = 0;//统计周围活细胞的数量
        for(int i = 0; i < 8; i++)
        {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];

            if(tx < 0 || tx >= row || ty < 0 || ty >= col)
                continue;

            if(board[tx][ty] == 1 || board[tx][ty] == -1)
                num++;
        }

        //如果该位置是死细胞
        if( !board[x][y] && num == 3 )
            return 1;
        
        //如果该位置是活细胞
        if( board[x][y] && (num == 2 || num == 3))
            return 1;
        
        return 0;
    }
};
