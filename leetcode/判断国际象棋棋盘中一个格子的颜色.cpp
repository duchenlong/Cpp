class Solution {
public:
    bool squareIsWhite(string s) {
        vector<vector<bool> > f(8,vector<bool> (8,false));
        
        for(int i = 0 ; i < 8; i ++) {
            if(i & 1) {
                f[i][0] = true;
            } else {
                f[i][0] = false;
            }
            
            for(int j = 1; j < 8; j++)
                f[i][j] = !f[i][j - 1];
        }
        
        int r = s[0] - 'a', c = s[1] - '1';
        
        return f[r][c];
    }
};


class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (coordinates[0] + coordinates[1]) % 2;
    }
};

给你一个坐标?coordinates?，它是一个字符串，表示国际象棋棋盘中一个格子的坐标。下图是国际象棋棋盘示意图。



如果所给格子的颜色是白色，请你返回?true，如果是黑色，请返回?false?。

给定坐标一定代表国际象棋棋盘上一个存在的格子。坐标第一个字符是字母，第二个字符是数字。

?

示例 1：

输入：coordinates = "a1"
输出：false
解释：如上图棋盘所示，"a1" 坐标的格子是黑色的，所以返回 false 。
示例 2：

输入：coordinates = "h3"
输出：true
解释：如上图棋盘所示，"h3" 坐标的格子是白色的，所以返回 true 。
示例 3：

输入：coordinates = "c7"
输出：false
?

提示：

coordinates.length == 2
'a' <= coordinates[0] <= 'h'
'1' <= coordinates[1] <= '8'

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/determine-color-of-a-chessboard-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
