//一条包含字母?A-Z 的消息通过以下方式进行了编码：

//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//给定一个只包含数字的非空字符串，请计算解码方法的总数。

//示例 1:

class Solution {
public:
    int ans;
    int len;
    int numDecodings(string s) {
        ans = 0;
        len = s.size();
        //dfs(s,0);
        vector<int> dp(len,0);//表示以i位置的字符结束时的最多匹配方式
        dp[0] = s[0]=='0'?0:1;
        for(int i = 1; i < len; i++)
        {
            char n = s[i];
            char left = s[i-1];
            int num = (left-'0')* 10 + n-'0';
            if(n != '0') dp[i] += dp[i-1];//0不能是单独一个字符

            if(left == '1' || (left=='2' && n<='6'))
                if(i >= 2) dp[i] += dp[i-2];
                else dp[i]++;
        }
        return dp[len-1];
    }
    //深搜超时
    void dfs(string& s,int index)
    {
        if(s[index] == '0')
            return;
        if(index >= len)
        {
            ans++;
            return;
        }

        //选择一位
        dfs(s,index+1);

        if(index+1 >= len) return;
        //选择两位
        int num = (s[index]-'0')* 10 + s[index+1]-'0';
        if(num >=1 && num<=26)
            dfs(s,index+2);
    }
};
