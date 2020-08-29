题中给出一个 n_rows 行 n_cols 列的二维矩阵，且所有值被初始化为 0。要求编写一个 flip 函数，均匀随机的将矩阵中的 0 变为 1，并返回该值的位置下标 [row_id,col_id]；同样编写一个 reset 函数，将所有的值都重新置为 0。尽量最少调用随机函数 Math.random()，并且优化时间和空间复杂度。

注意:

1 <= n_rows, n_cols <= 10000
0 <= row.id < n_rows 并且 0 <= col.id < n_cols
当矩阵中没有值为 0 时，不可以调用 flip 函数
调用 flip 和 reset 函数的次数加起来不会超过 1000 次
示例 1：

输入: 
["Solution","flip","flip","flip","flip"]
[[2,3],[],[],[],[]]
输出: [null,[0,1],[1,2],[1,0],[1,1]]
示例 2：

输入: 
["Solution","flip","flip","reset","flip"]
[[1,2],[],[],[],[]]
输出: [null,[0,0],[0,1],null,[0,0]]
输入语法解释：

输入包含两个列表：被调用的子程序和他们的参数。Solution 的构造函数有两个参数，分别为 n_rows 和 n_cols。flip?和 reset 没有参数，参数总会以列表形式给出，哪怕该列表为空


class Solution {
public:
    Solution(int n_rows, int n_cols) {
        _n = n_rows;
        _m = n_cols;
        _num = _n * _m;
    }
    
    vector<int> flip() {
        if(_num == 0) return {};

        int mul = _n * _m;
        while(true){
            int idx = rand() % mul;
            if(_set.count(idx) > 0){
                continue;
            }

            int x = idx / _m;
            int y = idx % _m;
            _set.insert(idx);
            return {x,y};
        }
    }
    
    void reset() {
        _num = _n * _m;
        _set.clear();
    }
private:
    unordered_set<int> _set;
    int _n;
    int _m;
    int _num;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
