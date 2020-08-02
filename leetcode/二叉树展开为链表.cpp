给定一个二叉树，原地将它展开为一个单链表。

?

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* next = nullptr;
    void flatten(TreeNode* root) {
        if(root == nullptr) return ;
        
        flatten(root->right);
        flatten(root->left);
    
        root->right = next;
        root->left = nullptr;
        next = root;
    }

     void flatten1(TreeNode* root)
     {
         if(root == nullptr)    return;

         flatten(root->left);
         flatten(root->right);

         TreeNode* ri = root->right;
         root->right = root->left;
         root->left = nullptr;

         TreeNode* node = root;
         while(node->right != nullptr)
            node = node->right;
        node->right = ri;
     }
};
