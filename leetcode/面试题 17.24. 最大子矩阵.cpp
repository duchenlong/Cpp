class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        int sum[r+1][c+1];
        memset(sum,0x00,sizeof(sum));

        vector<int> ans(4,0);
        int cnt = INT_MIN;

        // 暴力超时 O(n^2 * m^2)
        // for(int i = 0; i < r; i++) 
        //     for(int j = 0; j < c; j++) sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + matrix[i][j];
        // for(int i = 0; i < r; i++)
        //     for(int j = i; j < r; j++)
        //         for(int n = 0; n < c; n++)
        //             for(int m = n; m < c; m++) {
        //                 int num = sum[j+1][m+1] - sum[j+1][n] - sum[i][m+1] + sum[i][n];
        //                 if(num > cnt) {
        //                     cnt = num;
        //                     ans[0] = i;
        //                     ans[1] = n;
        //                     ans[2] = j;
        //                     ans[3] = m;
        //                 }
        //             }

        // ac
        int dp[c];
        for(int i = 0; i < r; i++){
            memset(dp,0x00,sizeof(dp));

            for(int j = i; j < r; j++) {
                int cur = 0;
                int lefedown = i;
                for(int k = 0; k < c; k++) {
                    dp[k] += matrix[j][k];
                    if(cur > 0) cur += dp[k];
                    else {
                        cur = dp[k];
                        lefedown = k;
                    }

                    if(cur > cnt) {
                        cnt = cur;
                        ans[0] = i;
                        ans[1] = lefedown;
                        ans[2] = j;
                        ans[3] = k;
                    }
                }
            }
        }
        
        return ans;
                        
    }
};

给定一个正整数、负整数和 0 组成的 N × M?矩阵，编写代码找出元素总和最大的子矩阵。

返回一个数组 [r1, c1, r2, c2]，其中 r1, c1 分别代表子矩阵左上角的行号和列号，r2, c2 分别代表右下角的行号和列号。若有多个满足条件的子矩阵，返回任意一个均可。

注意：本题相对书上原题稍作改动

示例：

输入：
[
?  [-1,0],
?  [0,-1]
]
输出：[0,1,0,1]
解释：输入中标粗的元素即为输出所表示的矩阵
?

说明：

1 <= matrix.length, matrix[0].length <= 200

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-submatrix-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
