你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。

示例：

输入：
[
  [0,2,1,0],
  [0,1,0,1],
  [1,1,0,1],
  [0,1,0,1]
]
输出： [1,2,4]
提示：

0 < len(land) <= 1000
0 < len(land[i]) <= 1000


class Solution {
public:
    struct node
    {
        int x,y;
        node(int _x,int _y)
        {
            x = _x;
            y = _y;
        }
    };

    int row = 0,col= 0;
    vector<int> pondSizes(vector<vector<int>>& land) {
        row = land.size();
        col = land[0].size();

        vector<vector<bool> > visit(row,vector<bool> (col,false));
        multiset<int> tans;

        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
            {
                if(visit[i][j] == true || land[i][j] != 0)
                    continue;
                tans.insert(BFS(land,visit,i,j));
            }
        vector<int> ans;

        for(auto& num : tans)
            ans.push_back(num);
        return ans;
    }

    int BFS(vector<vector<int> >& land,vector<vector<bool> >& visit,int x,int y)
    {
        visit[x][y] = true;
        static int dir[8][2] = {1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
        queue<node> que;
        que.push({x,y});
        int ret = 1;
        while(!que.empty())
        {
            int size = que.size();

            for(int i = 0; i < size; i++)
            {
                node n = que.front();
                que.pop();

                for(int j = 0; j < 8; j++)
                {
                    int tx = n.x + dir[j][0];
                    int ty = n.y + dir[j][1];
    
                    if((tx < 0) || (tx >= row) || (ty < 0) || (ty >= col) || (visit[tx][ty] == true) || (land[tx][ty] != 0))
                        continue;
                     
                    ret++;
                    que.push({tx,ty});
                    visit[tx][ty] = true;
                }
            }
        }

        return ret;
    }
};
