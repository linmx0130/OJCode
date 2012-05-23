#include <string>
#include <iostream>
using namespace std;
string h[10000];
int t,mm;
int main(){
	h[1]="http://www.acm.org/";
	t=1;
	mm=1;
	string s;
	while (cin >>s){
		if (s=="VISIT"){
			cin>>s;
			cout << s <<endl;
			h[++t]=s;
			mm=t;
			continue;
		}
		if (s=="BACK"){
			if (t==1) cout <<"Ignored\n";
			else cout << h[--t] <<endl;
			continue;
		}
		if (s=="FORWARD"){
			if (t==mm) cout <<"Ignored\n";
			else cout <<h[++t] <<endl;
			continue;
		}
		if (s=="QUIT") return 0;
	}

}
