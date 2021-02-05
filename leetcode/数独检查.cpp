#include <iostream>
#include <cstring>

using namespace std;

const int N = 40;
int r[N][N],c[N][N],d[N][N],f[N][N],T,n,m;

bool check() {
    memset(r,0x00,sizeof r);
    memset(c,0x00,sizeof c);
    memset(d,0x00,sizeof d);
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++) {
            int num = f[i][j];
            if(num < 1 || num > m) return false;
            if(r[i][num] || c[j][num]) return false;
            int x = i / n, y = j / n;
            int id = x * n + y;
            if(d[id][num]) return false;
            r[i][num] = c[j][num] = d[id][num] = 1;
        }
    return true;
}

int main() {
    cin >> T;
    int k = 1;
    while(T --) {
        cin >> n;
        m = n * n;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < m; j++)
                cin >> f[i][j];
        
        
        if(check()) printf("Case #%d: Yes",k);
        else printf("Case #%d: No",k);
        
        puts("");
        k++;
    }
    return 0;
}


数独是一种流行的单人游戏。

目标是用数字填充9x9矩阵，使每列，每行和所有9个非重叠的3x3子矩阵包含从1到9的所有数字。

每个9x9矩阵在游戏开始时都会有部分数字已经给出，通常有一个独特的解决方案。

1.png

2.png

给定完成的N2?N2数独矩阵，你的任务是确定它是否是有效的解决方案。

有效的解决方案必须满足以下条件：

每行包含从1到N2的每个数字，每个数字一次。
每列包含从1到N2的每个数字，每个数字一次。
将N2?N2矩阵划分为N2个非重叠N?N子矩阵。 每个子矩阵包含从1到N2的每个数字，每个数字一次。
你无需担心问题的唯一性，只需检查给定矩阵是否是有效的解决方案即可。

输入格式
第一行包含整数T，表示共有T组测试数据。

每组数据第一行包含整数N。

接下来N2行，每行包含N2个数字（均不超过1000），用来描述完整的数独矩阵。

输出格式
每组数据输出一个结果，每个结果占一行。

结果表示为“Case #x: y”，其中x是组别编号（从1开始），如果给定矩阵是有效方案则y是Yes，否则y是No。

数据范围
1≤T≤100,
3≤N≤6
输入样例：
3
3
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
3
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
1 2 3 4 5 6 7 8 9
3
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 999 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
输出样例：
Case #1: Yes
Case #2: No
Case #3: No
