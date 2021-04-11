class MKAverage {
public:
    typedef long long LL;
    MKAverage(int _m, int _k) {
        m = _m;
        k = _k;
    }
    
    void addElement(int num) {
        f.push_back(num);
        int n = f.size();

        if(n < m)
            return ;
        
        if(n == m) {
            auto q = f;
            sort(q.begin(),q.end());
            for(int i = 0; i < k; i ++) 
                le.insert(q[i]);
            
            for(int i = k; i < m - k; i ++)
                mid.insert(q[i]);
            
            for(int i = m - k; i < m; i ++)
                ri.insert(q[i]);

            return ;
        }

        // n > m
        insert(num);
        del(f[n - 1 - m]);
    }
    
    int calculateMKAverage() {
        int n = f.size();
        if(n < m)
            return -1;
        
        return mid.sum / (m - 2 * k);
    }
private:
    void insert(int x) {
        mid.insert(x);
        if(*mid.st.begin() < *le.st.rbegin()) {
            int a = *mid.st.begin(), b = *le.st.rbegin();
            mid.remove(a);
            le.remove(b);
            mid.insert(b);
            le.insert(a);
        }

        if(*mid.st.rbegin() > *ri.st.begin()) {
            int a = *mid.st.rbegin(), b = *ri.st.begin();
            mid.remove(a);
            mid.insert(b);
            ri.remove(b);
            ri.insert(a);
        }
    }

    void del(int x) {
        if(mid.st.count(x)) {
            mid.remove(x);
        } else if(le.st.count(x)) {
            le.remove(x);
            int t = *mid.st.begin();
            le.insert(t);
            mid.remove(t);
        } else if(ri.st.count(x)) {
            ri.remove(x);
            int t = *mid.st.rbegin();
            ri.insert(t);
            mid.remove(t);
        }
    }

private:
    struct node {
        multiset<int> st;
        LL sum = 0;

        void insert(int x) {
            st.insert(x);
            sum += x;
        }

        void remove(int x) {
            st.erase(st.find(x));
            sum -= x;
        }
    };
private:
    int m,k;
    node le,mid,ri;
    vector<int> f;
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
 
 
 给你两个整数?m?和?k?，以及数据流形式的若干整数。你需要实现一个数据结构，计算这个数据流的 MK 平均值?。

MK 平均值?按照如下步骤计算：

如果数据流中的整数少于 m?个，MK 平均值?为 -1?，否则将数据流中最后 m?个元素拷贝到一个独立的容器中。
从这个容器中删除最小的 k?个数和最大的 k?个数。
计算剩余元素的平均值，并 向下取整到最近的整数?。
请你实现?MKAverage?类：

MKAverage(int m, int k)?用一个空的数据流和两个整数 m?和 k?初始化?MKAverage?对象。
void addElement(int num)?往数据流中插入一个新的元素?num?。
int calculateMKAverage()?对当前的数据流计算并返回 MK 平均数?，结果需 向下取整到最近的整数 。
?

示例 1：

输入：
["MKAverage", "addElement", "addElement", "calculateMKAverage", "addElement", "calculateMKAverage", "addElement", "addElement", "addElement", "calculateMKAverage"]
[[3, 1], [3], [1], [], [10], [], [5], [5], [5], []]
输出：
[null, null, null, -1, null, 3, null, null, null, 5]

解释：
MKAverage obj = new MKAverage(3, 1); 
obj.addElement(3);        // 当前元素为 [3]
obj.addElement(1);        // 当前元素为 [3,1]
obj.calculateMKAverage(); // 返回 -1 ，因为 m = 3 ，但数据流中只有 2 个元素
obj.addElement(10);       // 当前元素为 [3,1,10]
obj.calculateMKAverage(); // 最后 3 个元素为 [3,1,10]
                          // 删除最小以及最大的 1 个元素后，容器为 [3]
                          // [3] 的平均值等于 3/1 = 3 ，故返回 3
obj.addElement(5);        // 当前元素为 [3,1,10,5]
obj.addElement(5);        // 当前元素为 [3,1,10,5,5]
obj.addElement(5);        // 当前元素为 [3,1,10,5,5,5]
obj.calculateMKAverage(); // 最后 3 个元素为 [5,5,5]
                          // 删除最小以及最大的 1 个元素后，容器为 [5]
                          // [5] 的平均值等于 5/1 = 5 ，故返回 5
?

提示：

3 <= m <= 105
1 <= k*2 < m
1 <= num <= 105
addElement 与?calculateMKAverage?总操作次数不超过 105 次

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/finding-mk-average
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
