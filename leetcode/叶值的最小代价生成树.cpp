class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int dp[n][n];
        int f[n][n];
        memset(dp,0x00,sizeof dp);
        memset(f,0x00,sizeof f);

        // f[i][j] 表示 arr 从 [i,j] 的子树中，最大值为f[i][j]
        // dp[i][j] 表示 arr 从 [i,j] 的子树中，非叶节点的最小值
        for(int i = 0; i < n; i++) {
            f[i][i] = arr[i];
            for(int j = i + 1; j < n; j++) f[i][j] = max(f[i][j-1],arr[j]),dp[i][j] = 0x3f3f3f3f;
        }

        for(int len = 1; len < n; len ++) // 左右子树的长度，0不需要考虑，最小为1
            for(int i = 0; i < n - len; i++) {
                int j = i + len;
                // dp[i][j] = 左边非叶子节点的和，右边非叶子节点的和，已经当前根节点的值
                for(int k = i; k < j; k++) 
                    dp[i][j] = min(dp[i][j],f[i][k] * f[k+1][j] + dp[i][k]+ dp[k+1][j]);
            }
        return dp[0][n-1];
    }
};

给你一个正整数数组?arr，考虑所有满足以下条件的二叉树：

每个节点都有 0 个或是 2 个子节点。
数组?arr?中的值与树的中序遍历中每个叶节点的值一一对应。（知识回顾：如果一个节点有 0 个子节点，那么该节点为叶节点。）
每个非叶节点的值等于其左子树和右子树中叶节点的最大值的乘积。
在所有这样的二叉树中，返回每个非叶节点的值的最小可能总和。这个和的值是一个?32 位整数。

?

示例：

输入：arr = [6,2,4]
输出：32
解释：
有两种可能的树，第一种的非叶节点的总和为 36，第二种非叶节点的总和为 32。

    24            24
   /  \          /  \
  12   4        6    8
 /  \               / \
6    2             2   4
?

提示：

2 <= arr.length <= 40
1 <= arr[i] <= 15
答案保证是一个 32 位带符号整数，即小于?2^31。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-cost-tree-from-leaf-values
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
