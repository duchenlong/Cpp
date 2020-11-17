class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](const vector<int>& a,const vector<int>& b)->bool{
            if(a[0] != b[0]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int n = people.size();
        vector<vector<int> > ans;
        for(int i = 0; i < n; i++) {
            ans.insert(ans.begin() + people[i][1],people[i]);
        }

        return ans;
    }
};

假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

注意：
总人数少于1100人。

示例

输入:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

输出:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
