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
    vector<vector<int> > ans;
    vector<int> tmp;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root,sum);
        return ans;
    }

    void dfs(TreeNode* root,int sum) {
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) {
            if(sum == root->val) {
                tmp.push_back(root->val);
                ans.push_back(tmp);
                tmp.pop_back();
            }
            return ;
        }

        tmp.push_back(root->val);
        dfs(root->left,sum-root->val);
        dfs(root->right,sum-root->val);
        tmp.pop_back();
    }
};

输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

?

示例:
给定如下二叉树，以及目标和?sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:

[
   [5,4,11,2],
   [5,8,4,5]
]
?

提示：

节点总数 <= 10000

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
