实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。

调用 next() 将返回二叉搜索树中的下一个最小的数。

?

示例：



BSTIterator iterator = new BSTIterator(root);
iterator.next();    // 返回 3
iterator.next();    // 返回 7
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 9
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 15
iterator.hasNext(); // 返回 true
iterator.next();    // 返回 20
iterator.hasNext(); // 返回 false
?

提示：

next()?和?hasNext()?操作的时间复杂度是?O(1)，并使用?O(h) 内存，其中?h?是树的高度。
你可以假设?next()?调用总是有效的，也就是说，当调用 next()?时，BST 中至少存在一个下一个最小的数。。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        //初始化，迭代器数组的最后一个数据是最小节点的位置
        TreeNode* cur = root;
        while(cur != nullptr)
        {
            Tnode.push(cur);
            cur = cur->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* ret = Tnode.top();
        Tnode.pop();
        
        //如果ret的右节点存在，找右节点中最小的一个数,将这些数入栈
        if(ret->right != nullptr)
        {
            TreeNode* cur = ret->right;
            while(cur != nullptr)
            {
                Tnode.push(cur);
                cur = cur->left;
            }
        }
        
        //右节点不存在，需要向上查找没有被访问的节点,也就是栈顶元素
        return ret->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !Tnode.empty();
    }
private:
    stack<TreeNode*> Tnode;//栈顶元素为下一个最小的节点
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
