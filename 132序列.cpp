//给定一个整数序列：a1, a2, ..., an，一个132模式的子序列?ai, aj, ak?被定义为：当 i < j < k 时，ai < ak < aj。设计一个算法，当给定有?n 个数字的序列时，验证这个序列中是否含有132模式的子序列。

//注意：n 的值小于15000。

//示例1:

//输入: [1, 2, 3, 4]

//输出: False

//解释: 序列中不存在132模式的子序列。
//示例 2:

//输入: [3, 1, 4, 2]

//输出: True

//解释: 序列中有 1 个132模式的子序列： [1, 4, 2].
//示例 3:

//输入: [-1, 3, 2, 0]

//输出: True

//解释: 序列中有 3 个132模式的的子序列: [-1, 3, 2], [-1, 3, 0] 和 [-1, 2, 0].

class Solution {
public:
    bool find132pattern1(vector<int>& nums) {
        stack<int> st;

        int two = INT_MIN;//表示第二大元素

        for(int i = nums.size()-1; i >= 0; i--)
        {
            int value = nums[i];
            if(value < two) return true;

            while(!st.empty() && value > st.top())
            {
                two = st.top();
                st.pop();
            }

            //保证栈里的元素自栈顶向下都是递增的
            st.push(value);
        }
        return false;
    }
    bool find132pattern(vector<int>& nums)
    {
        int minNum = INT_MAX;

        for(int i = 0; i < nums.size(); i++)
        {
            minNum = min(minNum,nums[i]);
            if(minNum == nums[i]) continue;

            for(int j = nums.size()-1; j > i; j--)
                if(nums[i] > nums[j] && nums[j] > minNum)
                    return true;
        }

        return false;
    }
};
