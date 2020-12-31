class Solution {
public:
    typedef long long LL;
    vector<int> findClosedNumbers(int num) {
        if(num == 1) return {2,-1};
        if(num == 2147483647) return {-1,-1};

        int MAX = nextMax(num);
        if(MAX < 0) MAX = -1;
        int MIN = ~nextMax(~num);
        return {MAX,MIN};
    }

    int nextMax(LL num) {
        LL x = num & -num;      // 找到最后一个1的位置
        LL y = x + num;         // 清除左侧连续的1

        // num & ~y 左侧连续的1组成的数
        // /x  清除后面的0
        // >> 1 
        return y | ((num & ~y) / x) >> 1;
    }
};


下一个数。给定一个正整数，找出与其二进制表达式中1的个数相同且大小最接近的那两个数（一个略大，一个略小）。

示例1:

 输入：num = 2（或者0b10）
 输出：[4, 1] 或者（[0b100, 0b1]）
示例2:

 输入：num = 1
 输出：[2, -1]
提示:

num的范围在[1, 2147483647]之间；
如果找不到前一个或者后一个满足条件的正数，那么输出 -1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/closed-number-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
