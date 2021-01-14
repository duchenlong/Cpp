class Solution {
public:
    int findString(vector<string>& words, string s) {
        int le = 0, ri = words.size() - 1;
        while(le < ri) {
            int mid = (le + ri) / 2;
            while(mid > le && words[mid] == "") mid--;
            if(words[mid] == s) return mid;
            else if(words[mid] < s) le = mid + 1;
            else ri = mid;
        }

        return words[le] == s ? le : -1;
    }
};


稀疏数组搜索。有个排好序的字符串数组，其中散布着一些空字符串，编写一种方法，找出给定字符串的位置。

示例1:

 输入: words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ta"
 输出：-1
 说明: 不存在返回-1。
示例2:

 输入：words = ["at", "", "", "", "ball", "", "", "car", "", "","dad", "", ""], s = "ball"
 输出：4
提示:

words的长度在[1, 1000000]之间

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sparse-array-search-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
