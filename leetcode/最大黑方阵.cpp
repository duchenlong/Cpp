class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int col[n+1][n+1];
        int row[n+1][n+1];
        memset(col,0x00,sizeof col);
        memset(row,0x00,sizeof row);

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                col[i][j] = col[i-1][j] + matrix[i-1][j-1];
                row[i][j] = row[i][j-1] + matrix[i-1][j-1];
            }

        int size = 0;
        vector<int> ans;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1) continue;

                int x = i;
                int y = j;  // 右下角坐标
                for(int len = 0; (x < n) && (y < n); len++) {
                    // 横
                    int t1 = row[i+1][y+1] - row[i+1][j+1];
                    int t2 = row[x+1][y+1] - row[x+1][j+1];

                    // 竖
                    int t3 = col[x+1][j+1] - col[i+1][j+1];
                    int t4 = col[x+1][y+1] - col[i+1][y+1];
                    x++,y++;
                    if(t1 + t2 + t3 + t4 != 0) continue;

                    if(len + 1 > size) {
                        ans = {i,j,len + 1};
                        size = len + 1;
                    }
                    
                }
            }
        
        return ans;
    }
};

给定一个方阵，其中每个单元(像素)非黑即白。设计一个算法，找出 4 条边皆为黑色像素的最大子方阵。

返回一个数组 [r, c, size] ，其中?r,?c?分别代表子方阵左上角的行号和列号，size 是子方阵的边长。若有多个满足条件的子方阵，返回 r 最小的，若 r 相同，返回 c 最小的子方阵。若无满足条件的子方阵，返回空数组。

示例 1:

输入:
[
?  [1,0,1],
?  [0,0,1],
?  [0,0,1]
]
输出: [1,0,2]
解释: 输入中 0 代表黑色，1 代表白色，标粗的元素即为满足条件的最大子方阵
示例 2:

输入:
[
?  [0,1,1],
?  [1,0,1],
?  [1,1,0]
]
输出: [0,0,1]
提示：

matrix.length == matrix[0].length <= 200

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-black-square-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
