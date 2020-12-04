class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> idx(3,0);
        vector<int> f(n,1);

        for(int i = 1; i < n; i++) {
            int a = f[idx[0]] * 2, b = f[idx[1]] * 3, c = f[idx[2]] * 5;
            int next = min(a,min(c,b));

            if(next == a)    idx[0]++;
            if(next == b)    idx[1]++;
            if(next == c)    idx[2]++;
            f[i] = next;
        }
        return f[n - 1];
    }
};

我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

?

示例:

输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:??

1?是丑数。
n?不超过1690。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/chou-shu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
