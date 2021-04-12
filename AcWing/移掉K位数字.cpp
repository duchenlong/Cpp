#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

string s;
int k;

int main() {
    cin >> s;
    cin >> k;
    
    stack<char> st;
    for(int i = 0; i < s.size(); i ++) {
        while(st.size() && k && st.top() > s[i]) {
            k --;
            st.pop();
        }
        st.push(s[i]);
    }
    
    while(k) {
        k --;
        st.pop();
    }
    
    string res("");
    while(st.size()) {
        res += st.top();
        st.pop();
    }
    res += "0";
    while(res.size() > 1 && res.back() == '0')
        res.pop_back();
    
    reverse(res.begin(),res.end());
    cout << res << endl;
    return 0;
}


给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。

注意：

空字符串被视为0。
如果结果中包含前导零，则需要将前导零删除，最后删除的前导零不用包含在移除的 k 个数字中。
输入格式
第一行输入一个字符串，用来表示非负整数 num。

第二行输入一个整数，表示 k。

输出格式
输出一个字符串，表示移除 k 位数字后所能得到的最小数字。

数据范围
0≤k≤ 字符串长度 ≤100000，
num 中不包含任何前导 0。

输入样例1：
1432219
3
输出样例1：
1219
样例1解释
移除掉三个数字 4,3,2 可形成一个新的最小的数字 1219。

输入样例2：
10200
1
输出样例2：
200
样例2解释：
移掉首位的 1 剩下的数字为 200. 注意输出不能有任何前导零。

输入样例3：
10
2
输出样例3：
0
样例3解释
从原数字移除所有的数字，剩余为空就是 0。
