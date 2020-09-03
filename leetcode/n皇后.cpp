n?皇后问题研究的是如何将 n?个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。



上图为 8 皇后问题的一种解法。

给定一个整数 n，返回所有不同的?n?皇后问题的解决方案。

每一种解法包含一个明确的?n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

?

示例：

输入：4
输出：[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
解释: 4 皇后问题存在两个不同的解法。


class Solution {
public:
    vector<int> col;
    vector<bool> vis;
    vector<vector<string> > ans;
    vector<vector<string>> solveNQueens(int n) {
        col.resize(n,0);
        vis.resize(n,false);

        dfs(0,n);

        return ans;
    }

    void dfs(int idx,int n){
        if(idx == n){
            check(n);
            return ;
        }

        for(int i = 0; i < n; i++){
            if(vis[i] == true)  continue;
            col[i] = idx;
            vis[i] = true;
            dfs(idx+1,n);
            vis[i] = false;
        }
    }

    void check(int n){
        for(int i = 0; i < n; i++)
            for(int j = i+1; j < n; j++)
                if(abs(i-j) == abs(col[i] - col[j]))    return;

        vector<string> tmp;

        for(int i = 0; i < n; i++){
            string str("");
            for(int j = 0; j < n; j++){
                if(j == col[i]) str += 'Q';
                else str += '.';
            }
            tmp.push_back(str);
        }
        ans.push_back(tmp);
    }
};
