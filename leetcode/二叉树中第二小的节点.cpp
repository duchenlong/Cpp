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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == nullptr) return -1;
        return dfs(root,root->val);
    }

    int dfs(TreeNode* root,int val) {
        if(root == nullptr) return -1;
        if(root->val > val) return root->val;

        int le = dfs(root->left,val);
        int ri = dfs(root->right,val);
        if(le > val && ri > val) return min(le,ri);

        // le == val || ri == val
        return max(le,ri);
    }
};


给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为?2?或?0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。

给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。

示例 1:

输入: 
    2
   / \
  2   5
     / \
    5   7

输出: 5
说明: 最小的值是 2 ，第二小的值是 5 。
示例 2:

输入: 
    2
   / \
  2   2

输出: -1
说明: 最小的值是 2, 但是不存在第二小的值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
