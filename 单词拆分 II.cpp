给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。

说明：

分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：

输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
? "cats and dog",
? "cat sand dog"
]
示例 2：

输入:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出:
[
? "pine apple pen apple",
? "pineapple pen apple",
? "pine applepen apple"
]
解释: 注意你可以重复使用字典中的单词。
示例?3：

输入:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
输出:
[]


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,vector<string> > m;

        return dfs(m,wordDict,s);
    }

    vector<string> dfs(unordered_map<string,vector<string> >& m,vector<string>& wordDict,string s)
    {
        if(m.count(s))  return m[s];
        if(s.empty())   return {""};

        vector<string> ans;
        for(auto& str : wordDict)
        {
            if(s.substr(0,str.size()) != str)   continue;
            
            //从后半段开始继续查找
            vector<string> tmp = dfs(m,wordDict,s.substr(str.size()));

            for(auto eoch : tmp)
                ans.push_back(str + (eoch.empty() ? "" : " ") + eoch);
        }
        m[s] = ans;
        return ans;
    }
};
