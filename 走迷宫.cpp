// write your code here cpp
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

int main()
{
    int dir[4][2] = {1,0,-1,0,0,1,0,-1};
    vector<string> board(10,"");
    while(cin>>board[0])
    {
        for(int i = 1; i < 10; i++)
            cin>>board[i];
        
        queue<pair<int,int> > que;
        que.push({0,1});
        vector<vector<bool> > vis(10,vector<bool> (10,false));
        int ans = 0;
        vis[0][1] = true;
        
        while(!que.empty())
        {
            ans++;
            int size = que.size();
            int flag = false;
            for(int i = 0; i < size; i++)
            {
                auto f = que.front();
                que.pop();
            
                vis[f.first][f.second] = false;
            
                
                for(int i = 0; i < 4; i++)
                {
                    int x = dir[i][0] + f.first;
                    int y = dir[i][1] + f.second;
                
                    if(x < 0 || x >= 10 || y < 0 || y >= 10 || vis[x][y] == true || board[x][y]=='#')
                        continue;
                
                    if(x == 9 && y == 8)
                    {
                        flag = true;
                        break;
                    }
                    vis[x][y] = true;
                    que.push({x,y});
                }
            
                if(flag == true) break;
            }
            if(flag == true) break;
        }
        
        cout<<ans<<endl;
    }
    return 0;
}
