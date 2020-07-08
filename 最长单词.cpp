给定一组单词words，编写一个程序，找出其中的最长单词，且该单词由这组单词中的其他单词组合而成。若有多个长度相同的结果，返回其中字典序最小的一项，若没有符合要求的单词则返回空字符串。

示例：

输入： ["cat","banana","dog","nana","walk","walker","dogwalker"]
输出： "dogwalker"
解释： "dogwalker"可由"dog"和"walker"组成。
提示：

0 <= len(words) <= 100
1 <= len(words[i]) <= 100

class Solution {
public:
    string longestWord(vector<string>& words) {
        unordered_set<string> map(words.begin(),words.end());
        sort(words.begin(),words.end(),cmp);

        for(auto& word : words)
        {
            map.erase(word);
            if(check(word,map))    return word;
            map.insert(word);
        }
        return "";
    }

    bool check(string str,unordered_set<string>& map)
    {
        if(str == "")   return true;

        for(int len = 1; len <= str.size(); len++)
        {
            string tmp = str.substr(0,len);
            if(map.find(tmp) != map.end() && check(str.substr(len),map))
                return true;
        }
        return false;
    }

    static bool cmp(const string& a,const string& b)
    {
        if(a.size() != b.size())
            return a.size() > b.size();
        return a < b;
    }
};
