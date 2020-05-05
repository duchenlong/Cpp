

给定一个 N 叉树，返回其节点值的后序遍历。

 /*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    //递归
    vector<int> postorder(Node* root)
    {
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }

    void dfs(Node* root, vector<int>& ans)
    {
        if(!root)
            return ;
        for(auto& eoch : root->children)
            dfs(eoch,ans);
        ans.push_back(root->val);
    }
    //迭代
    vector<int> postorder1(Node* root) {
        vector<int> ans;
        if(!root)
            return ans;
        stack<Node*> st;
        st.push(root);

        while(!st.empty())
        {
            Node* top = st.top();
            for(size_t i = top->children.size(); i > 0; i--)
            {
                st.push(top->children[i-1]);
            }

            if(top->children.size() == 0)
            {
                ans.push_back(top->val);
                st.pop();
            }
                
            vector<Node*> tmp;
            top->children = tmp;
        }
        return ans;
    }
};
