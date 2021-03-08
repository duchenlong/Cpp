#include <iostream>
#include <algorithm>

using namespace std;

const int N = 6010;
int f[N];
int n,m;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int v,w,s;
        cin >> v >> w >> s;
        
        for(int j = m; j >= v; j--)
            for(int cnt = 1; cnt <= s && j >= cnt * v; cnt ++)
                f[j] = max(f[j],f[j - cnt * v] + cnt * w);
    }
    
    cout << f[m] << endl;
    return 0;
}


为了庆贺班级在校运动会上取得全校第一名成绩，班主任决定开一场庆功会，为此拨款购买奖品犒劳运动员。

期望拨款金额能购买最大价值的奖品，可以补充他们的精力和体力。

输入格式
第一行二个数n，m，其中n代表希望购买的奖品的种数，m表示拨款金额。

接下来n行，每行3个数，v、w、s，分别表示第I种奖品的价格、价值（价格与价值是不同的概念）和能购买的最大数量（买0件到s件均可）。

输出格式
一行：一个数，表示此次购买能获得的最大的价值（注意！不是价格）。

数据范围
n≤500,m≤6000,
v≤100,w≤1000,s≤10
输入样例：
5 1000
80 20 4
40 50 9
30 50 7
40 30 6
20 20 1
输出样例：
1040
