//给定两个单词（beginWord?和 endWord）和一个字典，找到从?beginWord 到?endWord 的最短转换序列的长度。转换需遵循如下规则：

//每次转换只能改变一个字母。
//转换过程中的中间单词必须是字典中的单词。
//说明:

//如果不存在这样的转换序列，返回 0。
//所有单词具有相同的长度。
//所有单词只由小写字母组成。
//字典中不存在重复的单词。
//你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
//示例?1:

//输入:
//beginWord = "hit",
//endWord = "cog",
//wordList = ["hot","dot","dog","lot","log","cog"]

//输出: 5

//解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//     返回它的长度 5。
//示例 2:

//输入:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log"]

//输出:?0

//解释:?endWord "cog" 不在字典中，所以无法进行转换。


class Solution {
public:
    const static int N = 100010;
    int son[N][26];
    string key[N];
    int idx;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> map_begin;
        //插入字典树中
        for(auto& eoch : wordList)
        {
            insert(eoch);
            map_begin[eoch] = 0;
            //map_end[eoch] = 0;
        }
        insert(beginWord);
        //endword必须在字典中
        if(!Search(endWord)) return 0;
        
        int ans = 1;
        queue<string> que;
        que.push(beginWord);
        map_begin[beginWord] = 1;

        while(!que.empty())
        {
            int size = que.size();

            for(int i = 0; i < size; i++)
            {
                string str = que.front();
                que.pop();

                //找到该字符串一步可以变到的所有字符串
                vector<string> cur;
                Search_neighbors(str,cur);

                for(auto& eoch : cur)
                {
                    if(eoch == endWord)
                        return ans+1;
                    //防止该字符串构成回路
                    if(map_begin[eoch]) continue;
                    //cout<<eoch<<' ';
                    map_begin[eoch] = 1;
                    que.push(eoch);
                }
                //cout<<endl;
            }
            ans++;
        }

        return 0;
    }

    //插入字符串到字典树中
    void insert(string& str)
    {
        int p = 0;
        for(int i = 0; i < str.size(); i++)
        {
            int u = str[i] - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        key[p] = str;
    }

    //从根节点的位置查找指定字符串
    bool Search(string& str,int p = 0)
    {
        for(int i = 0; i < str.size(); i++)
        {
            int u = str[i] - 'a';
            if(!son[p][u]) return false;
            p = son[p][u];    
        }
        return true;
    }

    void Search_neighbors(string& str,vector<string>& arr)
    {
        int p = 0;
        for(int i = 0; i < str.size(); i++)
        {
            for(char ch = 'a'; ch <= 'z'; ch++)
            {
                //如果改变当前i位置为ch 后，节点位置没有该字符 或者说改变后的字符串不能匹配，就继续下一个
                if(ch == str[i] || !son[p][ch-'a']) continue;
                string right = str.substr(i+1);
                if(!Search(right,son[p][ch-'a'])) continue;

                //这里的字符串都是改变后匹配的
                string tmp = str;
                tmp[i] = ch;
                arr.push_back(tmp);
            }
            //更新下一次根节点的位置
            p = son[p][str[i]-'a'];
        }
    }
};
