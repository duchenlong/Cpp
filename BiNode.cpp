二叉树数据结构TreeNode可用来表示单向链表（其中left置空，right为下一个链表节点）。实现一个方法，把二叉搜索树转换为单向链表，要求值的顺序保持不变，转换操作应是原址的，也就是在原始的二叉搜索树上直接修改。

返回转换后的单向链表的头节点。

注意：本题相对原题稍作改动

?

示例：

输入： [4,2,5,1,3,null,6,0]
输出： [0,null,1,null,2,null,3,null,4,null,5,null,6]
提示：

节点数量不会超过 100000。

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
    TreeNode* convertBiNode1(TreeNode* root) {
        TreeNode* tmp = nullptr;
        TreeNode* ret = nullptr;
        dfs(root,tmp,ret);

        return ret;
    }

    void dfs(TreeNode* root,TreeNode*& pre,TreeNode*& ret)
    {
        if(!root) return ;

        if(root->left) dfs(root->left,pre,ret);

        if(!ret) ret = root;
        
        root->left = nullptr;
        if(pre) pre->right = root;
        pre = root;

        if(root->right) dfs(root->right,pre,ret);
    }

    //非递归
    TreeNode* convertBiNode(TreeNode* root)
    {
        if(!root) return root;

        stack<TreeNode*> st;
        TreeNode* r = root;
        TreeNode* head = new TreeNode(-1);
        TreeNode* p = head;

        while(r || !st.empty())
        {
            if(r)
            {
                st.push(r);
                r = r->left;
                continue;
            }

            //已经到底最后一个没有访问的左节点
            r = st.top();
            st.pop();
            r->left = nullptr;
            p->right = r;
            p = r;
            r = r->right;
            
        }

        TreeNode* ret = head->right;
        delete head;
        return ret;
    }
};
