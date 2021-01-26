class Solution {
public:
    int kthLargestValue(vector<vector<int>>& ma, int k) {
        int n = ma.size(), m = ma[0].size();
        vector<vector<int> > f(n+1,vector<int> (m + 1, 0));
        priority_queue<int> pq;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                f[i][j] = ma[i-1][j-1] ^ f[i-1][j-1] ^ f[i][j-1] ^ f[i-1][j];
                pq.push(f[i][j]);
            }
        }
        
        
        int res = 0;
        while(k --) {
            res= pq.top();
            pq.pop();
        }
        return res;
    }
};


给你一个二维矩阵 matrix 和一个整数 k ，矩阵大小为?m x n 由非负整数组成。

矩阵中坐标 (a, b) 的 值 可由对所有满足 0 <= i <= a < m 且 0 <= j <= b < n 的元素 matrix[i][j]（下标从 0 开始计数）执行异或运算得到。

请你找出?matrix 的所有坐标中第 k 大的值（k 的值从 1 开始计数）。

?

示例 1：

输入：matrix = [[5,2],[1,6]], k = 1
输出：7
解释：坐标 (0,1) 的值是 5 XOR 2 = 7 ，为最大的值。
示例 2：

输入：matrix = [[5,2],[1,6]], k = 2
输出：5
解释：坐标 (0,0) 的值是 5 = 5 ，为第 2 大的值。
示例 3：

输入：matrix = [[5,2],[1,6]], k = 3
输出：4
解释：坐标 (1,0) 的值是 5 XOR 1 = 4 ，为第 3 大的值。
示例 4：

输入：matrix = [[5,2],[1,6]], k = 4
输出：0
解释：坐标 (1,1) 的值是 5 XOR 2 XOR 1 XOR 6 = 0 ，为第 4 大的值。
?

提示：

m == matrix.length
n == matrix[i].length
1 <= m, n <= 1000
0 <= matrix[i][j] <= 106
1 <= k <= m * n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-kth-largest-xor-coordinate-value
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
