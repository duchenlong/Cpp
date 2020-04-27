//给定一个二叉树，在树的最后一行找到最左边的值。

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
    int findBottomLeftValue(TreeNode* root) {
        int ans = root->val;
        int maxdepth = 1;
        dfs(root,ans,1,maxdepth);
        return ans;
    }

    void dfs(TreeNode* root, int& ans, int depth, int& maxdepth){
        if(!root) return;
        //找左下方第一个，所以优先遍历左子树
        // if(root->left) {
        //     if(depth == maxdepth) {
        //         ans = root->left->val;
        //         maxdepth++;
        //     }
        //     dfs(root->left,ans,depth+1,maxdepth);
        // }

        // if(root->right) {
        //     if(depth == maxdepth) {
        //         ans = root->right->val;
        //         maxdepth++;
        //     }
        //     dfs(root->right,ans,depth+1,maxdepth);
        // }

        if(!root->left && !root->right && depth > maxdepth) {
            maxdepth = depth;
            ans = root->val;
        }
        dfs(root->left,ans,depth+1,maxdepth);
        dfs(root->right,ans,depth+1,maxdepth);
        
    }
};
//请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

//例如，二叉树?[1,2,2,3,4,4,3] 是对称的。

//? ? 1
//? ?/ \
//? 2 ? 2
//?/ \ / \
//3 ?4 4 ?3
//但是下面这个?[1,2,2,null,3,null,3] 则不是镜像对称的:

//? ? 1
//? ?/ \
//? 2 ? 2
//? ?\ ? \
//? ?3 ? ?3

//?

//示例 1：

//输入：root = [1,2,2,3,4,4,3]
//输出：true
//示例 2：

//输入：root = [1,2,2,null,3,null,3]
//输出：false


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        
        return Fun(root->left, root->right);
    }

    bool Fun(TreeNode* Treeleft, TreeNode* Treeright) {
        if(!Treeright && !Treeleft) return true;
        if(!Treeleft || !Treeright) return false;

        //两个节点都是非空节点
        if(Treeleft->val != Treeright->val) return false;
        return Fun(Treeleft->left, Treeright->right) &&
                Fun(Treeleft->right, Treeright->left);
    }
};
