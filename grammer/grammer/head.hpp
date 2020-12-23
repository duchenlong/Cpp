#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string	str;				// 输入表达式
int		start = 0;			// 待读取表达式位置
int		idx = 0;			// 序号
vector<string> st;			// 符号栈

void E();
void E1();
void F();
void T();
void T1();

void input() {
	cout << "输入表达式 -> ";
	getline(cin, str);
	//str = "i*(i+i)";
	cout << endl;
}

void print() {
	cout << "\t " << idx << "\t ";
	string t("");
	for (auto& e : st) t += e;
	printf("%-10s\t", t.c_str());
	cout << str.substr(start) << "\t\t ";
}


void check() {
	printf("\t 序号\t 符号栈 \t 待分析字符串 \t 表达式 \n");
	
	st.push_back("#");
	st.push_back("E");
	print();
	idx++;
	cout << endl;

	E();

	if (st.back() != "#") cout << "语义不合法" << endl;
	else cout << "语义合法 " << endl;
}

void E() {
	print();					//打印当前步骤信息
	printf("E->TE'\n");			
	st.pop_back();
	st.push_back("E`");
	st.push_back("T");
	idx++;					
	T();
	E1();
}

void E1() {
	if (str[start] == '+') {
		print();
		printf("E'->+TE'\n");			//输出表达式
		st.pop_back();			
		st.push_back("E`");				
		st.push_back("T");		
		idx++;							
		start++;						
		T();
		E1();
	}
	else {
		print();						
		printf("E'->ε\n");				
		st.pop_back();
		idx++;
	}
}

void F() {
	if (str[start] == 'i'){				//若待分析字符匹配‘i’
		print();						
		printf("F->i\n");				
		st.pop_back();
		idx++;							
		start++;						
	}
	else if (str[start] == '('){		//若待分析字符匹配‘(’
		print();						
		printf("F->(E)\n");				
		st.pop_back();
		st.push_back("E");
		idx++;							
		start++;						
		E();
		if (str[start] == ')'){			//若待分析字符匹配‘)’
			start++;					
		}
		else{
			printf("没有')'匹配！\n");
			return;
		}
	}
	else{
		printf("error\n");
		return;
	}
}

void T() {
	print();					//打印当前步骤信息
	printf("T->FT'\n");			//输出表达式
	st.pop_back();
	st.push_back("T`");
	st.push_back("F");
	idx++;						//分析步数+1
	F();
	T1();
}

void T1(){
	if (str[start] == '*'){		//若待分析字符匹配‘*’
		print();						
		printf("T'->*FT'\n");			
		st.pop_back();
		st.push_back("T`");
		st.push_back("F");
		idx++;							
		start++;						
		F();
		T1();
	}
	else{
		print();						
		printf("T'->ε\n");				
		st.pop_back();
		idx++;							
	}
}





