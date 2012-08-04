#include <map>
#include <string>
#include <iostream>
using namespace std;
map <string,bool> F;

int main(){
	string d;
	int ans=0,n;
	cin >>n;
	for (int i=1;i<=n;++i){
		cin >>d;
		if (!F[d]){
			ans++;
			F[d]=1;
		}
	}
	cout <<ans <<endl;
	return 0;
}
