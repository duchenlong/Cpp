//在给定的N个整数A1，A2……AN中选出两个进行xor（异或）运算，得到的结果最大是多少？

//输入格式
//第一行输入一个整数N。

//第二行输入N个整数A1～AN。

//输出格式
//输出一个整数表示答案。

//数据范围
//1≤N≤105,
//0≤Ai<231
//输入样例：
//3
//1 2 3
//输出样例：
//3


#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;
const int M = N * 31;

int num[N];
int son[M][2];
int id;

//插入数据到字典树中，一个根的左节点是1，右节点是0
void insert(int num)
{
    int p = 0;
    // for(int i = 30; i >= 0; i--)
    for(int i = 30; ~i; i--)
    {
        //获取第i位的数字 0 或者 1
        // int& s = son[p][num>>i & 1];
        // if(!s) s = ++id; //创建一个新结点
        // p = s;
        int tmp = num>>i&1;
        if(!son[p][tmp]) son[p][tmp] = ++id;
        p = son[p][tmp];
    }
}

//找到与这个数异或后最大的结果
int Find(int num)
{
    int ret = 0;
    int p = 0;
    for(int i = 30; ~i; i--)
    {
        int s = num>>i & 1;
        //异或的话，同则为0，异则为1
        if(son[p][!s])//如果存在该位置不同的数，则走这个分支
        {
            ret += 1 << i;
            p = son[p][!s];
        }
        else
            p = son[p][s];
    }
    
    return ret;
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>num[i];
        insert(num[i]);//插入该数据到字典树种
    }
    
    int ans = 0;
    //找异或的最大值
    for(int i = 0; i < n; i++)
        ans = max(ans,Find(num[i]));
    
    cout<<ans<<endl;
    return 0;
}

// //暴力法
// int main()
// {
//     int n;
//     cin>>n;
//     for(int i = 0; i < n; i++)
//         cin>>num[i];
//     int ans = 0;
//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < n; j++)
//             ans = max(ans,num[i]^num[j]);
//     cout<<ans<<endl;
//     return 0;
// }
