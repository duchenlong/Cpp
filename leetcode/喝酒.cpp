class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回牛牛能喝的最多的酒
     * @param m int整型 酒单价
     * @param n int整型 牛牛的现金
     * @return int整型
     */
    int countWine(int m, int n) {
        // write code here
        
        int ans = n / m;
        int p1 = ans;
        int p2 = ans;
        
        while(p1 >= 2 || p2 >= 4) {
            int sum = p1 / 2 + p2 / 4;
            ans += sum;
            p1 = sum + p1 % 2;
            p2 = sum + p2 % 4;
        }
        
        return ans;
    }
};

链接：https://ac.nowcoder.com/acm/problem/212807
来源：牛客网

牛牛是一个酒鬼，非常爱喝酒，一瓶酒m元钱，两个酒瓶可以换一瓶酒，四个瓶盖可以换一瓶酒，现在有 n 元钱，求最多可以喝多少瓶酒？
（注：没有借贷功能，即最终不允许借一瓶酒、喝完后拿酒瓶兑换归还的操作）
示例1
输入
复制
2,12
返回值
复制
19
说明
牛牛总计可以喝19瓶酒
备注:
0 < m < 100
0 < n < 2000
