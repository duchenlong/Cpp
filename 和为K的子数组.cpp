//给定一个整数数组和一个整数?k，你需要找到该数组中和为?k?的连续的子数组的个数。

//示例 1 :

//输入:nums = [1,1,1], k = 2
//输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
//说明 :

//数组的长度为 [1, 20,000]。
//数组中元素的范围是 [-1000, 1000] ，且整数?k?的范围是?[-1e7, 1e7]。



class Solution {
public:
    int subarraySum1(vector<int>& nums, int k) {
        int len = nums.size();
        int ans = 0;
        int tmp = 0;

        for(int i = 0; i < len; i++)
        {
            tmp = 0;
            for(int j = i; j < len; j++)
            {
                tmp += nums[j];
                if(tmp == k)
                    ans++;
            }
        }
        return ans;
    }

    int subarraySum2(vector<int>& nums, int k)
    {
        int len = nums.size();
        vector<int> arr(len+2,0);
        //计算前缀和
        for(int i = 1; i <= len; i++)
            arr[i] = arr[i-1] + nums[i-1];
        // for(int i = 1; i <= len; i++)
        //     cout<<arr[i]<<' ';
        
        int ans = 0;
        //固定左区间
        for(int i = 0; i <= len; i++)
            for(int j = i+1; j <= len; j++)
                if(arr[j]-arr[i] == k) ans++;

        //固定右区间
        // for(int i = 1; i <= len; i++)
        //     for(int j = 0; j <= len; j++)
        //         if(arr[i]-arr[j] == k) ans++;
        return ans;
    }

    //哈希+前缀和
    int subarraySum(vector<int>& nums, int k)
    {
        int len = nums.size();
        unordered_map<int,int> map;

        int ans = 0;
        int pre = 0;
        map[0]=1;
        for(int i = 0; i < len; i++)
        {
            pre += nums[i];
            ans += map[pre-k];
            map[pre]++;
        }
        return ans;
    }
};
