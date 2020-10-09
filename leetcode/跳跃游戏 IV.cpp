class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        // 离散化  1 7 7 7 7 11 --》  1 7 7 11
        int m = 0;
        for(int i = 0; i < n; i++) {
            int len = 1;
            while(i + len < n && arr[i] == arr[len + i]) len++;
            arr[m++] = arr[i];
            if(len != 1) arr[m++] = arr[i];
            i += len - 1;
        }

        queue<int> que({0});
        int dp[m];
        memset(dp,0x3f,sizeof(dp));
        dp[0] = 0;

        // 有向图
        unordered_map<int,set<int> > ums;
        for(int i = 0; i < m; i++) ums[arr[i]].insert(i);

        int ans = 0;
        while (que.empty() == false) {
            int size = que.size();
            while (size --) {
                int f = que.front();
                que.pop();
                if(f == m - 1) return ans;    // 当前位置为终点

                // left
                int le = f - 1;
                if(le >= 0 && dp[le] > dp[f] + 1) {
                    que.push(le);
                    dp[le] = dp[f] + 1;
                }

                // right
                int ri = f + 1;
                if ( ri < m && dp[ri] > dp[f] + 1) {
                    que.push(ri);
                    dp[ri] = dp[f] + 1;
                }

                // same
                for ( auto& index : ums[arr[f]] ) {
                    if(dp[index] > dp[f] + 1) {
                        que.push(index);
                        dp[index] = dp[f] + 1;
                    }
                }
            }
            ans++;
        }

        return -1;  // 无法跳到终点
    }
};

给你一个整数数组?arr?，你一开始在数组的第一个元素处（下标为 0）。

每一步，你可以从下标?i?跳到下标：

i + 1?满足：i + 1 < arr.length
i - 1?满足：i - 1 >= 0
j?满足：arr[i] == arr[j]?且?i != j
请你返回到达数组最后一个元素的下标处所需的?最少操作次数?。

注意：任何时候你都不能跳到数组外面。

?

示例 1：

输入：arr = [100,-23,-23,404,100,23,23,23,3,404]
输出：3
解释：那你需要跳跃 3 次，下标依次为 0 --> 4 --> 3 --> 9 。下标 9 为数组的最后一个元素的下标。
示例 2：

输入：arr = [7]
输出：0
解释：一开始就在最后一个元素处，所以你不需要跳跃。
示例 3：

输入：arr = [7,6,9,6,9,6,9,7]
输出：1
解释：你可以直接从下标 0 处跳到下标 7 处，也就是数组的最后一个元素处。
示例 4：

输入：arr = [6,1,9]
输出：2
示例 5：

输入：arr = [11,22,7,7,7,7,7,7,7,22,13]
输出：3
?

提示：

1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game-iv
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
