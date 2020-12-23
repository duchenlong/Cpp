#define _CRT_SECURE_NO_WARNINGS 1


#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

const string  fileName	=	"text.cpp";
vector<string> keyBuf	= { "int", "if", "else", "while", "do", "return","for" ,"include"};
vector<string> operBuf	= {"#" ,"<", ">", "!=", ">=", "<=", "==", ",", ";", "(", ")", "{", "}", "+", "-", "*", "/", "=" ,"++"};
vector<string> numBuf	= { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

int		idx;							// 词法标号
string	buf;							// 源程序
int							operand;	// 操作数
int							tag;		// 标识符
unordered_map<string, int>	keyWord;	// 关键字
unordered_map<string, int>	oper;		// 操作符

void init();			// 初始化
void analyse();			// 词法解析
bool isSpace(char ch);	// 是否为空格，tab，回车
void show(string first, int index);	// 展示

int main() {
	ifstream fp(fileName);
	string rbuf;

	init();
	while (getline(fp, rbuf)) {
		buf += rbuf + "\n";
	}
	cout << "词法分析器解析源文件: \n\n";
	cout << "==================================================" << endl;
	cout << buf << endl;

	analyse();		// 解析

	fp.close();
	return 0;
}

// 初始化
void init() {
	for (auto& e : keyBuf) keyWord[e] = ++idx;
	for (auto& e : operBuf)	oper[e] = ++idx;
	operand = ++idx;
	tag = ++idx;
}

void show(string first, int index) {
	printf("[ %s -> ( %d , %s )] \n", first.c_str(), index, first.c_str());
}

// 是否为空格，tab，回车
bool isSpace(char ch) {
	return ch == ' ' || ch == '\n' || ch == '\t';
}

// 是否为操作符
bool isOper(char ch) {
	string s(1,ch);
	//if (oper.find(s) != oper.end()) cout << "no find " << s << endl;
	return oper.find(s) != oper.end();
}

// 是否是数字
bool isNum(string& str) {
	for (auto& ch : str) if (ch < '0' || ch > '9') return false;
	return true;
}

// 标识符,数字 解析
void check(string& str) {
	if (str == "") return;

	// 是否为数字
	bool ret = isNum(str);
	if (ret) {
		// number
		show(str, operand);
	}else {
		if (keyWord.find(str) == keyWord.end()) {
			// 标识符
			show(str, tag);
			return;
		}
		show(str, keyWord[str]);
	}
}

// 操作符解析
void checkOper(int& index) {
	int p = index;
	string t;
	for (; p < buf.size(); p++) {
		if (oper.find(t + buf[p]) == oper.end()) break;
		t += buf[p];
	}
	show(t, oper[t]);
	index = p - 1;
}

// 词法解析
void analyse() {
	string str;
	int n = buf.size();

	for (int i = 0; i < n; i++) {
		if (isSpace(buf[i])) {
			check(str);
			str = "";
		}else if (isOper(buf[i])) {
			check(str);
			checkOper(i);
			str = "";
		}else {
			str += buf[i];
		}

		//cout << str << endl;
	}
}