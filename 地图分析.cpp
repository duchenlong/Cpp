//你现在手里有一份大小为?N x N 的『地图』（网格）?grid，
//上面的每个『区域』（单元格）都用?0?和?1?标记好了。其中?0?代表海洋，1?代表陆地，
//你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。

//我们这里说的距离是『曼哈顿距离』（?Manhattan Distance）：(x0, y0) 和?(x1, y1)?
//这两个区域之间的距离是?|x0 - x1| + |y0 - y1|?。

//如果我们的地图上只有陆地或者海洋，请返回?-1。

//?

//示例 1：



//输入：[[1,0,1],[0,0,0],[1,0,1]]
//输出：2
//解释： 
//海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。
//示例 2：



//输入：[[1,0,0],[0,0,0],[0,0,0]]
//输出：4
//解释： 
//海洋区域 (2, 2) 和所有陆地区域之间的距离都达到最大，最大距离为 4。
//?

//提示：

//1 <= grid.length == grid[0].length?<= 100
//grid[i][j]?不是?0?就是?1



typedef struct node
{
    int x;//横坐标
    int y;//纵坐标
    int path;//距离该点最远的陆地距离
}node;

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};//上下左右四个方向
        queue<node> q;//储存陆地的位置
        int row = grid.size();
        int col = grid[0].size();

        //初次遍历，储存所有陆地位置
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(grid[i][j])//如果是陆地，就加入结构体中，然后入队
                    q.push(CreatNode(i,j,0));
        int maxPath = -1;

        while(!q.empty())
        {
            node head = q.front();//取出队列头元素
            int x = head.x;
            int y = head.y;
            int path = head.path;
            q.pop();

            for(int i = 0; i < 4; i++)//访问四个方向
            {
                int tx = x + dir[i][0];
                int ty = y + dir[i][1];
                int tpath = path + 1;

                //判断是否越界，或者是否是陆地
                if(tx < 0 || tx >= row || ty < 0 || ty >= col || grid[tx][ty])
                    continue;
                grid[tx][ty] = 1;//当前海洋制成陆地
                q.push(CreatNode(tx,ty,tpath));//陆地入队
                //更新是否有最远的距离
                if(maxPath < tpath)
                    maxPath = tpath;
            }
        }
        return maxPath;
    }

    //返回位置结构体
    node CreatNode(int x,int y,int path)
    {
        node pos;
        pos.x = x;
        pos.y = y;
        pos.path = path;
        return pos;
    }
};
