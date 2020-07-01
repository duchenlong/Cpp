给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。

示例 1:

输入：
nums = [1,3,1]
k = 1
输出：0 
解释：
所有数对如下：
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
因此第 1 个最小距离的数对是 (1,1)，它们之间的距离为 0。
提示:

2 <= len(nums) <= 10000.
0 <= nums[i] < 1000000.
1 <= k <= len(nums) * (len(nums) - 1) / 2.



class Solution {
public:
    int len = 0;
    int smallestDistancePair(vector<int>& nums, int k) {
        len = nums.size();
        sort(nums.begin(),nums.end());
        int left = 0;//最小差值
        int right = nums[len - 1] - nums[0];//最大差值

        while(left < right)
        {
            int mid = (left + right) / 2;
            if(check(nums,mid) >= k)
                right = mid;
            else 
                left = mid + 1;
        }
        return left;
    }
    //寻找nums数组中，比val值小的距离数量
    int check(vector<int>& nums,int val)
    {
        int le = 0;
        int ans = 0;

        for(int i = 0; i < len; i++)
        {
            while(nums[i] - nums[le] > val) le++;
            ans += i - le;//i 一定大于 le,nums为有序数组
        }
        return ans;
    }
};
