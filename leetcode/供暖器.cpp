class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());

        int n = heaters.size();
        int ans = -1;
        for(auto& idx : houses) {
            int pos = BinaryFind(heaters,0,n-1,idx);
            
            int ri = (pos == n) ? INT_MAX : heaters[pos] - idx;
            int le = (pos == 0) ? INT_MAX : idx - heaters[pos-1];
            ans = max(ans,min(ri,le));
        }

        return ans;
    }

    // 第一次出现的位置
    int BinaryFind(vector<int>& arr,int le,int ri,int num) {
        while(le <= ri) {
            int mid = (le + ri) / 2;

            if(arr[mid] == num) return mid;
            else if(arr[mid] > num) ri = mid - 1;
            else if(arr[mid] < num) le = mid + 1;
        }

        return le;
    }   
};

冬季已经来临。?你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。

现在，给出位于一条水平线上的房屋和供暖器的位置，找到可以覆盖所有房屋的最小加热半径。

所以，你的输入将会是房屋和供暖器的位置。你将输出供暖器的最小加热半径。

说明:

给出的房屋和供暖器的数目是非负数且不会超过 25000。
给出的房屋和供暖器的位置均是非负数且不会超过10^9。
只要房屋位于供暖器的半径内(包括在边缘上)，它就可以得到供暖。
所有供暖器都遵循你的半径标准，加热的半径也一样。
示例 1:

输入: [1,2,3],[2]
输出: 1
解释: 仅在位置2上有一个供暖器。如果我们将加热半径设为1，那么所有房屋就都能得到供暖。
示例 2:

输入: [1,2,3,4],[1,4]
输出: 1
解释: 在位置1, 4上有两个供暖器。我们需要将加热半径设为1，这样所有房屋就都能得到供暖。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/heaters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
