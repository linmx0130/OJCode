#include <iostream>
#include <string>
using namespace std;
int n,m;
int v[1002];
string s1,s2;
int ans=-1;
#define MAX(a,b) (a>b?a:b)
void work(int pos){
	int t=0;
	for (int i=0;i<s2.size();++i) {
		if (s1[i+pos]!=s2[i]) return;
		t+=v[pos+i];
	}
	ans=MAX(ans,t);
}
int main(){
	cin >>n;
	for (int i=0;i<n;++i) cin >> v[i];
	cin >>s1;
	cin >>m;
	cin >>s2;
	for (int i=0;i<n;++i){
		if (s1[i]==s2[0]) work(i);
	}
	cout <<ans <<endl;
	return 0;
}

