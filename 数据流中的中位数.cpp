如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4]?的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例 1：

输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]
示例 2：

输入：
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
输出：[null,null,2.00000,null,2.50000]
?

限制：

最多会对?addNum、findMedia进行?50000?次调用。

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        bigQue = priority_queue<int,vector<int>,less<int> > ();
        smallQue = priority_queue<int,vector<int>,greater<int> > ();
    }
    
    void addNum(int num) {
        if(bigQue.size() == smallQue.size())
        {
            //取出num放入大顶堆后，大顶堆最小的元素
            bigQue.push(num);
            smallQue.push(bigQue.top());
            bigQue.pop();
            return ;
        }

        //两个堆元素数量不相等，大顶堆少一个元素
        smallQue.push(num);
        bigQue.push(smallQue.top());
        smallQue.pop();
    }
    
    double findMedian() {
        double ans = 0.0;

        if(bigQue.size() == smallQue.size())
            ans = (bigQue.top() + smallQue.top()) / 2.0;
        else
            ans = smallQue.top();
        return ans;
    }
private:
    priority_queue<int,vector<int>,less<int> > bigQue;
    priority_queue<int,vector<int>,greater<int> > smallQue;
};
