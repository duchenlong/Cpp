给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。

?

示例 1：

输入：
    3
   / \
  9  20
    /  \
   15   7
输出：[3, 14.5, 11]
解释：
第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。
?

提示：

节点值的范围在32位有符号整数范围内。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        vector<double> ans;

        while(!que.empty()) {
            int size = que.size();
            double sum = 0;
            for(int i = 0; i < size; i++) {
                auto f = que.front();
                que.pop();
                sum += f->val;
                if(f->left) que.push(f->left);
                if(f->right) que.push(f->right);
            }
            ans.push_back(sum/(double)size);
        }

        return ans;
    }
};
