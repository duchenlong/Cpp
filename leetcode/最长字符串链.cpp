class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        int dp[n + 1];
        memset(dp,0x00,sizeof dp);

        sort(words.begin(),words.end(),[](const string& a,const string& b)->bool{
            return a.size() < b.size();
        });
        unordered_map<string,int> hash;

        int ans = 0;
        for(int i = 0; i < n; i++) {
            hash[words[i]] = i;
            dp[i] = 1;

            string word = words[i];
            int m = word.size();
            if(m == 1) continue;

            for(int j = 0; j < m; j++) {
                string tmp = word.substr(0,j) + word.substr(j+1);
                if(hash.count(tmp)) dp[i] = max(dp[i], dp[hash[tmp]] + 1);
            }

            ans = max(ans,dp[i]);
        }

        return ans;
    }
};


给出一个单词列表，其中每个单词都由小写英文字母组成。

如果我们可以在?word1?的任何地方添加一个字母使其变成?word2，那么我们认为?word1?是?word2?的前身。例如，"abc"?是?"abac"?的前身。

词链是单词?[word_1, word_2, ..., word_k]?组成的序列，k >= 1，其中?word_1?是?word_2?的前身，word_2?是?word_3?的前身，依此类推。

从给定单词列表 words 中选择单词组成词链，返回词链的最长可能长度。
?

示例：

输入：["a","b","ba","bca","bda","bdca"]
输出：4
解释：最长单词链之一为 "a","ba","bda","bdca"。
?

提示：

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i]?仅由小写英文字母组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-string-chain
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
