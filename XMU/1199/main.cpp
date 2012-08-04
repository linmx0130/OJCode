#include <string>
#include <iostream>
using namespace std;
string t,s;
inline bool cmp(int pos){
	for (int i=1;i<s.size();++i){
		if (t[i+pos]!=s[i]) return 0;
	}
	return 1;
}
int main(){
	int n;
	cin >>n;
	int ans;
	for (;n;n--){
		cin >>t;
		cin >>s;
		ans=0;
		for (int i=0;i<t.size()-s.size()+1;++i){
			if ((t[i]==s[0])&&(t[i+s.size()-1]==s[s.size()-1])){
				if (cmp(i)) {i+=s.size()-1;ans++;}
			}
		}
		cout << ans <<endl;
	}
	return 0;
}
