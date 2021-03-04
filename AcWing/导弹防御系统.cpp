#include <iostream>
#include <algorithm>

using namespace std;

const int N = 55;
int f[N];
int up[N],down[N];
int n,res;

void dfs(int id,int su,int sd) {
    if(su + sd >= res) return ;
    if(id == n) {
        res = min(res,su + sd);
        return ;
    }
    
    // 放在上升子序列中
    int k = 0;
    while(k < su && up[k] < f[id])
        k++;
    int t = up[k];
    up[k] = f[id];
    dfs(id + 1, su + (k == su), sd);
    up[k] = t;
    
    // 放在下降子序列中
    k = 0;
    while(k < sd && down[k] > f[id])
        k ++;
    t = down[k];
    down[k] = f[id];
    dfs(id + 1,su, sd + (k == sd));
    down[k] = t;
}

int main() {
    while(cin >> n, n) {
        res = n;
        for(int i = 1; i <= n; i++)
            cin >> f[i];
        
        dfs(1,0,0);
        
        cout << res << endl;
    }
    
    return 0;
}

为了对抗附近恶意国家的威胁，R国更新了他们的导弹防御系统。

一套防御系统的导弹拦截高度要么一直 严格单调 上升要么一直 严格单调 下降。

例如，一套系统先后拦截了高度为3和高度为4的两发导弹，那么接下来该系统就只能拦截高度大于4的导弹。

给定即将袭来的一系列导弹的高度，请你求出至少需要多少套防御系统，就可以将它们全部击落。

输入格式
输入包含多组测试用例。

对于每个测试用例，第一行包含整数n，表示来袭导弹数量。

第二行包含n个不同的整数，表示每个导弹的高度。

当输入测试用例n=0时，表示输入终止，且该用例无需处理。

输出格式
对于每个测试用例，输出一个占据一行的整数，表示所需的防御系统数量。

数据范围
1≤n≤50
输入样例：
5
3 5 2 4 1
0 
输出样例：
2
样例解释
对于给出样例，最少需要两套防御系统。

一套击落高度为3,4的导弹，另一套击落高度为5,2,1的导弹。
