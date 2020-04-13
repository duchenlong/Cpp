//给定一个只包含三种字符的字符串：（?，）?和 *，写一个函数来检验这个字符串是否为有效字符串。有效字符串具有如下规则：

//任何左括号 (?必须有相应的右括号 )。
//任何右括号 )?必须有相应的左括号 (?。
//左括号 ( 必须在对应的右括号之前 )。
//*?可以被视为单个右括号 )?，或单个左括号 (?，或一个空字符串。
//一个空字符串也被视为有效字符串。
//示例 1:

//输入: "()"
//输出: True
//示例 2:

//输入: "(*)"
//输出: True
//示例 3:

//输入: "(*))"
//输出: True


class Solution {
public:
    bool checkValidString(string s) {
        int len = s.size();
        int maxleft = 0;//当前位置最多的合理左括号数量，左括号 + *
        int minleft = 0;//当前位置最少的合理左括号数量，纯左括号

        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(')//左括号，两者都+1
            {
                maxleft++;
                minleft++;
            }
            else if(s[i] == ')')//右括号
            {
                maxleft--;//最大括号-1，
                minleft = minleft ? minleft-1 : 0;//最少为0，就说明没有(了，最小就不用处理
            }
            else
            {
                maxleft++;//* 号当做左括号
                minleft = minleft ? minleft-1 : 0;//*当做右括号，或者不做处理
            }

            if(maxleft < 0)
                return false;
        }

        return minleft == 0;
    }
};
