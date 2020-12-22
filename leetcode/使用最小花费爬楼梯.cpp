class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // int f[n+1];
        // memset(f,0x3f,sizeof f);

        // f[0] = cost[0];
        // f[1] = cost[1];
        for(int i = 2; i < n; i++) {
            cost[i] += min(cost[i-1], cost[i-2]);
        }

        return min(cost[n-1],cost[n-2]);
    }
};


数组的每个索引作为一个阶梯，第?i个阶梯对应着一个非负数的体力花费值?cost[i](索引从0开始)。

每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。

您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯。

示例?1:

输入: cost = [10, 15, 20]
输出: 15
解释: 最低花费是从cost[1]开始，然后走两步即可到阶梯顶，一共花费15。
?示例 2:

输入: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
输出: 6
解释: 最低花费方式是从cost[0]开始，逐个经过那些1，跳过cost[3]，一共花费6。
注意：

cost?的长度将会在?[2, 1000]。
每一个?cost[i] 将会是一个Integer类型，范围为?[0, 999]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-cost-climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
