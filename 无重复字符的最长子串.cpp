//给定一个字符串，请你找出其中不含有重复字符的?最长子串?的长度。

//示例?1:

//输入: "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//示例 2:

//输入: "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//示例 3:

//输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是?"wke"，所以其长度为 3。
//?    请注意，你的答案必须是 子串 的长度，"pwke"?是一个子序列，不是子串。

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0;
        int len = s.size();
        vector<int> ret(256,-1);//记录出现字符的次数
        

        for(int i = 0; i < len; i++) {
            if(ret[s[i]] == -1) 
                ret[s[i]] = i;//保存第一次出现该字符的位置
            else {//前面出现过该字符
                
                //缩小窗口左边界到该字符第一次出现的位置
                while(left <= ret[s[i]]) 
                    ret[s[left++]] = -1;//把中间出现的字符清空
                
                //此时s[i]对应的次数就是i位置字符出现一次
                ret[s[i]] = i;
            }

            ans = max(i-left+1,ans);
        }
        return ans;
    }
};

