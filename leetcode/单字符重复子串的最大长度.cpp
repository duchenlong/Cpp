如果字符串中的所有字符都相同，那么这个字符串是单字符重复的字符串。

给你一个字符串?text，你只能交换其中两个字符一次或者什么都不做，然后得到一些单字符重复的子串。返回其中最长的子串的长度。

?

示例 1：

输入：text = "ababa"
输出：3
示例 2：

输入：text = "aaabaaa"
输出：6
示例 3：

输入：text = "aaabbaaa"
输出：4
示例 4：

输入：text = "aaaaa"
输出：5
示例 5：

输入：text = "abcdef"
输出：1
?

提示：

1 <= text.length <= 20000
text 仅由小写英文字母组成。


class Solution {
public:
    int maxRepOpt1(string text) {
        vector<pair<int,int> > rec;
        for(auto& ch : text)
            if(rec.empty() || rec.back().first != ch - 'a')
                rec.push_back({ch - 'a',1});
            else
                rec.back().second++;
        
        int len = rec.size();
        vector<int> cnt(26,0);
        for(int i = 0; i < len; i++)
            cnt[rec[i].first]++;
        
        int ans = 0;
        for(int i = 0; i < len; i++)
        {
            if(i > 0 && i < len-1 && rec[i].second == 1
                && rec[i-1].first == rec[i+1].first)
            {
                //...aaaabaaaa...
                int tmp = rec[i-1].second + rec[i+1].second;
                //...aaaabaaaa...a...
                if(cnt[rec[i-1].first] > 2) tmp++;
                ans = max(ans,tmp);
            }

            //...aaaa...a...
            ans = max(ans,rec[i].second + (cnt[rec[i].first] > 1));
        }

        return ans;
    }
};
