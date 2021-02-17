class unionFind{
    public:
        unionFind(int n) : f(n) {
            cnt = n;
            for(int i = 1; i < n; i++) f[i] = i;
        }

        int find(int x) {
            if(f[x] != x) f[x] = find(f[x]);
            return f[x]; 
        }

        bool merge(int a,int b) {
            a = find(a);
            b = find(b);
            if(a == b) return false;
            f[a] = b;
            cnt --;
            return true;
        }

        int get() {
            return cnt;
        }
    private:
        vector<int> f;
        int cnt;
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        unionFind uf(n / 2);

        for(int i = 0; i < n; i+=2) {
            uf.merge(row[i]/2,row[i+1]/2);
        }

        return n / 2 - uf.get();
    }
};
N 对情侣坐在连续排列的 2N 个座位上，想要牵到对方的手。 计算最少交换座位的次数，以便每对情侣可以并肩坐在一起。 一次交换可选择任意两人，让他们站起来交换座位。

人和座位用?0?到?2N-1?的整数表示，情侣们按顺序编号，第一对是?(0, 1)，第二对是?(2, 3)，以此类推，最后一对是?(2N-2, 2N-1)。

这些情侣的初始座位??row[i]?是由最初始坐在第 i 个座位上的人决定的。

示例 1:

输入: row = [0, 2, 1, 3]
输出: 1
解释: 我们只需要交换row[1]和row[2]的位置即可。
示例 2:

输入: row = [3, 2, 0, 1]
输出: 0
解释: 无需交换座位，所有的情侣都已经可以手牵手了。
说明:

len(row) 是偶数且数值在?[4, 60]范围内。
可以保证row 是序列?0...len(row)-1?的一个全排列。
通过次数19,138提交次数29,232

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/couples-holding-hands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
