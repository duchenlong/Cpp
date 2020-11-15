class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n,0);

        for(int i = 0, cur = 1; i < n; i++) {
            ans[i] = cur;
            cur *= a[i];
        }

        for(int i = n - 1, cur = 1; i >= 0; i--) {
            ans[i] *= cur;
            cur *= a[i];
        }

        return ans;
    }
};


给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

?

示例:

输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
?

提示：

所有元素乘积之和不会溢出 32 位整数
a.length <= 100000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
