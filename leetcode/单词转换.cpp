class Solution {
public:
    vector<string> ans;
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,bool> st;
        for(auto& s : wordList) st[s] = false;
        
        if(st.count(endWord) == 0) return ans;
        st.erase(beginWord);

        dfs(beginWord,endWord,st);

        return ans;
    }

    bool dfs(string& pre,string& endWord,unordered_map<string,bool>& st) {
        st[pre] = true;
        ans.push_back(pre);
        if(pre == endWord) {
            return true;
        }

        int n = pre.size();
        for(int i = 0; i < n; i++) {
            string t = pre;
            for(char ch = 'a'; ch <= 'z'; ch++) {
                t[i] = ch;
                if(st.count(t) && st[t] == false)
                    if(dfs(t,endWord,st)) return true;
            }
        }
        ans.pop_back();
        return false;
    }
};
给定字典中的两个词，长度相等。写一个方法，把一个词转换成另一个词， 但是一次只能改变一个字符。每一步得到的新词都必须能在字典中找到。

编写一个程序，返回一个可能的转换序列。如有多个可能的转换序列，你可以返回任何一个。

示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出:
["hit","hot","dot","lot","log","cog"]
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: []

解释:?endWord "cog" 不在字典中，所以不存在符合要求的转换序列。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-transformer-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
