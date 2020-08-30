假设你正在读取一串整数。每隔一段时间，你希望能找出数字 x 的秩(小于或等于 x 的值的个数)。请实现数据结构和算法来支持这些操作，也就是说：

实现 track(int x)?方法，每读入一个数字都会调用该方法；

实现 getRankOfNumber(int x) 方法，返回小于或等于 x 的值的个数。

注意：本题相对原题稍作改动

示例:

输入:
["StreamRank", "getRankOfNumber", "track", "getRankOfNumber"]
[[], [1], [0], [0]]
输出:
[null,0,null,1]
提示：

x <= 50000
track?和?getRankOfNumber 方法的调用次数均不超过 2000 次

class StreamRank {
public:
    struct node{
        int _data;
        node* _left;
        node* _right;
        int _num;

        node(int data){
            _data = data;
            _left = _right = nullptr;
            _num = 1;
        }
    };

    StreamRank() {
        _root = nullptr;
    }
    
    //insert
    void track(int x) {
        insert(_root,x);
    }
    
    //find
    int getRankOfNumber(int x) {
        return find(_root,x);
    }
private:
    void insert(node*& root,int x){
        if(root == nullptr){
            root = new node(x);
            return ;
        }

        if(root->_data == x){
            root->_num++;
        }else if(root->_data < x){
            insert(root->_right,x);
        }else if(root->_data > x){
            root->_num++;
            insert(root->_left,x);
        }
    }

    int find(node* root,int x){
        if(root == nullptr){
            return 0;
        }

        if(root->_data == x){
            return root->_num;
        }

        if(root->_data < x){
            return find(root->_right,x) + root->_num;
        }
        
        //root->_data > x
        return find(root->_left,x);
    }
private:
    node* _root;
};
