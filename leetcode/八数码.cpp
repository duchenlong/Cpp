#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

string start;
int dir[4][2] = {1,0,-1,0,0,1,0,-1};

int bfs() {
    string end = "12345678x";
    
    queue<string> que;
    que.push(start);
    unordered_map<string,int> mp;
    mp[start] = 0;
    
    while(!que.empty()) {
        auto f = que.front();
        que.pop();
        
        int dis = mp[f];
        if(f == end) return dis;
        
        int p = f.find('x');
        int x = p / 3, y = p % 3;
        
        for(int i = 0; i < 4; i++) {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            
            if(tx < 0 || tx >= 3 || ty < 0 || ty >= 3) continue;
            
            string t = f;
            swap(t[p],t[tx*3 + ty]);
            if(mp.count(t)) continue;
            
            que.push(t);
            mp[t] = dis + 1;
        }
    }
    
    return -1;
}

int main() {
    char ch;
    for(int i = 0; i < 9; i++) {
        cin >> ch;
        start += ch;
    }
    
    cout << bfs() << endl;
    return 0;
}


在一个3×3的网格中，1~8这8个数字和一个“x”恰好不重不漏地分布在这3×3的网格中。

例如：

1 2 3
x 4 6
7 5 8
在游戏过程中，可以把“x”与其上、下、左、右四个方向之一的数字交换（如果存在）。

我们的目的是通过交换，使得网格变为如下排列（称为正确排列）：

1 2 3
4 5 6
7 8 x
例如，示例中图形就可以通过让“x”先后与右、下、右三个方向的数字交换成功得到正确排列。

交换过程如下：

1 2 3   1 2 3   1 2 3   1 2 3
x 4 6   4 x 6   4 5 6   4 5 6
7 5 8   7 5 8   7 x 8   7 8 x
现在，给你一个初始网格，请你求出得到正确排列至少需要进行多少次交换。

输入格式
输入占一行，将3×3的初始网格描绘出来。

例如，如果初始网格如下所示：
1 2 3

x 4 6

7 5 8

则输入为：1 2 3 x 4 6 7 5 8

输出格式
输出占一行，包含一个整数，表示最少交换次数。

如果不存在解决方案，则输出”-1”。

输入样例：
2  3  4  1  5  x  7  6  8 
输出样例
19
