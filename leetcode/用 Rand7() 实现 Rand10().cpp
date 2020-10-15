// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7


// a	1	2	3	4	5	6	7
// b								
// 1	2	3	4	5	6	7	8
// 2	3	4	5	6	7	8	9
// 3	4	5	6	7	8	9	0
// 4	5	6	7	8	9	0	1
// 5	6	7	8	9	0	1	2
// 6	7	8	9	0	1	2	3
// 7	8	9	0	1	2	3	4
// 去掉右上角的  
// 6	7	8
// 7	8	9
// 8	9	0      后

class Solution {
public:
    int rand10() {
        int a = rand7();
        int b = rand7();

        while(a >= 5 && b <= 3) {
            a = rand7();
            b = rand7();
        }

        int ans = (a+b) % 10;
        return  ans == 0 ? 10 : ans;
    }
};
已有方法?rand7?可生成 1 到 7 范围内的均匀随机整数，试写一个方法?rand10?生成 1 到 10 范围内的均匀随机整数。

不要使用系统的?Math.random()?方法。

?

示例 1:

输入: 1
输出: [7]
示例 2:

输入: 2
输出: [8,4]
示例 3:

输入: 3
输出: [8,1,10]
?

提示:

rand7?已定义。
传入参数:?n?表示?rand10?的调用次数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-rand10-using-rand7
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
