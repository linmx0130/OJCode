#include <string>
#include <iostream>
using namespace std;
int n,a;
string str(int d){
	string ret;
	while (d){
		ret=(char)((d%10)+'0')+ret;
		d/=10;
	}
	return ret;
}
void print(int data,int len){
	string s;
	s=str(data);
	int l=s.size();
	string ans;
	for (int i=0;i<len;++i){
		ans+=s[i%l];
	}
	cout <<ans <<endl;
}
int main(){
	cin >>a >> n;
	for (int i=1;i<=n;++i,++a){
		print(a,i);
	}
	return 0;
}
