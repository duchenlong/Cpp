//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

//百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

//例如，给定如下二叉树:? root =?[3,5,1,6,2,0,8,null,null,7,4]



//?

//示例 1:

//输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
//输出: 3
//解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
//示例?2:

//输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
//输出: 5
//解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
//?

//说明:

//所有节点的值都是唯一的。
//p、q 为不同节点且均存在于给定的二叉树中。

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
    //后序遍历
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        //根节点为NULL
        if(!root) return NULL;

        //根节点等于p q中的一个
        if(root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        //如果p,q在根节点的左右两边
        if(left && right) return root;

        //左右节点 一真一假  或者都是NULL都么有找到
        return left ? left:right;
    }

    //哈希存储
    unordered_map<int, TreeNode*> before;
    unordered_map<int, bool> visit;
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        before[root->val] = NULL;
        dfs(root);

        while(p)
        {
            visit[p->val] = true;
            p = before[p->val];
        }

        while(q)
        {
            if(visit[q->val]) return q;
            q = before[q->val];
        }

        return NULL;
    }  

    void dfs(TreeNode* root)
    {
        if(!root) return;

        if(root->left)
        {
            before[root->left->val] = root;
            dfs(root->left);
        }

        if(root->right)
        {
            before[root->right->val] = root;
            dfs(root->right);
        }
    }
};
