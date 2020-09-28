/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return root;
        queue<Node*> que;
        que.push(root);

        while(que.empty() == false) {
            Node* pre = que.front();
            int size = que.size();
            
            for(int i = 0; i < size; i++) {
                Node* f = que.front();
                que.pop();
                if(f->left != nullptr)  que.push(f->left);
                if(f->right != nullptr) que.push(f->right);

                if(i != size-1) {
                    Node* preNext = que.front();
                    pre->next = preNext;
                    pre = preNext;
                }
            }
        }

        return root;
    } 
};

给定一个二叉树

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有?next 指针都被设置为 NULL。

?

进阶：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
?

示例：



输入：root = [1,2,3,4,5,null,7]
输出：[1,#,2,3,#,4,5,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
?

提示：

树中的节点数小于 6000
-100?<= node.val <= 100
?

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
