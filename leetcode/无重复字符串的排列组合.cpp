class Solution {
public:
    vector<string> ans;

    vector<string> permutation(string S) {
        int n = S.size();
        dfs(S,0);

        return ans;
    }

    void dfs(string& s,int idx) {
        if(idx == s.size()) {
            ans.push_back(s);
            return ;
        }

        for(int i = idx; i < s.size(); i++) {
            swap(s[i],s[idx]);
            dfs(s,idx+1);
            swap(s[i],s[idx]);
        }
    }
};


无重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合，字符串每个字符均不相同。

示例1:

 输入：S = "qwe"
 输出：["qwe", "qew", "wqe", "weq", "ewq", "eqw"]
示例2:

 输入：S = "ab"
 输出：["ab", "ba"]
提示:

字符都是英文字母。
字符串长度在[1, 9]之间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-i-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
