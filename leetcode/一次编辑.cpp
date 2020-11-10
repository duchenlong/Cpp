class Solution {
public:
    bool oneEditAway(string first, string second) {
        int n = first.size();
        int m = second.size();
        int t = n - m;
        if(abs(t) > 1) return false;

        // 线性做法
        int cnt = 1;
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(first[i] == second[j]) i++,j++;
            else {
                if(t == 1) i++;     // second 添加一个字符
                else if(t == -1) j++;   // second 删除一个字符
                else if(t == 0) i++,j++;    // second 替换一个字符
                cnt--;
                if(cnt < 0) return false;
            }
        }
        return true;

        // int f[n+1][m+1];
        // memset(f,0x00,sizeof f);
        // for(int i = 0; i <= n; i++) f[i][0] = i;
        // for(int j = 0; j <= m; j++) f[0][j] = j;

        // for(int i = 1; i <= n; i++)
        //     for(int j = 1; j <= m; j++) {
        //         if(first[i - 1] == second[j - 1]) f[i][j] = f[i-1][j-1];
        //         else f[i][j] = min(min(f[i-1][j],f[i][j-1]),f[i-1][j-1]) + 1;
        //     }
        // return f[n][m] <= 1;
    }
};


字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

?

示例?1:

输入: 
first = "pale"
second = "ple"
输出: True
?

示例?2:

输入: 
first = "pales"
second = "pal"
输出: False

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/one-away-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
