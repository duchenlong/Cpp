class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long> sum{0};
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            sum.push_back(sum.back() + nums[i]);
        }

        return merge(sum,lower,upper,0,n);
    }

    int merge(vector<long>& sum,int lower,int upper,int left,int right) {
        if(left == right) return 0;

        int mid = (left + right) / 2;
        int n1 = merge(sum,lower,upper,left,mid);
        int n2 = merge(sum,lower,upper,mid+1,right);
        int ret = n1 + n2;

        int i = left;
        int l = mid + 1;
        int r = mid + 1;
        while(i <= mid) {
            while(l <= right && sum[l] - sum[i] < lower) l++;
            while(r <= right && sum[r] - sum[i] <= upper) r++;
            ret += (r - l);
            i++;
        }

        vector<long> tmp(right - left + 1);
        int p1 = left, p2 = mid + 1;
        int p = 0;
        while(p1 <= mid || p2 <= right) {
            if(p1 > mid) tmp[p++] = sum[p2++];
            else if(p2 > right) tmp[p++] = sum[p1++];
            else if(sum[p1] <= sum[p2]) tmp[p++] = sum[p1++];
            else tmp[p++] = sum[p2++];
        }
        for(int i = 0; i < tmp.size(); i++) sum[left + i] = tmp[i];
        return ret;
    }
};


给定一个整数数组?nums，返回区间和在?[lower, upper]?之间的个数，包含?lower?和?upper。
区间和?S(i, j)?表示在?nums?中，位置从?i?到?j?的元素之和，包含?i?和?j?(i ≤ j)。

说明:
最直观的算法复杂度是?O(n2) ，请在此基础上优化你的算法。

示例:

输入: nums = [-2,5,-1], lower = -2, upper = 2,
输出: 3 
解释: 3个区间分别是: [0,0], [2,2], [0,2]，它们表示的和分别为: -2, -1, 2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-of-range-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
