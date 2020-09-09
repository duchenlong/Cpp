给定一个由 4 位数字组成的数组，返回可以设置的符合 24 小时制的最大时间。

最小的 24 小时制时间是?00:00，而最大的是?23:59。从 00:00 （午夜）开始算起，过得越久，时间越大。

以长度为 5 的字符串返回答案。如果不能确定有效时间，则返回空字符串。

?

示例 1：

输入：[1,2,3,4]
输出："23:41"
示例 2：

输入：[5,5,5,5]
输出：""
?

提示：

A.length == 4
0 <= A[i] <= 9


class Solution:
    def largestTimeFromDigits(self, arr: List[int]) -> str:
        arr.sort(reverse=True)
        p = itertools.permutations(arr) #全排列迭代器

        for h1,h2,m1,m2 in p:
            if h1 * 10 + h2 <= 23 and m1 * 10 + m2 <= 59:
                return str(h1) + str(h2) + ":" + str(m1) + str(m2)
        return ""
