//输入一个按升序排序的整数数组（可能包含重复数字），你需要将它们分割成几个子序列，
//其中每个子序列至少包含三个连续整数。返回你是否能做出这样的分割？

//?

//示例 1：
//输入: [1,2,3,3,4,5]
//输出: True
//解释:
//你可以分割出这样两个连续子序列 : 
//1, 2, 3
//3, 4, 5
//?

//示例 2：
//输入: [1,2,3,3,4,4,5,5]
//输出: True
//解释:
//你可以分割出这样两个连续子序列 : 
//1, 2, 3, 4, 5
//3, 4, 5
//?

//示例 3：
//输入: [1,2,3,4,4,5]
//输出: False


#include <iostream>
#include <vector>
using namespace std;

//序列中的所有数据必须可以全被被分成连续子序列 
class Solution {
public:
    bool isPossible(vector<int>& nums){
        unordered_map<int,int> freq,need;
        //统计每个数字出现的次数
        for(int num : nums)
            freq[num]++;
        
        for(int num : nums)
        {
            if(freq[num] == 0)
                continue;
            
            if(need[num] > 0)
            {
                need[num]--;
                need[num+1]++;
            }
            else if(freq[num + 1] > 0 && freq[num + 2] > 0)
            {
                freq[num + 1]--;
                freq[num + 2]--;
                need[num + 3]++;
            }
            else
                return false;
            
            freq[num]--;
        }

        return true;
    }
}; 

//错误的想法，找两个长度为3的连续子序列 
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int size = 0;//连续子序列的数量
        vector<int> arr(nums.size(),0);

        return isFun(arr,nums) && isFun(arr,nums);
    }

    bool isFun(vector<int>& arr,vector<int>& nums)
    {
        int len = 0;
        for(int i = 1; i < nums.size(); i++)
        {
            if(arr[i-1] + arr[i] != 0)
                continue;

            if(nums[i] - nums[i-1] == 1)
            {
                len++;
                if(len == 2)
                {
                    arr[i] = 1;
                    int count = 0;
                    //前面三个数全部置1
                    for(int j = i - 1; j >= 0; j--)
                    {
                        if(nums[j] != nums[j+1])
                        {
                            arr[j] = 1;
                            count++;
                        }
                        if(count == 2)
                            return true;
                    }
                }
            }
            else if(nums[i] - nums[i-1])//结果比1大
                len = 0;    
                
                //排除重复元素
            while(i+1 < nums.size() && nums[i+1] == nums[i])
                    i++;
        }

        return false;
    }
};

int main()
{
	vector<int> nums(6);
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;
	nums[3] = 4;
	nums[4] = 4;
	nums[5] = 5;
	Solution s1;
	cout<<s1.isPossible(nums)<<endl;
	return 0;
} 
