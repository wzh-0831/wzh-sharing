#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<string>
using namespace std;
//  a1=20+22*6-45;

string c[] = { "","标识符","常数","=","+" ,"*",";","-" };
struct id {
	string name;
	int v;
}a[100];//标识符表
int b[100];//常数表
int k1, k2; //在标识符表、常数表的位置
struct res {
	int t, v;
};//识别单词 type value
res f(string s, int& k) {//识别一个单词
	res r;
	string s1 = "";
	if (isalpha(s[k]))//字母
	{
		s1 += s[k++];
		while (isalpha(s[k]) || isdigit(s[k]))
			s1 += s[k++];
		k--;
		r.t = 1;
		a[k1].name = s1;//插入标识符表
		r.v = k1++;
	}
	else if (isdigit(s[k]))//数字
	{
		int t = s[k++] - '0';
		while (isdigit(s[k]))
			t = t * 10 + s[k++] - '0';
		k--;
		r.t = 2;
		b[k2] = t;//插入常数表
		r.v = k2++;
	}
	else if (s[k] == '=')
		r.t = 3;
	else if (s[k] == '+')
		r.t = 4;
	else if (s[k] == '*')
		r.t = 5;
	else if (s[k] == ';')
		r.t = 6;
	else if (s[k] == '-')
		r.t =7;
	return r;
}
int main(int argc, char** argv) {
	res r;
	string s;
	s = "a1=20+22*6-45";
	int k = 0;
	while (1) {
		r = f(s, k);
		k++;
		while (r.t == 6)
			break;
		cout << c[r.t] << " ";
		if (r.t == 1)
			cout << a[r.v].name;
		else if (r.t == 2)
			cout << b[r.v];
		cout << endl;
	}
	return 0;
}
