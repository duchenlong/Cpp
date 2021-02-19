#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n;
int f[N];

bool check(int m) {
    for(int i = 1; i <= n; i++) {
        // if(f[i] > m) 
        //     m -= f[i] - m;
        // else 
        //     m += m - f[i];
        m += m - f[i];
        if(m > 1e5) return true;
        if(m < 0) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> f[i];
    
    int le = 0, ri = 1e5;
    while(le < ri) {
        int mid = le + ri >> 1;
        if(check(mid)) ri = mid;
        else le = mid + 1;
        
        //cout << le << " " << ri << endl;
    }
    
    cout << le << endl;
    return 0;
}


机器人正在玩一个古老的基于DOS的游戏。

游戏中有N+1座建筑——从0到N编号，从左到右排列。

编号为0的建筑高度为0个单位，编号为 i 的建筑高度为H(i)个单位。

起初，机器人在编号为0的建筑处。

每一步，它跳到下一个（右边）建筑。

假设机器人在第k个建筑，且它现在的能量值是E，下一步它将跳到第k+1个建筑。

如果H(k+1)>E，那么机器人就失去H(k+1)-E的能量值，否则它将得到E-H(k+1)的能量值。

游戏目标是到达第N个建筑，在这个过程中能量值不能为负数个单位。

现在的问题是机器人至少以多少能量值开始游戏，才可以保证成功完成游戏？

输入格式
第一行输入整数N。

第二行是N个空格分隔的整数，H(1),H(2),…,H(N)代表建筑物的高度。

输出格式
输出一个整数，表示所需的最少单位的初始能量值上取整后的结果。

数据范围
1≤N,H(i)≤105,

输入样例1：
5
3 4 3 2 4
输出样例1：
4
输入样例2：
3
4 4 4
输出样例2：
4
输入样例3：
3
1 6 4
输出样例3：
3
