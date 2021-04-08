#include <iostream>
#include <stack>

using namespace std;

const int N = 30;
int f[N];
int n,m;
struct node {
    int id,cur,len,state;
};

void dfs(int id,int cur,int len) {
    if(len == m) {
        for(int i = 0; i < len; i++)
            cout << f[i] << " ";
        cout << endl;
        return ;
    }
    
    for(int i = cur; i <= n; i++) {
        f[id] = i;
        dfs(id + 1,i + 1, len + 1);
    }
}

int main() {
    cin >> n >> m;
    // dfs(0,1,0);
    
    stack<node> st;
    st.push({0,1,0,0});
    
    while(st.size()) {
        node t = st.top();
        st.pop();
        
        int id= t.id, cur = t.cur, len = t.len;
        int state = t.state;
        
        if(len == m) {
            for(int i = 1; i <= n; i++)
                if((state >> i) & 1)
                    cout << i << " ";
            cout << endl;
            continue;
        }
        
        for(int i = n; i >= cur; i--) {
            st.push({t.id + 1,i + 1,len + 1,state | (1 << i)});
        }
    }
    
    return 0;
}

从 1～n 这 n 个整数中随机选出 m 个，输出所有可能的选择方案。

输入格式
两个整数 n,m ,在同一行用空格隔开。

输出格式
按照从小到大的顺序输出所有方案，每行 1 个。

首先，同一行内的数升序排列，相邻两个数用一个空格隔开。

其次，对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面（例如 1 3 5 7 排在 1 3 6 8 前面）。

数据范围
n>0 ,
0≤m≤n ,
n+(n?m)≤25
输入样例：
5 3
输出样例：
1 2 3 
1 2 4 
1 2 5 
1 3 4 
1 3 5 
1 4 5 
2 3 4 
2 3 5 
2 4 5 
3 4 5 
思考题：如果要求使用非递归方法，该怎么做呢？
