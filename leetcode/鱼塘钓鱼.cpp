#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;
int c[N],s[N],d[N];
int speed[N];

int get(int id) {
    return max(0, c[id] - s[id] * speed[id]);
}

int check(int n,int T) {
    memset(speed,0x00,sizeof speed);
    
    int res = 0;
    for(int i = 1; i <= T; i++) {
        int t = 1;
        for(int j = 1; j <= n; j++)
            if(get(j) > get(t)) 
                t = j;
        res += get(t);
        speed[t] ++;
    }
    return res;
}

int main() {
    int n,t;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i < n; i++) {
        cin >> d[i];
        d[i] += d[i-1];
    }
    cin >> t;
    
    int res = 0;
    for(int i = 1; i <= n; i++)
        res = max(res, check(i,t - d[i - 1]));
    cout << res << endl;
}

有 N 个鱼塘排成一排，每个鱼塘中有一定数量的鱼，例如：N=5 时，如下表：

鱼塘编号	1	2	3	4	5
第1分钟能钓到的鱼的数量（1..1000）	10	14	20	16	9
每钓鱼1分钟钓鱼数的减少量（1..100)	2	4	6	5	3
当前鱼塘到下一个相邻鱼塘需要的时间（单位：分钟）	3	5	4	4	
即：在第 1 个鱼塘中钓鱼第 1 分钟内可钓到 10 条鱼，第 2 分钟内只能钓到 8 条鱼，……，第 5 分钟以后再也钓不到鱼了。

从第 1 个鱼塘到第 2 个鱼塘需要 3 分钟，从第 2 个鱼塘到第 3 个鱼塘需要 5 分钟，……

给出一个截止时间 T，设计一个钓鱼方案，从第 1 个鱼塘出发，希望能钓到最多的鱼。

假设能钓到鱼的数量仅和已钓鱼的次数有关，且每次钓鱼的时间都是整数分钟。

输入格式
共 5 行，分别表示：

第 1 行为 N；

第 2 行为第 1 分钟各个鱼塘能钓到的鱼的数量，每个数据之间用一空格隔开；

第 3 行为每过 1 分钟各个鱼塘钓鱼数的减少量，每个数据之间用一空格隔开；

第 4 行为当前鱼塘到下一个相邻鱼塘需要的时间；

第 5 行为截止时间 T。

输出格式
一个整数（不超过231?1），表示你的方案能钓到的最多的鱼。

数据范围
1≤N≤100,
1≤T≤1000
输入样例：
5
10 14 20 16 9
2 4 6 5 3
3 5 4 4
14
输出样例：
76
