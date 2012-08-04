#include <iostream>
#include <string>
using namespace std;
string a,b;
int main(){
	cin >> a >>b;
	string c;
	while (a.size()>b.size()){b="0"+b;}
	while (a.size()<b.size()){a="0"+a;}
	int t;
	for (int i=0;i<a.size();++i){
		t=a[i]-'0'+b[i]-'0';
		if (t>=10) t-=10;
		c+=(char)(t+'0');
	}
	cout << c <<endl;
	return 0;
}
