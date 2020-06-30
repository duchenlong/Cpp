输入一个字符串，打印出该字符串中字符的所有排列。

?

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

?

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
?


class Solution {
public:
    int len;
    vector<string> permutation(string s) {
        sort(s.begin(),s.end());
        len = s.size();

        vector<string> ans;
        dfs(s,0,ans);
        return ans;
    }

    void dfs(string& s,int idx,vector<string>& ans)
    {
        if(idx == len - 1)
        {
            ans.push_back(s);
            return;
        }

        //不排序做法
        for(int i = idx; i < len; i++)
        {
            if(check(s,idx,i))  continue;

            swap(s[i],s[idx]);
            dfs(s,idx+1,ans);
            swap(s[i],s[idx]);
        }

        // for(int i = idx; i < len; i++)
        // {
        //     //排序做法，不能使用引用
        //     if(i != idx && s[i] == s[idx])  continue;

        //     swap(s[i],s[idx]);
        //     dfs(s,idx+1,ans);
        // }
    }

    bool check(string& s,int start,int end)
    {
        for(int i = start; i < end; i++)
            if(s[i] == s[end])  return true;
        return false;
    }
};
