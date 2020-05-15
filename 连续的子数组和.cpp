//给定一个包含非负数的数组和一个目标整数?k，编写一个函数来判断该数组是否含有连续的子数组，其大小至少为 2，总和为 k 的倍数，即总和为 n*k，其中 n 也是一个整数。

//示例 1:

//输入: [23,2,4,6,7], k = 6
//输出: True
//解释: [2,4] 是一个大小为 2 的子数组，并且和为 6。
//示例 2:

//输入: [23,2,6,4,7], k = 6
//输出: True
//解释: [23,2,6,4,7]是大小为 5 的子数组，并且和为 42。
//说明:

//数组的长度不会超过10,000。
//你可以认为所有数字总和在 32 位有符号整数范围内。



class Solution {
public:
    //暴力解法
    bool checkSubarraySum1(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> arr(len+1,0);
        for(int i = 1; i <= len; i++)
            arr[i] = arr[i-1] + nums[i-1];
        
        for(int i = 0; i <= len-2; i++)
            for(int j = i+2; j <= len; j++)
                if(k==0 && (arr[i]-arr[j]) == 0) 
                    return true;
                else if(k != 0 && (arr[i] - arr[j]) % k == 0) 
                    return true;

        return false;
    }

    //哈希 + 前缀和
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        int len = nums.size();
        unordered_map<int,int> map;
        map.insert({0,-1});//排除 [0,0],0 的干扰
        int pre = 0;
        for(int i = 0; i < len; i++)
        {
            pre += nums[i];
            if(k != 0) pre %= k;

            if(map.count(pre) && i - map[pre] > 1) return true;
 
            map.insert({pre,i});
        }
        return false;
    }
};
