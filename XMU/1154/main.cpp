#include <iostream>
#include <string>
#include <cstdio>
#include <map>
using namespace std;
map<string,bool> s;
int main(){
	int i=0;
	int ans=0;
	string x;
	do{
		cin >>x;
		if (x=="0") break;
		s[x]=1;
	}while(1);
	int n=i;
	string t;
	do {
		cin >>t;
		if (t=="0")break;
		if (s[t]){
			ans++;
			s[t]=0;
		}
	}while(1);
	cout<<ans<<endl;
	return 0;
}
