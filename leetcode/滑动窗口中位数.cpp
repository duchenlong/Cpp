class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> st;
        int n = nums.size();
        vector<double> res;

        for(int i = 0; i < n; i++) {
            st.insert(nums[i]);
            if(st.size() > k)
                st.erase(st.lower_bound(nums[i - k]));
            if(st.size() == k) {
                int id = k / 2;
                auto it = st.begin();
                for(int j = 0; j < id; j ++) it ++;
                if(k & 1) res.push_back(*it / 1.0);
                else res.push_back(((double)*it + (double)*(--it)) / 2.0);
            }
        } 
        return res;
    }
};

中位数是有序序列最中间的那个数。如果序列的长度是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。

例如：

[2,3,4]，中位数是?3
[2,3]，中位数是 (2 + 3) / 2 = 2.5
给你一个数组 nums，有一个长度为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1 位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。

?

示例：

给出?nums = [1,3,-1,-3,5,3,6,7]，以及?k = 3。

窗口位置                      中位数
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7      -1
 1  3 [-1  -3  5] 3  6  7      -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6
?因此，返回该滑动窗口的中位数数组?[1,-1,-1,3,5,6]。

?

提示：

你可以假设?k?始终有效，即：k 始终小于输入的非空数组的元素个数。
与真实值误差在 10 ^ -5 以内的答案将被视作正确答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sliding-window-median
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
