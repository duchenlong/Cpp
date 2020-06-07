给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord 到 endWord 的最短转换序列。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回一个空列表。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
[
  ["hit","hot","dot","dog","cog"],
? ["hit","hot","lot","log","cog"]
]
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: []

解释:?endWord "cog" 不在字典中，所以不存在符合要求的转换序列。




class Solution {
public:
    unordered_map<string,vector<string> > hash;
    vector<vector<string> > res;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //所有单词插入字典中，并去重
        unordered_set<string> dirc(wordList.begin(),wordList.end());
        //防止末尾单词不在字典中
        if(dirc.find(endWord) == dirc.end()) return res;

        //分别从路径的两端开始，维护一个双端的路径，防止单边过多深入
        unordered_set<string> beginW{beginWord};//始终都是有比较少的起始点
        unordered_set<string> endW{endWord};//存在比较多的起始点
        bool flag1 = false;
        bool flag2 = false;//true --> 维护一个 to->from  false  --> 维护一个 from-->to

        while(!beginW.empty())
        {
            unordered_set<string> tmp;

            for(auto& str : beginW) dirc.erase(str);

            for(auto& str : beginW)
                for(int i = 0; i < str.size(); i++)
                {
                    string s = str;
                    for(char ch = 'a'; ch <= 'z'; ch++)
                    {
                        s[i] = ch;
                        //如果没有转换后的单词
                        if(dirc.find(s) == dirc.end()) continue;

                        //如果当前单词在结尾set中出现，说明这次就是最短的路径了
                        if(endW.find(s) != endW.end()) flag1 = true;
                        else tmp.insert(s);

                        flag2 ? hash[s].push_back(str) : hash[str].push_back(s);
                    }
                }

            //已经到了最短队列
            if(flag1) break;

            if(tmp.size() <= endW.size())
                beginW = tmp;
            else
            {
                beginW = endW;
                endW = tmp;
                flag2 = !flag2;
            }
        }

        vector<string> ans;
        ans.push_back(beginWord);
        dfs(ans,beginWord,endWord);
        return res;
    }

    void dfs(vector<string>& ans,string& begin,string& end)
    {
        if(begin == end)
        {
            res.push_back(ans);
            return;
        }

        if(hash.find(begin) == hash.end()) return;

        for(auto& str : hash[begin])
        {
            ans.push_back(str);
            dfs(ans,str,end);
            ans.pop_back();
        }
    }

};
