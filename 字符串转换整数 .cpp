//你来实现一个?atoi?函数，使其能将字符串转换成整数。

//首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：

//如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
//假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
//该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
//注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。

//在任何情况下，若函数不能进行有效的转换时，请返回 0 。

//提示：

//本题中的空白字符只包括空格字符 ' ' 。
//假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为?[?231,? 231?? 1]。如果数值超过这个范围，请返回 ?INT_MAX (231?? 1) 或?INT_MIN (?231) 。
//?

//示例?1:

//输入: "42"
//输出: 42
//示例?2:

//输入: "   -42"
//输出: -42
//解释: 第一个非空白字符为 '-', 它是一个负号。
//?    我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
//示例?3:

//输入: "4193 with words"
//输出: 4193
//解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
//示例?4:

//输入: "words and 987"
//输出: 0
//解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
     因此无法执行有效的转换。


//C 
long plusnum(char* str);
long minusnum(char* str)
{
    long num = 0;
    long count = 2147483648;
    char* src = str;
    while(*src>='0'  && *src<='9')
    {
        num = num * 10 + *src - '0';
        if(num > count)
        {
            return count;
        }
        src++;
    }
    num = 0 - num;
    return num;
}
long plusnum(char* str)
{
    long num = 0;
    int count = 2147483647;
    char* src = str;
    if(*src == '+')
    {
        src++;
    }
    while(*src>='0'  && *src<='9')
    {
        num = num * 10 + *src - '0';
        if(num > count)
        {
            return count;
        }
        src++;
    }
    return num;
}

int myAtoi(char * str){
    long num = 0;
    while(*str == ' ')
    {
        *str++;
    }
    if(str[0] == '+' || (str[0] >= '0' && str[0] <= '9'))
    {
        num = plusnum(str);
    }
    else if(str[0] == '-' && (str[1] >= '0' && str[1] <= '9'))
    {
        num = minusnum(str+1);
    }
    return (int)num;
}


//C++ 
class Solution {
public:
    int myAtoi(string str) {
    int num=0;
    istringstream str_1(str);//绑定一行字符串，然后以空格为分隔符把该行分隔开来。
    str_1 >> num;
    if (num > INT_MAX)
        return INT_MAX;
    else if (num < INT_MIN)
        return INT_MIN;
    else
        return num;
    }
};
