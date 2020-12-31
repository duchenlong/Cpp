class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        res.push_back({});

        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int m = res.size();
            for(int j = 0; j < m; j++) {
                vector<int> t = res[j];
                t.push_back(nums[i]);
                res.push_back(move(t));
            }
        }

        return res;
    }
};

幂集。编写一种方法，返回某集合的所有子集。集合中不包含重复的元素。

说明：解集不能包含重复的子集。

示例:

 输入： nums = [1,2,3]
 输出：
[
  [3],
? [1],
? [2],
? [1,2,3],
? [1,3],
? [2,3],
? [1,2],
? []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-set-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
