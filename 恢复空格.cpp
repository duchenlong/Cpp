哦，不！你不小心把一个长篇文章中的空格、标点都删掉了，并且大写也弄成了小写。像句子"I reset the computer. It still didn’t boot!"已经变成了"iresetthecomputeritstilldidntboot"。在处理标点符号和大小写之前，你得先把它断成词语。当然了，你有一本厚厚的词典dictionary，不过，有些词没在词典里。假设文章用sentence表示，设计一个算法，把文章断开，要求未识别的字符最少，返回未识别的字符数。

注意：本题相对原题稍作改动，只需返回未识别的字符数

?

示例：

输入：
dictionary = ["looked","just","like","her","brother"]
sentence = "jesslookedjustliketimherbrother"
输出： 7
解释： 断句后为"jess looked just like tim her brother"，共7个未识别字符。
提示：

0 <= len(sentence) <= 1000
dictionary中总字符数不超过 150000。
你可以认为dictionary和sentence中只包含小写字母。


class Solution {
public:
    static const int N = 150010;
    int son[N][26];
    int idx = 0;
    bool key[N];
    //字典树 + 深搜
    int respace1(vector<string>& dictionary, string sentence) {
        for(auto& word : dictionary)
            insert(word);
        int ans = INT_MAX;

        dfs(sentence,0,0,ans);

        return ans==INT_MAX ? 0 : ans;
    }

    void dfs(string& str,int index, int len,int& ans)
    {
        for(int i = index; i < str.size(); i++)
        {
            vector<int> tmp = search(str,i);
            if(tmp.size() != 0)
            {
                for(int i = tmp.size() - 1; i >= 0; i--)
                    dfs(str,tmp[i],len,ans);
                return;
            }
            len++;//未识别字符数 + 1
        }

        ans = min(len,ans);
    }

    //字典树 +动态规划
    int respace(vector<string>& dictionary, string sentence) {
        for(auto& word : dictionary)
            insert(word);
        
        int len = sentence.size();
        vector<int> dp(len+1,0);

        for(int i = 1; i <= len; i++)
        {
            dp[i] = dp[i-1] + 1;
            int p = 0;
            for(int j = i; j >= 1; j--)
            {
                int v = sentence[j - 1] - 'a';
                if(son[p][v] == 0)
                {
                    dp[i] = min(dp[i],dp[j-1] + i-j+1);
                    break;
                }
                p = son[p][v];
                //son[p][v] == 1
                if(key[p] == true)//是可以匹配的最后一个单词
                    dp[i] = min(dp[i],dp[j-1]);
                else
                    dp[i] = min(dp[i],dp[j-1] + i - j + 1);
            }
        }
        return dp[len];
    }

    vector<int> search(string& str,int index)
    {
        int p = 0;
        vector<int> ret;
        for(int i = index; i < str.size(); i++)
        {
            int v = str[i] - 'a';
            if(son[p][v] == 0)  break;
            p = son[p][v];
            if(key[p] == true) ret.push_back(i+1);//返回以 index 单词开头，以 i 单词结尾的下一从查询位置
        }
        
        return ret;
    }

    void insert(string& str)
    {
        int p = 0;
        for(int i = str.size() - 1; i >= 0; i--)
        {
            int v = str[i] - 'a';
            if(son[p][v] == 0)  son[p][v] = ++idx;
            p = son[p][v];
        }
        key[p] = true;
    }

    //动态规划
    int respace2(vector<string>& dictionary, string sentence)
    {
        unordered_set<string> set(dictionary.begin(),dictionary.end());
        int len = sentence.size();
        vector<int> dp(len + 1,0);

        for(int i = 1; i <= len; i++)
        {
            dp[i] = dp[i-1] + 1;//假设当前字符不在字典中
            for(int j = 0; j < i; j++)
                if(set.find(sentence.substr(j,i-j)) != set.end())
                    dp[i] = min(dp[i],dp[j]);
        }
        return dp[len];
    }
};
