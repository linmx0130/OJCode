#include <iostream>
#include <cstdio>
using namespace std;
int m,n;
void printb(int b){
	int t=0;
	for(int i=128;i;i>>=1){
		if (b&i){
			cout <<1 ;
			t=1;
		}else {
			if (t) cout <<0;
		}

	}
	cout <<endl;
}
int main(){
	cin >>m >> n;
	for (int i=m;i<256;i+=n){
		if ((i%7==0)) {
			cout << "pass"<<endl;
			continue;
		}
		int t=i,flag=0;
		while (t){
			if ((t & 7)==7) {
				cout <<"pass"<<endl;
				flag=1;
				break;
			}
			t=t>>1;
		}
		if (!flag) printb(i);
	}
	return 0;
}
