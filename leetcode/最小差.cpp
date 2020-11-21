class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        long ans = INT_MAX;
        int le = 0, ri = 0;
        int n = a.size(), m = b.size();
        while(le < n && ri < m) {
            long num = abs(abs(a[le]) - abs(b[ri]));
            ans = min(num,ans);

            if(le == n - 1) ri++;
            else if(ri == m - 1) le++;
            else if(a[le] > b[ri]) ri++;
            else le++;
        }

        return ans;
    }
};

给定两个整数数组a和b，计算具有最小差绝对值的一对数值（每个数组中取一个值），并返回该对数值的差

示例：

输入：{1, 3, 15, 11, 2}, {23, 127, 235, 19, 8}
输出： 3，即数值对(11, 8)
提示：

1 <= a.length, b.length <= 100000
-2147483648 <= a[i], b[i] <= 2147483647
正确结果在区间[-2147483648, 2147483647]内

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-difference-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
