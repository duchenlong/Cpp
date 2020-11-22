#include <iostream>

using namespace std;

const int N = 1e5 + 10;
// f[0 - N] A,B,C 同类之间的关系
// f[N - N * 2] A吃B B吃C C吃A 捕食关系
// f[N * 2 - N * 3] 不能吃的集合
int f[N * 3];
int n,k;

int find(const int x) {
    if(f[x] != x) return f[x] = find(f[x]);
    return f[x];
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n * 3; i++) f[i] = i;
    
    int ans = 0;
    while(k --) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(b > n || c > n) {
            ans++;
            continue;
        }
        
        if(a == 1) {        // b and c
            if(find(b) == find(c + n) || find(b) == find(c + n * 2)) {        // b eat c     c eat b
                ans++;
                continue;
            }
            
            f[find(b)] = find(c);             // b and c
            f[find(b + n)] = find(c + n);
            f[find(b + n * 2)] = find(c + n * 2);
            
        } else if(a == 2) { // b eat c
            if(find(b) == find(c) || find(b) == find(c + n)) {            // b and c     c eat b
                ans++;
                continue;
            }     

            f[find(b)] = find(c + n * 2);       // b 的同类是 c 的天敌
            f[find(b + n)] = find(c);           // b 可以吃掉 c
            f[find(b + n * 2)] = find(c + n);   // c 可以吃掉 b 的天敌
        }
    }
    
    cout << ans ;
    return 0;
}

动物王国中有三类动物A,B,C，这三类动物的食物链构成了有趣的环形。

A吃B， B吃C，C吃A。

现有N个动物，以1－N编号。

每个动物都是A,B,C中的一种，但是我们并不知道它到底是哪一种。

有人用两种说法对这N个动物所构成的食物链关系进行描述：

第一种说法是”1 X Y”，表示X和Y是同类。

第二种说法是”2 X Y”，表示X吃Y。

此人对N个动物，用上述两种说法，一句接一句地说出K句话，这K句话有的是真的，有的是假的。

当一句话满足下列三条之一时，这句话就是假话，否则就是真话。

1） 当前的话与前面的某些真的话冲突，就是假话；
2） 当前的话中X或Y比N大，就是假话；
3） 当前的话表示X吃X，就是假话。

你的任务是根据给定的N和K句话，输出假话的总数。

输入格式
第一行是两个整数N和K，以一个空格分隔。

以下K行每行是三个正整数 D，X，Y，两数之间用一个空格隔开，其中D表示说法的种类。

若D=1，则表示X和Y是同类。

若D=2，则表示X吃Y。

输出格式
只有一个整数，表示假话的数目。

数据范围
1≤N≤50000,
0≤K≤100000
输入样例：
100 7
1 101 1 
2 1 2
2 2 3 
2 3 3 
1 1 3 
2 3 1 
1 5 5
输出样例：
3
