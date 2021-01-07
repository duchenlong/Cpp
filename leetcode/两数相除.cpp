class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1) return dividend;
        if(divisor == -1) {
            if(dividend != INT_MIN) return -dividend;
            return INT_MAX;     // 变为 int 型数据的最大值
        }
        if(dividend == divisor) return 1;
        if(divisor == INT_MIN) return 0;
        int res = 0;
        // 最后结果的符号
        bool flag = (dividend > 0) ^ (divisor > 0);
        // 排除 INT_MIN 转为 INT_MAX 后，将负数转为正数
        divisor = abs(divisor);
        if(dividend == INT_MIN) {
            res++;
            dividend += divisor;
        }
        dividend = abs(dividend);   

        while(dividend >= divisor) {
            int tmp = divisor;
            int cnt = 1;

            // INT_MAX = 2147483647 防止左移越界
            while(tmp < (INT_MAX >> 2) && (tmp << 1) <= dividend) {
                tmp <<= 1;
                cnt <<= 1;
            }

            res += cnt;
            dividend -= tmp;
        }

        return flag ? -res : res;
    }
};

给定两个整数，被除数?dividend?和除数?divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数?dividend?除以除数?divisor?得到的商。

整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2

?

示例?1:

输入: dividend = 10, divisor = 3
输出: 3
解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
示例?2:

输入: dividend = 7, divisor = -3
输出: -2
解释: 7/-3 = truncate(-2.33333..) = -2
?

提示：

被除数和除数均为 32 位有符号整数。
除数不为?0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [?231,? 231?? 1]。本题中，如果除法结果溢出，则返回 231?? 1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
