输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如，序列 {1,2,3,4,5} 是某栈的压栈序列，
序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，
但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

?

示例 1：

输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
示例 2：

输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。
?

提示：

0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed?是?popped?的排列。


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int lenle = pushed.size();
        int lenri = popped.size();

        stack<int> st;
        int r = 0;
        //记录入栈的顺序，如果poped中 r 位置的数字一样，就出栈
        for(int i = 0; i < lenle; i++)
        {
            st.push(pushed[i]);
            while(!st.empty() && st.top() == popped[r])
            {
                r++;
                st.pop();
            }
        }

        //此时栈的出栈顺序一定是和poped 从 r开始遍历的顺序一样的
        for(int i = r; i < lenri; i++)
        {
            if(st.top() != popped[i])   return false;
            st.pop();
        }
        return true;
    }
};
