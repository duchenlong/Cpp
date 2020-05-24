
//
//给定一个二维网格和一个单词，找出该单词是否存在于网格中。

//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

//?

//示例:

//board =
//[
//  ['A','B','C','E'],
//  ['S','F','C','S'],
//  ['A','D','E','E']
//]

//给定 word = "ABCCED", 返回 true
//给定 word = "SEE", 返回 true
//给定 word = "ABCB", 返回 false
//?

//提示：

//board 和 word 中只包含大写和小写英文字母。
//1 <= board.length <= 200
//1 <= board[i].length <= 200
//1 <= word.length <= 10^3

class Solution {
public:
    int row,col;
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();

        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                if(board[i][j] == word[0])
                {
                    vector<vector<bool> > visit(row,vector<bool> (col,false));
                    if(dfs(board,visit,i,j,word,1)) return true;
                }
            }
        return false;
    }

    bool dfs(vector<vector<char>>& board,vector<vector<bool>>& visit,int r,int c,string& word,int index)
    {
        if(index >= word.size()) return true;
        static int dir[4][2] = {-1,0,0,-1,1,0,0,1};

        for(int i = 0; i < 4; i++)
        {
            int x = r + dir[i][0];
            int y = c + dir[i][1];

            if(x < 0 || x >= row || y < 0 || y >= col || visit[x][y] || board[x][y] != word[index])
                continue;
            visit[r][c] = true;
            if(dfs(board,visit,x,y,word,index+1)) return true;
            visit[r][c] = false;
        }
        return false;
    }
};
