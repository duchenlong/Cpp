#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 2e5 + 10;

int W[N],V[N];
int l[N],r[N];
LL sum[N],cnt[N];
LL n,m,s;

LL check(int w) {
    for(int i = 1; i <= n; i++)
        if(W[i] >= w) {
            sum[i] = sum[i-1] + V[i];
            cnt[i] = cnt[i-1] + 1;
        } else {
            sum[i] = sum[i-1];
            cnt[i] = cnt[i-1];
        }
    LL res = 0;
    for(int i = 0; i < m; i++)
        res += (cnt[r[i]] - cnt[l[i] - 1]) * (sum[r[i]] - sum[l[i] - 1]);
    return res;
}

int main() {
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) cin >> W[i] >> V[i];
    for(int i = 0; i < m; i++) cin >> l[i] >> r[i];
    
    int le = 0, ri = 1e6 + 10;
    while(le < ri) {
        int mid = le + ri + 1 >> 1;
        if(check(mid) >= s) le = mid;
        else ri = mid - 1;
    }
    
    cout << min(abs(s - check(ri)), abs(s - check(ri + 1))) << endl;
}

小?T?是一名质量监督员，最近负责检验一批矿产的质量。这批矿产共有?n?个矿石，从?1?到?n?逐一编号，每个矿石都有自己的重量?wi?以及价值?vi。

检验矿产的流程是：?

1、给定?m?个区间[Li，Ri]；?
2、选出一个参数?W；?
3、对于一个区间[Li，Ri]，计算矿石在这个区间上的检验值?Yi?：?

QQ截图20190314005531.png

这批矿产的检验结果?Y?为各个区间的检验值之和。

即：Y?=?Y1+Y2+…+Ym

若这批矿产的检验结果与所给标准值?S?相差太多，就需要再去检验另一批矿产。

小?T?不想费时间去检验另一批矿产，所以他想通过调整参数?W?的值，让检验结果尽可能的靠近标准值?S，即使得?S-Y?的绝对值最小。

请你帮忙求出这个最小值。

输入格式
第一行包含三个整数?n，m，S，分别表示矿石的个数、区间的个数和标准值。?

接下来的?n?行，每行?2?个整数，中间用空格隔开，第?i+1?行表示?i?号矿石的重量?wi?和价值?vi?。?

接下来的?m?行，表示区间，每行?2?个整数，中间用空格隔开，第?i+n+1?行表示区间[Li,?Ri]的两个端点?Li?和?Ri。

注意：不同区间可能重合或相互重叠。

输出格式
输出一个整数，表示所求的最小值。

数据范围
1≤n,m≤200000,
0<wi,vi≤106,
0<S≤1012,
1≤Li≤Ri≤n
输入样例：
5 3 15 
1 5 
2 5 
3 5 
4 5 
5 5 
1 5 
2 4 
3 3 
输出样例：
10
