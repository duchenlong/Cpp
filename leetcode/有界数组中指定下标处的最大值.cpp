class Solution {
public:
    typedef long long LL;
    int maxValue(int n, int index, int maxSum) {
        int le = 1, ri = maxSum;
        while(le < ri) {
            int mid = le + ri + 1 >> 1;
            if(check(mid,n,index,maxSum)) le = mid;
            else ri = mid - 1;
        }
        
        return le;
    }
    
    bool check(LL num,int n, int index, LL maxSum) {
        LL le = index, ri = n - index - 1;
        LL cnt = num - 1;
        LL sum = num;
        
        if(le >= cnt) {
            sum += cnt * (num - 1) - (cnt * (cnt - 1) / 2);
            sum += le - cnt;
        } else {
            sum += le * (num - 1) - (le * (le - 1) / 2);
        }
        
        if(ri >= cnt) {
            sum += cnt * (num - 1) - (cnt * (cnt - 1) / 2);
            sum += ri - cnt;
        } else {
            sum += ri * (num - 1) - (ri * (ri - 1) / 2);
        }
        
        return sum <= maxSum;
    }
};


给你三个正整数 n、index 和 maxSum 。你需要构造一个同时满足下述所有条件的数组 nums（下标 从 0 开始 计数）：

nums.length == n
nums[i] 是 正整数 ，其中 0 <= i < n
abs(nums[i] - nums[i+1]) <= 1 ，其中 0 <= i < n-1
nums 中所有元素之和不超过 maxSum
nums[index] 的值被 最大化
返回你所构造的数组中的 nums[index] 。

注意：abs(x) 等于 x 的前提是 x >= 0 ；否则，abs(x) 等于 -x 。

?

示例 1：

输入：n = 4, index = 2,  maxSum = 6
输出：2
解释：数组 [1,1,2,1] 和 [1,2,2,1] 满足所有条件。不存在其他在指定下标处具有更大值的有效数组。
示例 2：

输入：n = 6, index = 1,  maxSum = 10
输出：3
?

提示：

1 <= n <= maxSum <= 109
0 <= index < n

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-value-at-a-given-index-in-a-bounded-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
