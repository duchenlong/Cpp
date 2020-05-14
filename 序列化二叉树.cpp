//请实现两个函数，分别用来序列化和反序列化二叉树。

//示例:?

//你可以将以下二叉树：

//    1
//   / \
//  2   3
//     / \
//    4   5

//序列化为 "[1,2,3,null,null,4,5]"




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "[]";
        queue<TreeNode*> que;
        que.push(root);
        string tmp("[");
        while(!que.empty())
        {
            int size = que.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();

                if(node)
                {
                    tmp += to_string(node->val) + ',';
                    que.push(node->left);
                    que.push(node->right);
                } 
                else 
                    tmp += "null,";
            }
        }
        int end = tmp.size()-1;
        while(tmp[end]>'9'||tmp[end]<'0')
            tmp.erase(end--);
        //cout<<tmp<<endl;
        return tmp+']';
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "[]") return NULL;
        queue<TreeNode*> que;
        TreeNode* root;
        int p = 1;
        int len = data.size() - 1;
 
        while(p < len)
        {
            if(que.empty())
            {
                if(data[p] == 'n') return NULL;
                int num = SToN(data,p,len);
                root = new TreeNode(num);

                que.push(root);
                p++;
            }
            else
            {
                int size = que.size();

                for(int i = 0; i < size; i++)
                {
                    TreeNode* node = que.front();
                    que.pop();

                    if(p < len)
                    {
                        if(data[p] == 'n')
                            p += 5;
                        else
                        {
                            TreeNode* left = new TreeNode(SToN(data,p,len));
                            node->left = left;
                            que.push(left);
                            p++;
                        }
                    }
                    
                    if(p < len)
                    {
                        if(data[p] == 'n')
                            p += 5;
                        else
                        {
                            TreeNode* right = new TreeNode(SToN(data,p,len));
                            que.push(right);
                            node->right=right;
                            p++;
                        }
                    }
                }
            } 
        }
        return root;
    }

    int SToN(string& data,int& i,int len)
    {
        int p = i;
        if(data[i] == '-') i++;
        int num = 0;
        for(; i <= len; i++)
        {
            if(data[i]==',' || data[i]==']')
                return data[p]=='-'?0-num:num;
            num = num * 10 + data[i]-'0';
        }
        return num;
    }
};
