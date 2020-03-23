//700. 二叉搜索树中的搜索
//给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。

//例如，

//给定二叉搜索树:

//        4
//       / \
//      2   7
//     / \
//    1   3

//和值: 2
//你应该返回如下子树:

//      2     
//     / \   
//    1   3
//在上述示例中，如果要找的值是 5，但因为没有节点值为 5，我们应该返回 NULL。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* searchBST(struct TreeNode* root, int val){
    if(!root)
        return NULL;
    
    if(root->val == val)
        return root;
    else if(root->val < val)//根节点值小于Val,则说明结果可能在右子树
        return searchBST(root->right,val);
    //根节点值大于于Val,则说明结果可能在左子树
    return searchBST(root->left,val);
}
