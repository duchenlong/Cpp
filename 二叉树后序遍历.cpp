

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
    vector<int> postorderTraversal1(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* r = root;
        TreeNode* node = NULL;

        while(!st.empty() || r)
        {
            if(r)   //根节点不是空，说明当前节点有效，放入栈中保存
            {
                st.push(r);
                r = r->left;//更改节点为左孩子
            }
            else    //根节点为空，说明前一个节点是一个叶子节点
            {
                r = st.top();
                //需要添加这个节点有两种情况
                //一个是他没有右孩子，并且左孩子是空
                //另一个是他的右孩子遍历过了
                if(!r->right || r->right == node)
                {
                    ans.push_back(r->val);
                    st.pop();
                    node = r;
                    r=NULL;
                }
                else
                    r = r->right;

            }
        }
        return ans;
    }


    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) 
            return ans;
        stack<TreeNode*> st;
        st.push(root);
        

        while(!st.empty())
        {
            TreeNode* node = st.top();
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);

            if(!node->left && !node->right)
            {
                ans.push_back(node->val);
                st.pop();
            }
            node->left = node->right = NULL;
        }
        return ans;
    }
};
