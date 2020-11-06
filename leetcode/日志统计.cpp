#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct node{
    int time,id;
    bool operator<(const node& a) {
        return time < a.time;
    }
};

const int N = 1e5 + 10;
int n,d,k;
int x,y;
node f[N];
int ans[N],cnt[N],vis[N];
int e = 0;

void slove() {
    int le = 0;     // 开始时间段的数据下标
    for(int i = 0; i < n; i++) {
        while(f[le].time + d <= f[i].time) {
            cnt[f[le++].id]--;
        }
        cnt[f[i].id]++;

        if(cnt[f[i].id] >= k && vis[f[i].id] == 0) {
            ans[e++] = f[i].id;
            vis[f[i].id] = 1;
        }
    }
}

int main() {
    cin >> n >> d >> k;
    memset(cnt,0x00,sizeof cnt);
    memset(f,0x00,sizeof f);
    memset(ans,0x00,sizeof ans);
    memset(vis,0x00,sizeof vis);
    for(int i = 0; i < n; i++) scanf("%d %d",&f[i].time,&f[i].id);
    
    sort(f,f+n);        // 点赞时间从小到大排序
    
    //for(int i = 0; i < n; i++) printf("%d %d\n",f[i].time,f[i].id);
    slove();
    
    sort(ans,ans+e);
    for(int i = 0; i < e; i++) printf("%d\n",ans[i]);
    return 0;
}


小明维护着一个程序员论坛。现在他收集了一份”点赞”日志，日志共有 N 行。

其中每一行的格式是：

ts id  
表示在 ts 时刻编号 id 的帖子收到一个”赞”。

现在小明想统计有哪些帖子曾经是”热帖”。

如果一个帖子曾在任意一个长度为 D 的时间段内收到不少于 K 个赞，小明就认为这个帖子曾是”热帖”。

具体来说，如果存在某个时刻 T 满足该帖在 [T,T+D) 这段时间内(注意是左闭右开区间)收到不少于 K 个赞，该帖就曾是”热帖”。

给定日志，请你帮助小明统计出所有曾是”热帖”的帖子编号。

输入格式
第一行包含三个整数 N,D,K。

以下 N 行每行一条日志，包含两个整数 ts 和 id。

输出格式
按从小到大的顺序输出热帖 id。

每个 id 占一行。

数据范围
1≤K≤N≤105,
0≤ts,id≤105,
1≤D≤10000
输入样例：
7 10 2
0 1
0 10
10 10
10 1
9 1
100 3
100 3
输出样例：
1
3
难度：中等
时/空限制：1s / 64MB
总通过数：995
总尝试数：1963
来源：第九届蓝桥杯省赛C++B组
算法标签

