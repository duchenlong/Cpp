//给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换?k?次。在执行上述操作后，找到包含重复字母的最长子串的长度。

//注意:
//字符串长度 和 k 不会超过?104。

//示例 1:

//输入:
//s = "ABAB", k = 2

//输出:
//4

//解释:
//用两个'A'替换为两个'B',反之亦然。
//示例 2:

//输入:
//s = "AABABBA", k = 1

//输出:
//4

//解释:
//将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
//子串 "BBBB" 有最长重复字母, 答案为 4。


class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> arr(26,0);
        int left = 0;//窗口的左边界
        int ans = 0;//最长窗口的长度
        int maxCh = 0;//当前窗口出现次数最多的字符数

        for(int i = 0; i < s.size(); i++) {
            arr[s[i] - 'A']++;
            maxCh = max(maxCh, arr[s[i] - 'A']);
            //如果当前窗口中需要改动的字符数：i - left + 1 - maxCh  超过了 k
            //缩小窗口的范围 ， left++
            if(i - left + 1 - maxCh > k)  arr[s[left++] - 'A']--;
            ans = max(ans,i - left + 1);
        }
        return ans;
    }
};
