//有重复字符串的排列组合。编写一种方法，计算某字符串的所有排列组合。

//示例1:

// 输入：S = "qqe"
// 输出：["eqq","qeq","qqe"]
//示例2:

// 输入：S = "ab"
// 输出：["ab", "ba"]



class Solution {
public:
    vector<string> permutation(string S) {
        vector<string> ans;
        int len = S.size();
        sort(S.begin(),S.end());//排序，保证相同的字符串都在一起
        dfs(ans,S,0,len);
        return ans;
    }

    void dfs(vector<string>& ans, string& S,int index,int len) {
        //判断是否越界
        if(index == len) {
            string tmp = S;
            ans.push_back(tmp);
            return;
        }

        for(int i = index; i < len; i++) {
            //排除相同字符串的情况,可能是和起始位置相同，也可能是和前一个位置相同
            if(i > index && 
                (S[i] == S[index] || S[i] == S[i-1]) ) continue;
            swap(S[i],S[index]);//交换
            dfs(ans,S,index+1,len);
            swap(S[i],S[index]);//回溯
        }
    }
};
