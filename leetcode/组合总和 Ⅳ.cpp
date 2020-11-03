class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        unsigned long long f[target+1];
        memset(f,0x00,sizeof f);

        f[0] = 1;
        for(int i = 1; i <= target; i++)
            for(int num : nums)
                if(i >= num) f[i] += f[i - num];
        
        return f[target];
    }
};


给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

示例:

nums = [1, 2, 3]
target = 4

所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

请注意，顺序不同的序列被视作不同的组合。

因此输出为 7。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
