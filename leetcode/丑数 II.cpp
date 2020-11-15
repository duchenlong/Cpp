class Solution {
public:
    int nthUglyNumber(int n) {
        int f[n],idx[3];
        memset(idx,0x00,sizeof idx);
        for(int i = 0; i < n; i++) f[i] = 1;

        for(int i = 1; i < n; i++) {
            int a = f[idx[0]] * 2, b = f[idx[1]] * 3, c = f[idx[2]] * 5;
            int next = min(a,min(b,c));

            if(next == a) idx[0] ++;
            if(next == b) idx[1] ++;
            if(next == c) idx[2] ++;
            f[i] = next;
        }

        return f[n-1];
    }
};

编写一个程序，找出第 n 个丑数。

丑数就是质因数只包含?2, 3, 5 的正整数。

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:??

1?是丑数。
n?不超过1690。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ugly-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
