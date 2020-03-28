//给定一个单词列表，我们将这个列表编码成一个索引字符串?S?与一个索引列表 A。

//例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。

//对于每一个索引，我们可以通过从字符串 S?中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。

//那么成功对给定单词列表进行编码的最小字符串长度是多少呢？

//?

//示例：

//输入: words = ["time", "me", "bell"]
//输出: 10
//说明: S = "time#bell#" ， indexes = [0, 2, 5] 。




class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        int num = words.size();//求出单词的数量

        //翻转每一个单词
        vector<string> reversed_words;
        for(string word : words)
        {
            reverse(word.begin(),word.end());//翻转单词
            reversed_words.push_back(word);     //添加到新的数组中
        }

        //按照字典序进行排序
        sort(reversed_words.begin(),reversed_words.end());

        int ret = 0;
        for(int i = 0; i < num; i++)
        {
            //如果存在下一个单词，并且下一个单词是这个单词的前缀，直接舍去
            if(i + 1 < num && reversed_words[i+1].find(reversed_words[i]) == 0)
                continue;
            
            //不是前缀，说明当前单词已经最小，计算长度了
            ret += reversed_words[i].length() + 1;
        }

        return ret;
    }
};
