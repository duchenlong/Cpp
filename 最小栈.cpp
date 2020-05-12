//设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

//push(x) —— 将元素 x 推入栈中。
//pop()?—— 删除栈顶的元素。
//top()?—— 获取栈顶元素。
//getMin() —— 检索栈中的最小元素。
//?

//示例:

//输入：
//["MinStack","push","push","push","getMin","pop","top","getMin"]
//[[],[-2],[0],[-3],[],[],[],[]]

//输出：
//[null,null,null,null,-3,null,0,-2]

//解释：
//MinStack minStack = new MinStack();
//minStack.push(-2);
//minStack.push(0);
//minStack.push(-3);
//minStack.getMin();   --> 返回 -3.
//minStack.pop();
//minStack.top();      --> 返回 0.
//minStack.getMin();   --> 返回 -2.



//辅助栈的写法
class MinStack1 {
public:
    /** initialize your data structure here. */
    MinStack1() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        num_stack.push(x);
        if(x <= min_stack.top()) min_stack.push(x);
    }
    
    void pop() {
        if(num_stack.top() == min_stack.top()) min_stack.pop();
        num_stack.pop();
    }
    
    int top() {
        return num_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
private:
    stack<int> num_stack;
    stack<int> min_stack;
};

//一个栈
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        Node n(INT_MAX,INT_MAX);
        num_stack.push(n);
    }
    
    void push(int x) {
        Node n(x,num_stack.top()._min);
        num_stack.push(n);
    }
    
    void pop() {
        num_stack.pop();
    }
    
    int top() {
        return num_stack.top()._val;
    }
    
    int getMin() {
        return num_stack.top()._min;
    }
private:
    struct Node
    {
        int _val;
        int _min;

        Node(int val,int min)
        {
            _val = val;
            if(min <= val) _min = min;
            else _min = val;
        }
    };
    
    stack<Node> num_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
