给定一个单词数组和一个长度?maxWidth，重新排版单词，使其成为每行恰好有?maxWidth?个字符，且左右两端对齐的文本。

你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格?' '?填充，使得每行恰好有 maxWidth?个字符。

要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。

文本的最后一行应为左对齐，且单词之间不插入额外的空格。

说明:

单词是指由非空格字符组成的字符序列。
每个单词的长度大于 0，小于等于?maxWidth。
输入单词数组 words?至少包含一个单词。
示例:

输入:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
输出:
[
? ?"This ? ?is ? ?an",
? ?"example ?of text",
? ?"justification. ?"
]
示例?2:

输入:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
输出:
[
? "What ? must ? be",
? "acknowledgment ?",
? "shall be ? ? ? ?"
]
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
?    因为最后一行应为左对齐，而不是左右两端对齐。       
     第二行同样为左对齐，这是因为这行只包含一个单词。
示例?3:

输入:
words = ["Science","is","what","we","understand","well","enough","to","explain",
?        "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
输出:
[
? "Science ?is ?what we",
  "understand ? ? ?well",
? "enough to explain to",
? "a ?computer. ?Art is",
? "everything ?else ?we",
? "do ? ? ? ? ? ? ? ? ?"
]


class Solution {
public:
    int curLen = 0;
    int wordLen = 0;
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        int pre = 0;
        for(int i = 0; i < words.size(); i++)
        {
            if(curLen + words[i].size() <= maxWidth)
            {
                curLen += words[i].size() + 1;//1 和下一个单词中间最少的一个空格
                wordLen += words[i].size();
                if(i == words.size() - 1)
                {
                    string str("");
                    for(int j = pre; j <= i; j++)
                    {
                        str += words[j];
                        if(str.size() < maxWidth)
                            str += " ";
                    }
                    Space(str,maxWidth - str.size());
                    ans.push_back(str);
                    break;
                }

                continue;
            }

            Add(ans,words,i,pre,maxWidth);

            //当前单词属于下一行
            pre = i;
            curLen = 0;
            wordLen = 0;
            i--;
        }

        return ans;
    }

    void Add(vector<string>& ans,vector<string>& words, int i,int pre,int maxWidth)
    {
        //这里就说明已经凑够了一行单词,添加从 pre 到 i中间的单词，不包括 i 
        string str = "";
        //防止只有一个单词的情况
        if(i - pre == 1)
        {
            str = words[pre];
            Space(str,maxWidth - str.size());
            ans.push_back(str);
            return;
        }
            
        //i - pre 个单词  i - pre - 1 个间隔
        int avl = (maxWidth - wordLen) / (i - pre - 1);
        //记录平均分之后剩余的空格数量 sum 一定小于 间隔数
        int sum = maxWidth - wordLen - (i - pre - 1) * avl;

        for(int j = pre; j < i; j++)
        {
            str += words[j];
            //剩余的空格数量，在从左向右每个单词的后面再加一个
            int sp = avl + (sum > 0 ? 1 : 0);
            sum--;
            //最后一个单词后面不用添加空格
            if(j != i -1)
                Space(str,sp);
        }
        
        ans.push_back(str);
    }

    void Space(string& str,int num)
    {
        for(int i = 0; i < num; i++)
            str += " ";
    }
};
