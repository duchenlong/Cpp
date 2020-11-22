class TripleInOne {
public:
    TripleInOne(int stackSize) {
        arr.resize(stackSize * 3,0);
        cnt = {-3,-2,-1};
    }

    
    void push(int stackNum, int value) {
        if(cnt[stackNum] + 3 >= arr.size()) return ;

        cnt[stackNum] += 3;
        arr[cnt[stackNum]] = value;
    }
    
    int pop(int stackNum) {
        if(cnt[stackNum] < 0) return -1;

        int top = arr[cnt[stackNum]];
        cnt[stackNum] -= 3;
        return top;
    }
    
    int peek(int stackNum) {
        if(cnt[stackNum] < 0) return -1;
        
        return arr[cnt[stackNum]];
    }
    
    bool isEmpty(int stackNum) {
        return cnt[stackNum] < 0;
    }
private:
    vector<int> arr;
    vector<int> cnt;
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
 
 
 三合一。描述如何只用一个数组来实现三个栈。

你应该实现push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum)方法。stackNum表示栈下标，value表示压入的值。

构造函数会传入一个stackSize参数，代表每个栈的大小。

示例1:

 输入：
["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
[[1], [0, 1], [0, 2], [0], [0], [0], [0]]
 输出：
[null, null, null, 1, -1, -1, true]
说明：当栈为空时`pop, peek`返回-1，当栈满时`push`不压入元素。
示例2:

 输入：
["TripleInOne", "push", "push", "push", "pop", "pop", "pop", "peek"]
[[2], [0, 1], [0, 2], [0, 3], [0], [0], [0], [0]]
 输出：
[null, null, null, null, 2, 1, -1, -1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/three-in-one-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
