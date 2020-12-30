struct Node {
    int x,m,k;
    bool operator<(const Node& no) const {
        return m < no.m;
    }
}q[100010];

int f[100005 * 32 + 10][2], idx;

class Solution {
public:
    
    void insert(int num) {
        int p = 0;
        for(int i = 31; i >= 0; i--) {
            int ne = (num >> i) & 1;
            if(f[p][ne] == 0) f[p][ne] = ++idx;
            p = f[p][ne];
        }
    }

    int find(int num) {
        if(!idx) return -1;     // 没有比num 小的元素

        int p = 0;
        int res = 0;
        for(int i = 31; i >= 0; i--) {
            int ne = (num >> i) & 1;
            if(f[p][!ne]) {
                res = res * 2 + 1;
                p = f[p][!ne];
            } else {
                res = res * 2;
                p = f[p][ne];
            }
        }

        return res;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        idx = 0;
        memset(f,0x00,sizeof f);

        int n = nums.size(), m = queries.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < m; i++)
            q[i] = {queries[i][0],queries[i][1],i};
        sort(q,q+m);

        vector<int> res(m);
        int le = 0;
        for(int i = 0; i < m; i++) {
            while(le < n && nums[le] <= q[i].m){
                insert(nums[le]);
                le++;
            }
            res[q[i].k] = find(q[i].x);
        }

        return res;
    }

    // vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    //     int n = nums.size(), m = queries.size();
    //     sort(nums.begin(),nums.end());
    //     for(int i = 0; i < m; i++) queries[i].push_back(i);

    //     sort(queries.begin(),queries.end(),[](const auto& a,const auto& b)->bool{
    //         return a[1] < b[1];
    //     });

    //     vector<int> res(m);
    //     int le = 0;
    //     for(auto& e : queries) {
    //         while(le < n && nums[le] <= e[1]){
    //             insert(nums[le]);
    //             le++;
    //         }
    //         res[e[2]] = find(e[0]);
    //     }

    //     return res;
    // }
};


给你一个由非负整数组成的数组 nums 。另有一个查询数组 queries ，其中 queries[i] = [xi, mi] 。

第 i 个查询的答案是 xi 和任何 nums 数组中不超过 mi 的元素按位异或（XOR）得到的最大值。换句话说，答案是 max(nums[j] XOR xi) ，其中所有 j 均满足 nums[j] <= mi 。如果 nums 中的所有元素都大于 mi，最终答案就是 -1 。

返回一个整数数组 answer 作为查询的答案，其中 answer.length == queries.length 且 answer[i] 是第 i 个查询的答案。

?

示例 1：

输入：nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
输出：[3,3,7]
解释：
1) 0 和 1 是仅有的两个不超过 1 的整数。0 XOR 3 = 3 而 1 XOR 3 = 2 。二者中的更大值是 3 。
2) 1 XOR 2 = 3.
3) 5 XOR 2 = 7.
示例 2：

输入：nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
输出：[15,-1,5]
?

提示：

1 <= nums.length, queries.length <= 105
queries[i].length == 2
0 <= nums[j], xi, mi <= 109
通过次数659提交次数2,040

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-xor-with-an-element-from-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
