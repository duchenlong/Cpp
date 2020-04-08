//地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
//一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
//也不能进入行坐标和列坐标的数位之和大于k的格子。
//例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
//但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

//?

//示例 1：

//输入：m = 2, n = 3, k = 1
//输出：3
//示例 1：

//输入：m = 3, n = 1, k = 0
//输出：1



class Solution {
public:
    typedef struct node
    {
        int row;
        int col;
    };

    int movingCount(int m, int n, int k) {
        int ans = 0;
        vector<vector<int> > visit(m,vector<int> (n,0));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            {
                if(GetNum(i,j) > k)
                    visit[i][j] = 1;//表示这个格子不可以走到
            }
        
        ans = bfs(visit,0,0,m,n);
        return ans;
    }

    int bfs(vector<vector<int> >& visit,int x,int y,int m,int n)
    {
        int dir[4][2] = {1,0,-1,0,0,1,0,-1};//四个方向

        queue<node> que;
        que.push(GetNode(x,y));//头结点入队
        visit[x][y] = 1;
        int ans = 1; //起始位置一定可以到达

        while(!que.empty())
        {
            int size = que.size();//获取队列中元素个数
            for(int i = 0; i < size; i++)
            {
                node point = que.front();//获取队头元素
                que.pop();//队头元素出栈
                int row = point.row;
                int col = point.col;

                //获取该节点下一步可以到达的位置
                for(int j = 0; j < 4; j++)
                {
                    int tx = dir[j][0] + row;
                    int ty = dir[j][1] + col;

                    //判断越界
                    if(tx < 0 || tx >= m || ty < 0 || ty >= n)
                        continue;
                    
                    //是否可以到达
                    if(visit[tx][ty])
                        continue;
                    
                    //此时这个格子可以达到
                    que.push(GetNode(tx,ty));//入队
                    ans++;
                    visit[tx][ty] = 1;
                }
            }
        }

        return ans;
    }

    //打包点的坐标为结构体
    node GetNode(int row,int col)
    {
        node point;
        point.row = row;
        point.col = col;
        return point;
    }

    //获取该位置坐标的位数和
    int GetNum(int row,int col)
    {
        int num = 0;
        while(row || col)
        {
            num += row % 10 + col % 10;
            row /= 10;
            col /= 10;
        }

        return num;
    }
};
