//给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

//例如：
//给定二叉树?[3,9,20,null,null,15,7],

//    3
//   / \
//  9  20
//    /  \
//   15   7
//返回锯齿形层次遍历如下：

//[
//  [3],
//  [20,9],
//  [15,7]
//]




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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        stack<TreeNode*> st;
        st.push(root);
        vector<vector<int> > ans;

        int ret = 1; //1,0  从左向右，从右向左两种状态
        while(!st.empty())
        {
            int size = st.size();
            stack<TreeNode*> tmp;
            vector<int> t;
            
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = st.top();
                st.pop();

                if(ret&1)//从左向右
                {
                    if(node->left) tmp.push(node->left);
                    if(node->right) tmp.push(node->right);
                }
                else
                {
                    if(node->right) tmp.push(node->right);
                    if(node->left) tmp.push(node->left);
                }

                t.push_back(node->val);
            }
            ret = !ret;//下一次从右向左
            ans.push_back(t);
            st=tmp;
        }
        return ans;
    }
};
