const int N = 2e6 + 10;
int f[N];

class Solution {
public:
    int g,cnt,n,res;
    vector<int> num;
    int minAbsDifference(vector<int>& nums, int goal) {
        res = INT_MAX,g = goal,n = nums.size(),cnt = 0;
        num = nums;
        dfs1(0,0);
        sort(f,f+cnt);
        dfs2((n + 1) /2,0);
        return res;
    }

    void dfs1(int id,int sum) {
        if(id == (n + 1) /2) {
            f[cnt ++] = sum;
            return;
        }

        dfs1(id + 1, sum);
        dfs1(id + 1, sum + num[id]);
    }

    void dfs2(int id,int sum) {
        if(id == n) {
            int le = 0, ri = cnt - 1;
            while(le < ri) {
                int mid = le + ri + 1 >> 1;
                if(f[mid] + sum <= g) le = mid;
                else ri = mid - 1;
            }
            res = min(res,abs(f[le] + sum - g));
            if(le + 1 < cnt) res = min(res,abs(f[le + 1] + sum - g));
            return;
        }
        dfs2(id + 1, sum);
        dfs2(id + 1, sum + num[id]);
    }
};

给你一个整数数组 nums 和一个目标值 goal 。

你需要从 nums 中选出一个子序列，使子序列元素总和最接近 goal 。也就是说，如果子序列元素和为 sum ，你需要 最小化绝对差 abs(sum - goal) 。

返回 abs(sum - goal) 可能的 最小值 。

注意，数组的子序列是通过移除原始数组中的某些元素（可能全部或无）而形成的数组。

?

示例 1：

输入：nums = [5,-7,3,5], goal = 6
输出：0
解释：选择整个数组作为选出的子序列，元素和为 6 。
子序列和与目标值相等，所以绝对差为 0 。
示例 2：

输入：nums = [7,-9,15,-2], goal = -5
输出：1
解释：选出子序列 [7,-9,-2] ，元素和为 -4 。
绝对差为 abs(-4 - (-5)) = abs(1) = 1 ，是可能的最小值。
示例 3：

输入：nums = [1,2,3], goal = -7
输出：7
?

提示：

1 <= nums.length <= 40
-107 <= nums[i] <= 107
-109 <= goal <= 109

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/closest-subsequence-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
