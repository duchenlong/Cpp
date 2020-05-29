//给定一个经过编码的字符串，返回它解码后的字符串。

//编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

//你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

//此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像?3a?或?2[4]?的输入。

//示例:

//s = "3[a]2[bc]", 返回 "aaabcbc".
//s = "3[a2[c]]", 返回 "accaccacc".
//s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".

class Solution {
public:
    
    string decodeString(string s) {
        int len = s.size();
        string ret = "";

        for(int i = 0; i < len; i++)
        {
            if(s[i]<='9' && s[i]>='0')
                ret += dfs(s,len,i); //每一次深搜提取重复的字符串
            else ret += s[i];
        }

        return ret;
    }

    string dfs(string& s, int len, int& i)
    {
        if(i >= len) return "";
        string ret = "";

        while(i < len)
        {
            if(s[i]<='9' && s[i]>='0')
            {
                //提取数字部分，提取之后i的位置是 数字后面 [ 的位置
                int count = ToNum(s,i);
                i++;//跳过这个 [
                string tmp = dfs(s,len,i);
                ret += connect(tmp,count);//负责对重复字符串拼接
            }
            else if(s[i] == ']')
                return ret;
            else 
                ret += s[i];
            
            i++;
        }

        return ret;
    }

    string connect(string& tmp,int count)
    {
        string ret = "";
        for(int i = 0; i < count; i++)
            ret += tmp;
        return ret;
    }

    int ToNum(string& s,int& index)
    {
        int num = 0;
        while(s[index] != '[')
            num = num * 10 + s[index++]-'0';

        return num;
    }
};
