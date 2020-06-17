实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int p = len - 1;

        //找左边第一个比他小的数的位置
        for(int i = p ; i >= 0; i--)    //左边的范围
            for(int j = len - 1; j > i; j--)    //右边区间范围
                if(nums[j] > nums[i])
                {
                    swap(nums[i],nums[j]);
                    sort(nums.begin() + i + 1,nums.end());
                    return ;
                }
        
        sort(nums.begin(),nums.end());

    }
};
