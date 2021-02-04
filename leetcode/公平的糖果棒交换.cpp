const int N = 1e5 + 10;
int fb[N];

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        memset(fb,0x00,sizeof fb);
        int sum = 0;
        for(auto& e : A)
            sum += e;
        for(auto& e : B) {
            sum -= e;
            fb[e] ++;
        }
        // sumA - n + m == sumB - m + n
        // sumA - sumB = 2 * n - 2 * m
        // 2 * n = sumA - sumB - 2 * m
        for(auto& e : A) {
            int t = (2 * e - sum) / 2;
            if(t > 0  && t < N && fb[t]) return {e,t};
        }
        return {-1,-1};
    }   
};

爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 根糖果棒的大小，B[j] 是鲍勃拥有的第 j 根糖果棒的大小。

因为他们是朋友，所以他们想交换一根糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）

返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1]?是 Bob 必须交换的糖果棒的大小。

如果有多个答案，你可以返回其中任何一个。保证答案存在。

?

示例 1：

输入：A = [1,1], B = [2,2]
输出：[1,2]
示例 2：

输入：A = [1,2], B = [2,3]
输出：[1,2]
示例 3：

输入：A = [2], B = [1,3]
输出：[2,3]
示例 4：

输入：A = [1,2,5], B = [2,4]
输出：[5,4]
?

提示：

1 <= A.length <= 10000
1 <= B.length <= 10000
1 <= A[i] <= 100000
1 <= B[i] <= 100000
保证爱丽丝与鲍勃的糖果总量不同。
答案肯定存在。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/fair-candy-swap
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
