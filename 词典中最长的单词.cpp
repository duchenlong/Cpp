//给出一个字符串数组words组成的一本英语词典。从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。若其中有多个可行的答案，则返回答案中字典序最小的单词。

//若无答案，则返回空字符串。

//示例 1:

//输入: 
//words = ["w","wo","wor","worl", "world"]
//输出: "world"
//解释: 
//单词"world"可由"w", "wo", "wor", 和 "worl"添加一个字母组成。
//示例 2:

//输入: 
//words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
//输出: "apple"
//解释: 
//"apply"和"apple"都能由词典中的单词组成。但是"apple"得字典序小于"apply"。
//注意:

//所有输入的字符串都只包含小写字母。
//words数组长度范围为[1,1000]。
//words[i]的长度范围为[1,30]。


class Solution {
public:
    const static int N = 10010;
    int son[N][26];
    int idx;
    string key[N];

    string longestWord(vector<string>& words) {
        for(auto& eoch : words) insert(eoch);

        string ret = "";
        int len = 0;

        for(auto& eoch : words)
        {
            int num = Find(eoch);
            //判断当前字符是否是由前面的字母，每次多一个组成的
            //word -->  w + wo + wor + word
            if(num != eoch.size()) continue;

            //如果组成的单词大于当前单词的长度，直接更新
            if(num > len)
            {
                len = num;
                ret = eoch;
            }
            else if(num == len)//等于，就需要判断字典序最小
                ret = min(ret,eoch);
        }

        return ret;
    }

    void insert(string& s)
    {
        int p = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        key[p] = s;
    }

    int Find(string& s)
    {
        int p = 0;
        int num = 0;//统计路径上有多少个单词
        for(int i = 0; i < s.size(); i++)
        {
            int u = s[i] - 'a';
            if(!son[p][u]) return num;
            p = son[p][u];
            if(key[p] != "") num++;
        } 
        return num;
    }
};
