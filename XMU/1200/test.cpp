#include <iostream>
#include <cmath>
using namespace std;
int gcd(int x,int y){
	int r;
	while(y>0){
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}
int work(int a){
	int ans=0;
	for (int i=1;i<=(int)sqrt(a);++i){
		if (a%i==0){
			if (gcd((a/i),i)==1) {
				ans++;
			}
		}
	}
	cout <<ans*2 <<endl;
	return 0;
}
int main(){
	int n,t;
	cin >> n;
	for (;n;n--){
		cin >> t;
		work(t);
	}
	return 0;
}
