//
//给定一个二维网格?board?和一个字典中的单词列表 words，找出所有同时在二维网格和字典中出现的单词。

//单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。

//示例:

//输入: 
//words = ["oath","pea","eat","rain"] and board =
//[
//  ['o','a','a','n'],
//  ['e','t','a','e'],
//  ['i','h','k','r'],
//  ['i','f','l','v']
//]

//输出:?["eat","oath"]
//说明:
//你可以假设所有输入都由小写字母 a-z?组成。

//提示:

//你需要优化回溯算法以通过更大数据量的测试。你能否早点停止回溯？
//如果当前单词不存在于所有单词的前缀中，则可以立即停止回溯。什么样的数据结构可以有效地执行这样的操作？散列表是否可行？为什么？ 前缀树如何？如果你想学习如何实现一个基本的前缀树，请先查看这个问题： 实现Trie（前缀树）。


class Solution {
public:
    const static int N = 100010;
    int son[N][26];
    int idx;
    string key[N];
    int row,col;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto& eoch : words) insert(eoch);
        vector<string> ret;
        row = board.size();
        col = board[0].size();
        vector<vector<int>> visit(row,vector<int> (col,0));

        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                visit[i][j] = 1;
                dfs(board,visit,i,j,0,ret);
                visit[i][j] = 0;
            }
        return ret;
    }

    void insert(string& s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        key[p] = s;
        //cout<<key[p]<<' '<<p<<endl;
    }

    void dfs(vector<vector<char> >& board,vector<vector<int> >& visit,int x,int y,int p,vector<string>& ret)
    {
        static int dir[4][2] = {-1,0,0,-1,1,0,0,1};
        int u = board[x][y] - 'a';
        //cout<<p<<' '<<board[x][y]<<' ';
        if(!son[p][u]) return;
        p = son[p][u];
        //cout<<p<<' '<<board[x][y]<<' ';
        if(key[p] != "")
        {
            ret.push_back(key[p]);
            key[p] = "";//防止出现多次  [["a","a"]]  ["a"]
        }

        for(int i = 0; i < 4; i++)
        {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];

            if(tx < 0 || tx >= row || ty < 0 || ty >= col || visit[tx][ty])
                continue;
            
            visit[tx][ty] = 1;
            dfs(board,visit,tx,ty,p,ret);
            visit[tx][ty] = 0;
        }
    }
};
