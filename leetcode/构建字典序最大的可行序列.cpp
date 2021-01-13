class Solution {
public:
    int n;
    vector<bool> vis;
    vector<int> res;

    bool dfs(int m) {
        if(m == 2 * n - 1) return true;
        if(res[m]) return dfs(m + 1);

        for(int i = n; i > 1; i--) 
            if(!vis[i] && m + i < 2 * n - 1 && !res[m + i]) {
                res[m] = i; res[i + m] = i;
                vis[i] = true;
                if(dfs(m+1)) return true;
                vis[i] = false;
                res[m] = 0; res[i + m] = 0;
            }
        
        if(!vis[1]) {
            res[m] = 1; vis[1] = true;
            if(dfs(m + 1)) return true;
            res[m] = 0; vis[1] = false;
        }

        return false;
    }

    vector<int> constructDistancedSequence(int _n) {
        n = _n;
        res.resize(2*n-1,0);
        vis.resize(n+1,false);

        dfs(0);

        return res;

    }
};

给你一个整数?n?，请你找到满足下面条件的一个序列：

整数?1?在序列中只出现一次。
2?到?n?之间每个整数都恰好出现两次。
对于每个?2?到?n?之间的整数?i?，两个?i?之间出现的距离恰好为?i?。
序列里面两个数 a[i]?和 a[j]?之间的 距离?，我们定义为它们下标绝对值之差?|j - i|?。

请你返回满足上述条件中?字典序最大?的序列。题目保证在给定限制条件下，一定存在解。

一个序列?a?被认为比序列?b?（两者长度相同）字典序更大的条件是：?a 和?b?中第一个不一样的数字处，a?序列的数字比?b?序列的数字大。比方说，[0,1,9,0]?比?[0,1,5,6]?字典序更大，因为第一个不同的位置是第三个数字，且?9?比?5?大。

?

示例 1：

输入：n = 3
输出：[3,1,2,3,2]
解释：[2,3,2,1,3] 也是一个可行的序列，但是 [3,1,2,3,2] 是字典序最大的序列。
示例 2：

输入：n = 5
输出：[5,3,1,4,3,5,2,4,2]
?

提示：

1 <= n <= 20

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-the-lexicographically-largest-valid-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
