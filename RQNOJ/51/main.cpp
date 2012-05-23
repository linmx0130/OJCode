#include <iostream>
#include <string>
using namespace std;
#define ABS(a) ((a)>0?(a):-(a))
int main(){
	string tmp,s;
	while (cin >>tmp) s+=tmp;
	int a=0,b=0;
	for (int i=0;i<s.size();++i){
		if (s[i]=='W') a++;
		if (s[i]=='L') b++;
		if ((((a>=11)||(b>=11))&&(ABS(a-b)>=2))||s[i]=='E'){
			cout <<a<<":"<<b<<endl;
			a=0;b=0;
		}
		if (s[i]=='E') break;
	}
	cout <<endl;
	for (int i=0;i<s.size();++i){
		if (s[i]=='W') a++;
		if (s[i]=='L') b++;
		if ((((a>=21)||(b>=21))&&(ABS(a-b)>=2))||s[i]=='E'){
			cout <<a<<":"<<b<<endl;
			a=0;b=0;
		}
		if (s[i]=='E') break;
	}
	return 0;
}
