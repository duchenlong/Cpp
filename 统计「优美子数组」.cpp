//你一个整数数组?nums 和一个整数 k。

//如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。

//请返回这个数组中「优美子数组」的数目。

//?

//示例 1：

//输入：nums = [1,1,2,1,1], k = 3
//输出：2
//解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
//示例 2：

//输入：nums = [2,4,6], k = 1
//输出：0
//解释：数列中不包含任何奇数，所以不存在优美子数组。
//示例 3：

//输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
//输出：16




class Solution {
public:
    int numberOfSubarrays1(vector<int>& nums, int k) {
        int len = nums.size();
        int* arr = new int[len+2];
        int num = 0;
        int ans = 0;

        for(int i = 0; i < len; i++)
            if(nums[i] & 1)
                arr[++num] = i;
        arr[0] = -1, arr[++num] = len; // arr数组是一个[0,len] 左闭右闭区间
        int left = 1, right = k;

        while(right < num){
            ans += (arr[left] - arr[left-1]) * (arr[right+1] - arr[right]);
            left++;
            right++;
        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(n + 1, 0);        
        int odd = 0, ans = 0;
        cnt[0] = 1;
        for (int i = 0; i < n; ++i) {
            odd += nums[i] & 1;
            ans += odd >= k ? cnt[odd - k] : 0;
            cnt[odd] += 1;//统计两个奇数之间有多少个数，包括自己
        }
        return ans;
    }
};

    

