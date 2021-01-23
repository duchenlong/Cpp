#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

string str,s;
map<string,int> mp;
int n;

int main() {
    cin >> str >> n;
    while (n --) {
        cin >> s;
        sort(s.begin(),s.end());
        mp[s] ++;
    }
    
    int m = str.size();
    int res = 0;
    for(int i = 0; i <= m - 8; i++) {
        string t = str.substr(i,8);
        sort(t.begin(),t.end());
        res += mp[t];
    }
    cout << res << endl;
    return 0;
} 

福尔摩斯从 X 星收到一份资料，全部是小写字母组成。

他的助手提供了另一份资料：许多长度为 8 的密码列表。

福尔摩斯发现，这些密码是被打乱后隐藏在先前那份资料中的。

请你编写一个程序，从第一份资料中搜索可能隐藏密码的位置。

要考虑密码的所有排列可能性。

输入格式
第一行：一个字符串 s，全部由小写字母组成。

紧接着一行是一个整数 n，表示以下有 n 行密码。

紧接着是 n 行字符串，都是小写字母组成，长度都为 8。

输出格式
一个整数，表示每行密码的所有排列在 s 中匹配次数的总和。

数据范围
字符串 s 的长度不超过 220,
1≤n≤1000
输入样例：
aaaabbbbaabbcccc
2
aaaabbbb
abcabccc
输出样例：
4
样例解释
第一个密码匹配了 3 次，第二个密码匹配了 1 次，一共 4 次。
