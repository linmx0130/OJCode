#include <iostream>
#include <string>
using namespace std;
string d[102];
int main(){
	int now=0,tot=0;
	d[0]="http://www.acm.org/";
	string command;
	do{
		cin>>command;
		if (command=="QUIT") return 0;
		if (command=="VISIT"){
			++now;
			tot=now;
			cin >>d[now];
			cout <<d[now]<<endl;
		}
		if (command=="BACK"){
			--now;
			if (now<0) {
				cout <<"Ignored" <<endl;
				now++;
			}else {
				cout <<d[now]<<endl;
			}
		}
		if (command=="FORWARD"){
			++now;
			if (now>tot){
				--now;
				cout << "Ignored"<<endl;
			}else cout <<d[now]<<endl;
		}
	}while (1);
}
