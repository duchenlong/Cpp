class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> f(255,0);
        for(auto& e : s1) f[e] ++;
        int le = 0;
        for(int i = 0; i < s2.size(); i++) {
            f[s2[i]] --;
            while(le <= i && f[s2[i]] < 0)
                f[s2[le ++]] ++;
            if(i - le + 1 == s1.size()) return true;
        }
        return false;
    }
};


给定两个字符串?s1?和?s2，写一个函数来判断 s2 是否包含 s1?的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
?

示例2:

输入: s1= "ab" s2 = "eidboaoo"
输出: False
?

注意：

输入的字符串只包含小写字母
两个字符串的长度都在 [1, 10,000] 之间

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
