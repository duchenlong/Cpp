编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字?1-9?在每一行只能出现一次。
数字?1-9?在每一列只能出现一次。
数字?1-9?在每一个以粗实线分隔的?3x3?宫内只能出现一次。
空白格用?'.'?表示。



一个数独。



答案被标成红色。

Note:

给定的数独序列只包含数字?1-9?和字符?'.'?。
你可以假设给定的数独只有唯一解。
给定数独永远是?9x9?形式的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sudoku-solver
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
private:
    vector<vector<bool> > row;
    vector<vector<bool> > col;
    vector<vector<bool> > block;

public:
    Solution()
    {
        row     =   vector<vector<bool> > (9,vector<bool> (9,false));
        col     =   vector<vector<bool> > (9,vector<bool> (9,false));
        block   =   vector<vector<bool> > (9,vector<bool> (9,false));
    }

    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')  continue;

                //[i][j] == 1,2,...9
                int num = board[i][j] - '1';//0,1...,8
                row[i][num] = true;
                col[j][num] = true;
                block[i / 3 * 3 + j / 3][num] = true;
            }
        
        dfs(board,0,0);
    }

    bool dfs(vector<vector<char> >& board,int x,int y)
    {  
        //从当前行开始，找第一个空位
        while(board[x][y] != '.')
        {
            if(++y >= 9)
            {
                x++;
                y = 0;
            }

            if(x >= 9)  return true;
        }

        for(int i = 0; i < 9; i++)
        {
            int block_idx = x / 3 * 3 + y / 3;
            //排除不可能填的数字
            if(row[x][i] || col[y][i] || block[block_idx][i])   continue;
            
            //在x,y 填入 i
            board[x][y] = i + '1';
            row[x][i] = true;
            col[y][i] = true;
            block[block_idx][i] = true;

            if(dfs(board,x,y) == true)
                return true;
            
            //i 不适合当前位置，回溯
            board[x][y] = '.';
            row[x][i] = false;
            col[y][i] = false;
            block[block_idx][i] = false;
        }

        return false;
    }
};
