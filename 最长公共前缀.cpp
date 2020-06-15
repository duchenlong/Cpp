编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串?""。

示例?1:

输入: ["flower","flow","flight"]
输出: "fl"
示例?2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母?a-z?。


class Solution {
public:
    //纵向搜索
    const static int N = 100010;
    int son[N][26] = {0};
    int idx = 0;
    string longestCommonPrefix1(vector<string>& strs) {
        int len = strs.size();
        if(len == 0) return "";

        insert(strs[0]);

        int ans = strs[0].size();
        for(int i = 1; i < len; i++)
        {
            ans = min(ans,search(strs[i]));
            if(ans == 0)    return "";
        }
            
        
        return strs[0].substr(0,ans);
    }

    void insert(string& s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u])  son[p][u] = ++idx;
            p = son[p][u];
       }
    }

    int search(string& s)
    {
        int p = 0;
        int ans = 0;

        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u])  return ans;
            p = son[p][u];
            ans++;
        }
        return ans;
    }

    //横向搜索
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if(len == 0) return "";


        int ans = strs[0].size();
        int ret = 0;
        for(int i = 0; i < ans; i++)
        {
            for(int j = 1; j < len; j++)
                if(strs[j][i] != strs[0][i])    return strs[0].substr(0,ret);

            ret++;
        }

        return strs[0];
    }

};
