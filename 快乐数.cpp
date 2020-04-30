//编写一个算法来判断一个数 n 是不是快乐数。

//「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为? 1，那么这个数就是快乐数。

//如果 n 是快乐数就返回 True ；不是，则返回 False 。

//?

//示例：

//输入：19
//输出：true
//解释：
//12 + 92 = 82
//82 + 22 = 68
//62 + 82 = 100
//12 + 02 + 02 = 1



class Solution {
public:
    //暴力枚举 + find搜索
    bool isHappy1(int n) {
        vector<int> arr;
        int num = n;
        while(1) {
            int tmp = 0;
            int count = num;
            while(count) {
                tmp += (count % 10) * (count % 10);
                count /= 10;
            }
            if(tmp == 1) return true;

            auto ret = find(arr.begin(),arr.end(),tmp);
            if(ret == arr.end()) arr.push_back(tmp);
            else break;
            num = tmp;
        }
        return false;
    }

    //链表找环
    bool isHappy(int n) {
        int slow = n;
        int fast = sqrtSum(n);
        while(slow != fast) {
            slow = sqrtSum(slow);
            fast = sqrtSum(sqrtSum(fast));
            if(slow == 1) return true;
        }
        return slow == 1; //防止第一个数就是1
    }

    //计算平方和
    int sqrtSum(int num) {
        int count = num;
        int ans = 0;
        while(count) {
            ans +=  (count % 10) * (count % 10);
            count /= 10;
        }
        return ans;
    }
};
