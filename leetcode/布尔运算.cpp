class Solution {
public:
    int calc(int x,int y,char op) {
        if(op == '|') return x | y;
        if(op == '&') return x & y;
        return x ^ y;
    }

    int countEval(string s, int result) {
        int n = s.size() / 2 + 1;
        vector<int> num(n), op(n-1);    // n个数字，n-1个操作符
        for(int i = 0; i < n; i++) {
            num[i] = s[i * 2] - '0';
            if(i != n - 1)
                op[i] = s[i * 2 + 1];
        }
        // i位置的操作符，操作的数字区间为  [ , i] [i + 1, ]

        int dp[n+1][n+1][3];
        memset(dp,0x00,sizeof dp);
        for(int i = 0; i < n; i++)
            dp[i][i][num[i]] = 1;      // 初始化每个位置是 0,1的方案数
        
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i + len - 1 < n; i++) {
                for(int j = i; j < i + len - 1; j++) {

                    // 数字划分为两个区间 [i, j] [j + 1, i + len -1]
                    // 两个区间中间的操作符位置 op[j]
                    for(int x = 0; x <= 1; x++)
                        for(int y = 0; y <= 1; y++)
                            dp[i][i + len - 1][calc(x,y,op[j])] += dp[i][j][x] * dp[j + 1][i + len - 1][y];
                }
            }
        }

        return dp[0][n-1][result];
    }


};

给定一个布尔表达式和一个期望的布尔结果 result，布尔表达式由 0 (false)、1 (true)、& (AND)、 | (OR) 和 ^ (XOR) 符号组成。实现一个函数，算出有几种可使该表达式得出 result 值的括号方法。

示例 1:

输入: s = "1^0|0|1", result = 0

输出: 2
解释:?两种可能的括号方法是
1^(0|(0|1))
1^((0|0)|1)
示例 2:

输入: s = "0&0&0&1^1|0", result = 1

输出: 10
提示：

运算符的数量不超过 19 个

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/boolean-evaluation-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
