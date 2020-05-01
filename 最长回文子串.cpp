//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设?s 的最大长度为 1000。

//示例 1：

//输入: "babad"
//输出: "bab"
//注意: "aba" 也是一个有效答案。
//示例 2：

//输入: "cbbd"
//输出: "bb"



class Solution {
public:
    //动态规划 O(n * n)
    string longestPalindrome1(string s) {
        int len = s.size();
        //dp[i][j] 表示从i到j是否可以构成回文字符串
        vector<vector<bool>> dp(len,vector<bool>(len,false));
        //初始化一个字符的位置，他们都是回文字符串
        for(int i = 0; i < len; i++)
            dp[i][i] = true;

        //最终回文字符串的起始位置
        int start = 0;
        int end = 0;

        for(int j = 1; j < len; j++)
            for(int i = 0; i < j; i++) {
                if(s[i] == s[j]) {
                    //aba  aa  a   如果长度为小于三，并且存在两端字符串相等，一定可以构成回文
                    if(j - i < 3)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i+1][j-1];//判断他的子串是否是回文的
                }
                else {
                    dp[i][j] = false;//缩小范围
                }
                    
                //如果dp[i][j]是true ，表示是回文字符串
                //并且长度比记录的长度大时，记录起始位置
                if( dp[i][j] && ((end - start + 1) < (j - i + 1)) ) {
                    start = i;
                    end = j;
                }
            }
        
        return s.substr(start,end - start + 1);
    }
    //中心扩散  时间复杂度O(N * N) --> 最坏的情况全部都是一样的字符
    string longestPalindrome(string s) {
        int len = s.size();
        if(len < 2) return s;
        vector<int> ans(2,0);//保存回文子串的开始位置和长度
        ans[0] = 0;
        ans[1] = 1;
        for(int i = 0; i < len; i++) 
            i = FindLongest(s,i,ans,len);
        return s.substr(ans[0],ans[1]);
    }

    int FindLongest(string s, int left, vector<int>& ans,int len) {
        int right = left;
        //确定中间部分的位置，判断是 aa型  还是aba型
        while(right < len-1 && s[right+1] == s[left])
            right++;
        
        //定位中间位置最后一个字符
        int end = right;
        while(left > 0 && right < len-1 && s[left-1] == s[right+1]) {
            left--;
            right++;
        }
        int now = right - left + 1;
        if(now > ans[1]) {
            ans[0] = left;
            ans[1] = now;
        }
        return end;
    }
};
