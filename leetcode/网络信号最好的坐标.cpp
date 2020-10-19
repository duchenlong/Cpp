class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        int maxN = INT_MIN;
        int n = towers.size();
        
        vector<int> ans(2,0);
        for(int i = 0; i < n; i++){
            int tmp = 0;
            for(int j = 0; j < n; j++) {
                int x = towers[i][0] - towers[j][0];
                int y = towers[i][1] - towers[j][1];
                double d = sqrt(x * x + y * y);
                
                if(d > radius) continue;
                tmp += towers[j][2] / (1 + d); 
            }
            
            if(tmp > maxN) {
                ans[0] = towers[i][0];
                ans[1] = towers[i][1];
            } else if(tmp == maxN) {
                if(ans[0] > towers[i][0]) {
                    ans[0] = towers[i][0];
                    ans[1] = towers[i][1];
                } else if(ans[0] == towers[i][0] && ans[1] > towers[i][1]) {
                    ans[0] = towers[i][0];
                    ans[1] = towers[i][1];
                }
            }
            cout << tmp << " ";
            maxN = max(tmp,maxN);
        }
        
        return ans;
            
    }
};
