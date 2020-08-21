还记得童话《卖火柴的小女孩》吗？现在，你知道小女孩有多少根火柴，请找出一种能使用所有火柴拼成一个正方形的方法。不能折断火柴，可以把火柴连接起来，并且每根火柴都要用到。

输入为小女孩拥有火柴的数目，每根火柴用其长度表示。输出即为是否能用所有的火柴拼成正方形。

示例?1:

输入: [1,1,2,2,2]
输出: true

解释: 能拼成一个边长为2的正方形，每边两根火柴。
示例?2:

输入: [3,3,3,3,4]
输出: false

解释: 不能用所有火柴拼成一个正方形。
注意:

给定的火柴长度和在?0?到?10^9之间。
火柴数组的长度不超过15。

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        if(n < 4) return false;

        int sum = 0;
        for(auto& num : nums)
            sum += num;
        
        if((sum / 4) * 4 != sum)    return false;
        sort(nums.begin(),nums.end(),[](const int a,const int b)->bool{
            return a > b;
        });
        return dfs(nums,0,n,0,0,0,0,sum/4);
    }

    bool dfs(vector<int>& nums,int idx,int n,int l1,int l2,int l3,int l4,int len)
    {
        if(idx == n)
        {
            if(l1 == l2 && l2 == l3 && l3 == l4 && l4 == len)   return true;
            return false;
        }

        if(l1 > len || l2 > len || l3 > len || l4 > len)    return false;

        return dfs(nums,idx+1,n,l1+nums[idx],l2,l3,l4,len) ||
            dfs(nums,idx+1,n,l1,l2+nums[idx],l3,l4,len) ||
            dfs(nums,idx+1,n,l1,l2,l3+nums[idx],l4,len) ||
            dfs(nums,idx+1,n,l1,l2,l3,l4+nums[idx],len);  
    }
};
