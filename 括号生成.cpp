//数字 n?代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

//?

//示例：

//输入：n = 3
//输出：[
//       "((()))",
//       "(()())",
//       "(())()",
//       "()(())",
//       "()()()"
//     ]

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string src;
        dfs(ans,src,n,n);
        return ans;
    }

    void dfs(vector<string>& ans,string src, int left,int right)
    {
        //左右括号全部加完了
        if(left + right == 0)
        {
            ans.push_back(src);
            return;
        }

        //先加左括号
        if(left > 0)
            dfs(ans,src + '(',left-1,right);

        //如果右括号比左括号多，加右括号
        if(right > left)
            dfs(ans,src + ')',left,right-1);
       
    }
}
