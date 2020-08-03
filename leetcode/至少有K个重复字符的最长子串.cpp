找到给定字符串（由小写字符组成）中的最长子串 T ，?要求?T?中的每一字符出现次数都不少于 k 。输出 T?的长度。

示例 1:

输入:
s = "aaabb", k = 3

输出:
3

最长子串为 "aaa" ，其中 'a' 重复了 3 次。
示例 2:

输入:
s = "ababbc", k = 2

输出:
5

最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
class Solution {
public:
    int longestSubstring(string s, int k) {
        if(k <= 1)  return s.size();
        if(s.empty() || s.size() < k)   return 0;

        vector<int> arr(26,0);
        for(auto& ch : s)
            arr[ch-'a']++;
        
        int p = 0;
        while(p < s.size() && arr[s[p] - 'a'] >= k)  p++;
        //s  全部符合情况
        if(p == s.size())   return s.size();

        int left = longestSubstring(s.substr(0,p),k);
        while(p < s.size() && arr[s[p] - 'a'] < k) p++;
        int right = longestSubstring(s.substr(p),k);

        return max(right,left);
    }
};
