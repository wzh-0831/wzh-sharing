#include<iostream>
#include<cstring>
using namespace std;
string s;
int k=-1,state=0;//��ȥʱ��k++������f0��ȡ��һ���ַ�������k=-1 
void f1();
void f2();
void f3();
//�����������򱨴� 
void f0(){
	state=0;
	k++;
	if(s[k]=='a')
		f1();
	else if(s[k]=='b')
		f2();
}
void f1(){
	state=1;
	k++;
	if(s[k]=='a')
		f3();
	else if(s[k]=='b')
		f2();
}
void f2(){
	state=2;
	k++;
	if(s[k]=='a')
		f1();
	else if(s[k]=='b')
		f3();
}
void f3(){
	state=3;
	k++;
	if(s[k]=='a')
		f3();
	else if(s[k]=='b')
		f3();
}

int main(){
	getline(cin,s);
	f0();
	if(state==3)
		cout<<"Permit!"<<endl;
	else 
		cout<<"Not accept, Go off!"<<endl;
	return 0;
}