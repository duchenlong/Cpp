你有两个 有序?且数组内元素互不相同的数组?nums1 和?nums2?。

一条?合法路径?定义如下：

选择数组 nums1 或者 nums2 开始遍历（从下标 0 处开始）。
从左到右遍历当前数组。
如果你遇到了 nums1?和 nums2?中都存在的值，那么你可以切换路径到另一个数组对应数字处继续遍历（但在合法路径中重复数字只会被统计一次）。
得分定义为合法路径中不同数字的和。

请你返回所有可能合法路径中的最大得分。

由于答案可能很大，请你将它对 10^9 + 7 取余后返回。

?

示例 1：



输入：nums1 = [2,4,5,8,10], nums2 = [4,6,8,9]
输出：30
解释：合法路径包括：
[2,4,5,8,10], [2,4,5,8,9], [2,4,6,8,9], [2,4,6,8,10],（从 nums1 开始遍历）
[4,6,8,9], [4,5,8,10], [4,5,8,9], [4,6,8,10]  （从 nums2 开始遍历）
最大得分为上图中的绿色路径 [2,4,6,8,10]?。
示例 2：

输入：nums1 = [1,3,5,7,9], nums2 = [3,5,100]
输出：109
解释：最大得分由路径 [1,3,5,100] 得到。
示例 3：

输入：nums1 = [1,2,3,4,5], nums2 = [6,7,8,9,10]
输出：40
解释：nums1 和 nums2 之间无相同数字。
最大得分由路径 [6,7,8,9,10] 得到。
示例 4：

输入：nums1 = [1,4,5,8,9,11,19], nums2 = [2,3,4,11,12]
输出：61
?

提示：

1 <= nums1.length <= 10^5
1 <= nums2.length <= 10^5
1 <= nums1[i], nums2[i] <= 10^7
nums1 和?nums2?都是严格递增的数组。


class Solution {
public:
    const int mod = 1e9+7;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        long long res1 = 0;
        long long res2 = 0;
        int l = 0;
        int r = 0;

        while(l < n || r < m)
        {
            if(l == n)
                res2 += nums2[r++];
            else if(r == m)
                res1 += nums1[l++];
            else if(l < n && r < m)
            {
                //+的时候不可以取模
                if(nums1[l] < nums2[r])
                    res1 += nums1[l++];
                else if(nums1[l] > nums2[r])
                    res2 += nums2[r++];
                else if(nums1[l] == nums2[r])
                {
                    res1 = max(res1+nums1[l],res2+nums2[r]);
                    res2 = res1;
                    l++;
                    r++;
                }
            }
        }

        return max(res1,res2) % mod;
    }
};
