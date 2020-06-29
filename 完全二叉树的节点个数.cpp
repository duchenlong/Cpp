
给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~?2h?个节点。

示例:

输入: 
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6

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
    int countNodes1(TreeNode* root) {
        if(root == nullptr) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    int countNodes(TreeNode* root)
    {
        TreeNode* cur = root;
        int h = GetDepth(root);
        int num = 0;//最后一层的节点数
        int lev = 1;

        while(cur)
        {
            TreeNode* tmp = cur->right;
            if(tmp && lev + GetDepth(tmp) == h)
            {
                cur = cur->right;
                num += pow(2,h-lev-1);
            }
            else
            {
                cur = cur->left;
            }
            lev++;
        }
        return num + pow(2,h-1);
    }

    int GetDepth(TreeNode* root)
    {
        int ans = 0;
        while(root != nullptr)
        {
            root = root->left;
            ans++;
        }
        return ans;
    }
};
