//你有一个日志数组 logs。每条日志都是以空格分隔的字串。

//对于每条日志，其第一个字为字母数字标识符。然后，要么：

//标识符后面的每个字将仅由小写字母组成，或；
//标识符后面的每个字将仅由数字组成。
//我们将这两种日志分别称为字母日志和数字日志。保证每个日志在其标识符后面至少有一个字。

//将日志重新排序，使得所有字母日志都排在数字日志之前。字母日志按内容字母顺序排序，忽略标识符；在内容相同时，按标识符排序。数字日志应该按原来的顺序排列。

//返回日志的最终顺序。

//?

//示例 ：

//输入：["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
//输出：["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]


class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(),logs.end(),vector_cmp);
        return logs;
    }

    static bool vector_cmp(const string& a,const string& b)
    {
        int lena = a.size(),flaga = 1,ia = 0;//1--字母日志  0 --- 数字日志
        int lenb = b.size(),flagb = 1,ib = 0;

        //找到两字符串的内容
        while(a[ia++] != ' ');
        while(b[ib++] != ' ');

        //判断日志格式
        if(a[ia] < 'a')
            flaga--;
        if(b[ib] < 'a')
            flagb--;
        
        //一个是数字日志，一个字母日志的情况
        if(flaga != flagb)
            return flaga;
        
        //两个数字日志，不用交换
        if(flaga + flagb == 0)
            return  false;
        

        //两个字母日志，比较内容
        const string s1 = a.substr(ia,lena);
        const string s2 = b.substr(ib,lenb);
        int ret = s1.compare(s2);
        if(ret != 0)
            return ret<0?true:false;

        return a.compare(b);
    }
};
