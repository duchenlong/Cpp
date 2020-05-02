//给定一个数组 nums，有一个大小为?k?的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k?个数字。滑动窗口每次只向右移动一位。

//返回滑动窗口中的最大值。

//?

//进阶：

//你能在线性时间复杂度内解决此题吗？

//?

//示例:

//输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
//输出: [3,3,5,5,6,7] 
//解释: 

//  滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7



class Solution {
public:
    滑动窗口
    class priorityQueue {
        public:
            void push(int num) {
                //当入一个元素的时候，前面比他小的元素就没必要存在了
                //尾插法
                while(!data.empty() && data.back() < num)
                    data.pop_back();
                data.push_back(num);
            }
            //最大值即为最大元素
            int max() {
                return data.front();
            }

            void pop(int num) {
                //真正可以pop是建立在num是当前队列最大的元素
                //因为比他小的元素在插入的时候就删除了
                if(!data.empty() && data.front() == num)
                    data.pop_front();//头删
            } 
        private:
            deque<int> data;
    };

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priorityQueue window;
        vector<int> ans;
        //先把前k-1个元素插入队列
        for(int i = 0; i < k - 1; i++)
            window.push(nums[i]);
        //开始操作窗口
        for(int i = k-1; i < nums.size(); i++) {
            window.push(nums[i]);
            ans.push_back(window.max());
            window.pop(nums[i-k+1]);//窗口逻辑上第一个元素出队
        }
        return ans;
    }
};
