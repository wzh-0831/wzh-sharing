#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	string s;
	int k=0,state=0;
	getline(cin,s);
	int len = s.length();
	while(k<len)
	{
		switch(state)
		{
			case 0:
				if(s[k]=='a')
				state=1;
				else if(s[k]=='b')
				state=2;
				break;
			case 1:
				if(s[k]=='a')
				state=3;
				else if(s[k]=='b')
				state=2;
				break;
			case 2:
				if(s[k]=='b')
				state=3;
				else if(s[k]=='a')
				state=1;
				break;
			case 3:
				if(s[k]=='b')
				state=3;
				else if(s[k]=='a')
				state=3;
				break;
		}
		k++;
	}
	if(state==3)
		cout<<"Permit!"<<endl;
	else 
		cout<<"Not accept, Go off!"<<endl;
	return 0;
}