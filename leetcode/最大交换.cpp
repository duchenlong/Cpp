
给定一个非负整数，你至多可以交换一次数字中的任意两位。返回你能得到的最大值。

示例 1 :

输入: 2736
输出: 7236
解释: 交换数字2和数字7。
示例 2 :

输入: 9973
输出: 9973
解释: 不需要交换。
注意:

给定数字的范围是?[0, 108]


class Solution {
public:
    int maximumSwap(int num) {
        string cur = to_string(num);
        string tmp(cur);
        int n = cur.size();

        sort(tmp.begin(),tmp.end(),[](const char a,const char b)->bool{
            return a > b;
        });

        int p = -1;//第一个不合的位置
        for(int i = 0; i < n; i++) {
            if(tmp[i] != cur[i]) {
                p = i;
                break;
            }
        }

        if(p == -1) return num;

        for(int i = n-1; i > p; i--) {
            if(cur[i] == tmp[p]) {
                swap(cur[i],cur[p]);
                break;
            }
        }
        return stoi(cur);
    }
};
