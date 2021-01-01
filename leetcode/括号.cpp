class Solution {
public:
    vector<string> ans;
    string s;
    vector<string> generateParenthesis(int n) {
        s.reserve(n*2);
        dfs(n,n);
        return ans;
    }

    void dfs(int le,int ri) {
        if(le > ri) return;
        if(le == 0 && ri == 0) {
            ans.push_back(s);
            return ;
        }

        if(le) {
            s += '(';
            dfs(le - 1,ri);
            s.pop_back();
        }
            
        if(ri) {
            s += ')';
            dfs(le , ri - 1);
            s.pop_back();
        }
    }
};


括号。设计一种算法，打印n对括号的所有合法的（例如，开闭一一对应）组合。

说明：解集不能包含重复的子集。

例如，给出?n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/bracket-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
