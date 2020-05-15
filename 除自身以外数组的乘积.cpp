//给你一个长度为?n?的整数数组?nums，其中?n > 1，返回输出数组?output?，其中 output[i]?等于?nums?中除?nums[i]?之外其余各元素的乘积。

//?

//示例:

//输入: [1,2,3,4]
//输出: [24,12,8,6]
//?

//提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。

//说明: 请不要使用除法，且在?O(n) 时间复杂度内完成此题。

//进阶：
//你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）


class Solution {
public:
    //朴素做法 O(N)空间复杂度
    vector<int> productExceptSelf1(vector<int>& nums) {
        int len = nums.size();
        vector<int> left(len+1,1);
        vector<int> right(len+1,1);

        //左边区间
        for(int i = 1; i < len; i++)
            left[i] = left[i-1]*nums[i-1];
        
        //右边区间
        for(int i = len-2; i >= 0; i--)
            right[i] = right[i+1]* nums[i+1];
        
        vector<int> ret(len,0);
        for(int i = 0; i < len; i++)
            ret[i] = left[i]*right[i];
        return ret;
    }

    //不使用额外空间
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret(len,1);
        //左边区间
        for(int i = 1; i < len; i++)
            ret[i] = ret[i-1]*nums[i-1];
        
        //右边区间
        int right = 1;
        for(int i = len-2; i >= 0; i--)
        {
            right *= nums[i+1];
            ret[i] *= right; 
        }
        return ret;
    }
};
