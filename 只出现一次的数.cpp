//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。

//说明：

//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

//示例 1:

//输入: [2,2,3,2]
//输出: 3
//示例?2:

//输入: [0,1,0,1,0,1,99]
//输出: 99


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int ret = 0;//统计第i位出现1的次数
            int count = 1 << i;
            for(int j = 0; j < nums.size(); j++){
                if(nums[j] & count)
                    ret++;
            }
            if(ret % 3) 
                ans |= count;
        }
        return ans;
    }
};

//给定一个整数数组?nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

//示例 :

//输入: [1,2,1,3,2,5]
//输出: [3,5]
//注意：


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tmp = 0;
        int len = nums.size();

        for(auto& eoch : nums)
            tmp ^= eoch;
        
        //找到tmp第一位不一样数的位置
        int pos = 0;
        for(int i = 0; i < 32; i++){
            int ret = 1 << i;
            if(tmp & ret){
                pos = ret;
                break;
            }
        }

        int left = 0, right = 0;
        for(auto& eoch : nums)
            (eoch & pos) ? (left ^= eoch) : (right ^= eoch);
        
        return {left,right};
    }
};
