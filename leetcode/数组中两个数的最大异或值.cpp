class Solution {
public:
    const int M = 50010;
    class dtree {
        struct node {
            node* son[2];
            node() {
                son[1] = son[0] = nullptr;
            }
        };
        public:
            dtree(int size) {
                root = new node();
            }

            void insert(int num) {
                node* cur = root;
                for(int i = 30; ~i; i--) {
                    int v = (num >> i) & 1;
                    if(cur->son[v] == nullptr) {
                        cur->son[v] = new node();
                    }
                    cur = cur->son[v];
                }
            }

            int check(int num) {
                int ret = 0;
                node* cur = root;
                for(int  i = 30; ~i; i--) {
                    int v = (num >> i) & 1;
                    if(cur->son[!v] != nullptr) {
                        ret |= (1<<i);
                        cur = cur->son[!v];
                    } else {
                        cur = cur->son[v];
                    }
                }

                return ret;
            }
        private:
            node* root;
    };

    int findMaximumXOR(vector<int>& nums) {
        dtree dt(M);
        for(int i = 0; i < nums.size(); i++) dt.insert(nums[i]);

        int ans = 0;
        for(int i = 0; i < nums.size(); i++) ans = max(ans,dt.check(nums[i]));

        return ans;
    }
};

给定一个非空数组，数组中元素为 a0, a1, a2, … , an-1，其中 0 ≤ ai < 231?。

找到 ai 和aj?最大的异或 (XOR) 运算结果，其中0 ≤ i,??j < n?。

你能在O(n)的时间解决这个问题吗？

示例:

输入: [3, 10, 5, 25, 2, 8]

输出: 28

解释: 最大的结果是 5 ^ 25 = 28.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
