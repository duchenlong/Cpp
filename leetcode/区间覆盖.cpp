#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
struct goods {
    int l,r;
    bool operator<(const goods& t) const {
        return l < t.l;
    }
}e[N];
int n;
int st,ed;

int main() {
    scanf("%d%d",&st,&ed);
    scanf("%d",&n);
    
    for(int i = 0; i < n; i ++) {
        scanf("%d%d",&e[i].l,&e[i].r);
    }
    sort(e,e+n);
    
    int res = 0, sucess = 0;
    for(int i = 0; i < n && st < ed; i++) {
        int j = i, ri = -2e9;
        while(j < n && e[j].l <= st) {
            ri = max(ri, e[j].r);
            j ++;
        }
        
        if(ri < st) {
            sucess = 1;
            break;
        }
        
        res ++;
        st = ri;
        i = j - 1;
    }
    
    if(sucess || (st < ed)) printf("-1\n");
    else printf("%d\n",res);
    
    return 0;
}

给定N个闭区间[ai,bi]以及一个线段区间[s,t]，请你选择尽量少的区间，将指定线段区间完全覆盖。

输出最少区间数，如果无法完全覆盖则输出-1。

输入格式
第一行包含两个整数s和t，表示给定线段区间的两个端点。

第二行包含整数N，表示给定区间数。

接下来N行，每行包含两个整数ai,bi，表示一个区间的两个端点。

输出格式
输出一个整数，表示所需最少区间数。

如果无解，则输出-1。

数据范围
1≤N≤105,
?109≤ai≤bi≤109,
?109≤s≤t≤109
输入样例：
1 5
3
-1 3
2 4
3 5
输出样例：
2
