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
    int d = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs1(root);
        return d;
    }

    int dfs1(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 0;

        int le = (root->left) ? dfs1(root->left) + 1 : 0;
        int ri = (root->right) ? dfs1(root->right) + 1 : 0;
        d = max(d,le + ri);
        return max(le , ri);
    }


};


给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

?

示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回?3, 它的长度是路径 [4,2,1,3] 或者?[5,2,1,3]。

?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/diameter-of-binary-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
