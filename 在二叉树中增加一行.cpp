给定一个二叉树，根节点为第1层，深度为 1。在其第?d?层追加一行值为?v?的节点。

添加规则：给定一个深度值 d （正整数），针对深度为 d-1 层的每一非空节点 N，为 N 创建两个值为?v?的左子树和右子树。

将?N 原先的左子树，连接为新节点?v 的左子树；将?N 原先的右子树，连接为新节点?v 的右子树。

如果 d 的值为 1，深度 d - 1 不存在，则创建一个新的根节点 v，原先的整棵树将作为 v 的左子树。

示例 1:

输入: 
二叉树如下所示:
       4
     /   \
    2     6
   / \   / 
  3   1 5   

v = 1

d = 2

输出: 
       4
      / \
     1   1
    /     \
   2       6
  / \     / 
 3   1   5   

示例 2:

输入: 
二叉树如下所示:
      4
     /   
    2    
   / \   
  3   1    

v = 1

d = 3

输出: 
      4
     /   
    2
   / \    
  1   1
 /     \  
3       1


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
    TreeNode* addOneRow1(TreeNode* root, int v, int d) {
        if(d == 1)
        {
            TreeNode* ret = new TreeNode(v);
            ret->left = root;
            return ret;
        }
        queue<TreeNode*> que;
        que.push(root);
        int height = 2;
        while(!que.empty())
        {
            int size = que.size();

            for(int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();

                if(height == d)
                {
                    TreeNode* left = new TreeNode(v);
                    if(node->left) left->left = node->left;
                    node->left = left;
                    
                    TreeNode* right = new TreeNode(v);
                    if(node->right) right->right = node->right;
                    node->right = right;
                }
                else
                {
                    if(node->left) que.push(node->left);
                    if(node->right) que.push(node->right);
                }

            }

            if(height == d) break;
            height++;
        }
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int v, int d)
    {
        if(d == 1 || d == 0)
        {
            TreeNode* ret = new TreeNode(v);
            d == 1 ? ret->left = root : ret->right = root;;
            return ret;
        }

        if(root && d > 1)
        {
            root->left = addOneRow(root->left,v,d > 2 ? d - 1 : 1);
            root->right = addOneRow(root->right,v,d > 2 ? d - 1 : 0);
        }

        return root;
    }
};
