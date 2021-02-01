#include <iostream>
using namespace std;

const int N = 35;
int w[N], f[N][N], g[N][N];
int n;

void dfs(int l,int r) {
    if(l > r) return ;
    cout << g[l][r] << " ";
    dfs(l,g[l][r]-1);
    dfs(g[l][r] + 1,r);
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> w[i];
    
    for(int len = 1; len <= n; len++)
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            
            if(l == r) {
                f[l][r] = w[l];
                g[l][r] = l;
            } else {
                for(int k = l; k <= r; k++) {
                    int left = (k == l) ? 1 : f[l][k - 1];
                    int right = (k == r) ? 1 : f[k + 1][r];
                    int score = left * right + w[k];
                    if(score > f[l][r]) {
                        f[l][r] = score;
                        g[l][r] = k;
                    }
                }
            }
        }
    
    cout << f[1][n] << endl;
    dfs(1,n);
    cout << endl;
    return 0;
}

设一个n个节点的二叉树tree的中序遍历为（1,2,3,…,n），其中数字1,2,3,…,n为节点编号。

每个节点都有一个分数（均为正整数），记第i个节点的分数为di，tree及它的每个子树都有一个加分，任一棵子树subtree（也包含tree本身）的加分计算方法如下：?????

subtree的左子树的加分 × subtree的右子树的加分 ＋ subtree的根的分数?

若某个子树为空，规定其加分为1。叶子的加分就是叶节点本身的分数，不考虑它的空子树。

试求一棵符合中序遍历为（1,2,3,…,n）且加分最高的二叉树tree。

要求输出：?

（1）tree的最高加分?

（2）tree的前序遍历

输入格式
第1行：一个整数n，为节点个数。?

第2行：n个用空格隔开的整数，为每个节点的分数（0<分数<100）。

输出格式
第1行：一个整数，为最高加分（结果不会超过int范围）。?????

第2行：n个用空格隔开的整数，为该树的前序遍历。如果存在多种方案，则输出字典序最小的方案。

数据范围
n<30
输入样例：
5
5 7 1 2 10
输出样例：
145
3 1 2 4 5
