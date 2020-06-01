//请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

//若队列为空，pop_front 和 max_value?需要返回 -1

//示例 1：

//输入: 
//["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
//[[],[1],[2],[],[],[]]
//输出:?[null,null,null,2,1,2]
//示例 2：

//输入: 
//["MaxQueue","pop_front","max_value"]
//[[],[],[]]
//输出:?[null,-1,-1]
//?

//限制：

//1 <= push_back,pop_front,max_value的总操作数?<= 10000
//1 <= value <= 10^5


class MaxQueue {
public:
    MaxQueue() {
    }
    
    int max_value() {
        return max_que.empty() ? -1 : max_que.front();
    }
    
    void push_back(int value) {
        que.push(value);
        //从后向前，把小的值弹出去 
        while(!max_que.empty() && value > max_que.back())
            max_que.pop_back();
        max_que.push_back(value);       
    }
    
    int pop_front() {
        if(que.empty()) return -1;
        int value = que.front();
        que.pop();
        
        if(value == max_que.front()) max_que.pop_front();

        return value;
    }
private:
    deque<int> max_que;
    queue<int> que;
};
