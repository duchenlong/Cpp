#include <iostream>
#include <algorithm>
using namespace std;

const int N = 210;
int le[N], ri[N], f[N], n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> f[i];
    
    for(int i = 0; i < n; i++) {
        le[i] = 1;
        for(int j = 0; j < i; j++) if(f[j] < f[i]) le[i] = max(le[i],le[j] + 1);
    }
    
    for(int i = n - 1; i >= 0; i--) {
        ri[i] = 1;
        for(int j = n - 1; j > i; j--) if(f[j] < f[i]) ri[i] = max(ri[i],ri[j] + 1);
    }
    
    int res = 0;
    for(int i = 0; i < n; i++) res = max(res,le[i] + ri[i] - 1);
    cout << n - res << endl;
    return 0;
}


N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。?????

合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK，??则他们的身高满足T1<…<Ti>Ti+1>…>TK(1≤i≤K)。?????

你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

输入格式
输入的第一行是一个整数N，表示同学的总数。

第二行有n个整数，用空格分隔，第i个整数Ti是第i位同学的身高(厘米)。

输出格式
输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。

数据范围
2≤N≤100,
130≤Ti≤230
输入样例：
8
186 186 150 200 160 130 197 220
输出样例：
4
