用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead?操作返回 -1 )

?

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]


class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        push_st.push(value);
    }
    
    int deleteHead() {
        int ans = 0;
        if(!pop_st.empty())
        {
            ans = pop_st.top();
            pop_st.pop();
        }
        else
        {
            if(push_st.empty()) return -1;
            while(push_st.size() != 1)
            {
                int t = push_st.top();
                pop_st.push(t);
                push_st.pop();
            }
            ans = push_st.top();
            push_st.pop();
        }
        return ans;
    }
private:
    stack<int> push_st;
    stack<int> pop_st;
};

