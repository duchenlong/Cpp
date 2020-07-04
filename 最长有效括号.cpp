给定一个只包含 '('?和 ')'?的字符串，找出最长的包含有效括号的子串的长度。

示例?1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"


class Solution {
public:
    //动态规划
    int longestValidParentheses1(string s) {
        int len = s.size();
        stack<int> st;  //标记前置括号 (
        vector<bool> dp(len,false);

        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
                continue;
            }

            if(s[i] == ')' && st.empty())
                continue;
            
            int p = st.top();
            st.pop();
            dp[p] = true;
            dp[i] = true;
        }

        int ans = 0;
        int left = 0;
        //寻找连续的true长度
        for(int i = 0; i < len; i++)
        {
            if(dp[i] == false)
            {
                left = i + 1;
                continue;
            }
            ans = max(ans,i - left + 1);
        }
        return ans;
    }

    //栈
    int longestValidParentheses(string s)
    {
        int len = s.size();
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
                continue;
            }
            //说明 s[i] 此时是 )
            st.pop();
            if(st.empty())
                st.push(i);
            else
                ans = max(ans,i - st.top());
        }
        return ans;
    }

};
