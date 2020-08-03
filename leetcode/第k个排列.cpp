给出集合?[1,2,3,…,n]，其所有元素共有?n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当?n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定?n 和?k，返回第?k?个排列。

说明：

给定 n?的范围是 [1, 9]。
给定 k?的范围是[1, ?n!]。
示例?1:

输入: n = 3, k = 3
输出: "213"
示例?2:

输入: n = 4, k = 9
输出: "2314"


class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factor(n+1,1);
        deque<char> vis(n+1,'0');
        int sum = 1;
        for(int i = 1; i <= n; i++)
        {
            vis[i] = '0' + i;
            sum *= i;
            factor[i] = sum;
        }

        string ans("");
        k--;
        for(int i = n-1; i >= 0; i--)
        {
            int p = k / factor[i];
            ans += vis[p+1];
            vis.erase(vis.begin()+p+1);
            k -= p * factor[i];
        }

        return ans;
    }
};
