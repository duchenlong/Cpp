class Solution {
public:
    const int N = 1e5+10;
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        
        int f[N];
        memset(f,0x00,sizeof f);
        
        for(int i = 0; i < n; i++) {
            f[i+1] = nums[i] + f[i];
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            //cout << f[i] << " " << f[i+1] << endl;
            int le = nums[i] * i - f[i];
            int ri = f[n] - f[i + 1] - nums[i] * (n - i - 1);
            
            ans.push_back(abs(le) + abs(ri));
        }
        
        return ans;
    }
};


给你一个 非递减?有序整数数组?nums?。

请你建立并返回一个整数数组?result，它跟?nums?长度相同，且result[i]?等于?nums[i]?与数组中所有其他元素差的绝对值之和。

换句话说，?result[i]?等于?sum(|nums[i]-nums[j]|) ，其中?0 <= j < nums.length 且?j != i?（下标从 0 开始）。

?

示例 1：

输入：nums = [2,3,5]
输出：[4,3,5]
解释：假设数组下标从 0 开始，那么
result[0] = |2-2| + |2-3| + |2-5| = 0 + 1 + 3 = 4，
result[1] = |3-2| + |3-3| + |3-5| = 1 + 0 + 2 = 3，
result[2] = |5-2| + |5-3| + |5-5| = 3 + 2 + 0 = 5。
示例 2：

输入：nums = [1,4,6,8,10]
输出：[24,15,13,15,21]
?

提示：

2 <= nums.length <= 105
1 <= nums[i] <= nums[i + 1] <= 104

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-absolute-differences-in-a-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
