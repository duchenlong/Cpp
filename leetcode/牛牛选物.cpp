链接：https://ac.nowcoder.com/acm/contest/9886/B
来源：牛客网

牛牛有现在有n个物品，每个物品有一个体积v[i]和重量g[i],他想选择其中总体积恰好为V的若干个物品，想使这若干个物品的总重量最大，他想知道最大总重量为多少。（如果不存在合法方案，返回-1）

示例1
输入
复制
[1,2,3],[2,3,4],3
返回值
复制
5
说明
可以选择前两个物品，总体积为1+2=3恰好等于V，总重量为2+3=5，为符合题意选法中的最大重量
示例2
输入
复制
[1,3],[100,300],2
返回值
复制
-1
说明
只有一个体积为1的和一个体积为3的物品，无法选出总体积为2的若干物品，所以返回-1
备注:
对于100\%的数据，1\leq n\leq 20,1\leq v[i]\leq 1e8,1\leq g[i]\leq 1e8,1\leq V\leq 1e9对于100%的数据，1≤n≤20,1≤v[i]≤1e8,1≤g[i]≤1e8,1≤V≤1e9
给定三个参数，第一个参数为数组v，第二个参数为数组g，第三个参数为体积V，求最大总重量为多少。
(所给字符串与返回字符串都不带引号)

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回总体积为V若干物品的最大总重量，如果g存在选择若干物品总体积为V的情况，返回-1
     * @param v int整型vector 
     * @param g int整型vector 
     * @param V int整型 
     * @return int整型
     */
    int ans = -1;
    int n;
    int Maximumweight(vector<int>& v, vector<int>& g, int V) {
        // write code here
        n = v.size();
        dfs(v,g,0,V,0);
        
        return ans;
    }
    
    void dfs(vector<int>& v, vector<int>& g,int idx, int V, int kg) {
        
        if(V == 0) {
            ans = max(ans,kg);
            return ;
        }
        if(V < 0 || idx == n) return ;
        
        for(int i = idx; i < n; i++) {
            dfs(v,g,i+1,V - v[i],kg + g[i]);
        }
    }
};
