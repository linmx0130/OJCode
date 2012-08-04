#include <iostream>
using namespace std;
const int m[]={500,100,50,10,5,1};
int n,ans,d;
int a;
int main(){
  a=1000;
	cin >> n;
	a-=25*n;
	if (a<0) {
	  cout << -1 <<endl;
		return 0;
	}
	for (int i=0;i<6;++i){
		cin >> d;
		while ((d)&&(a>=m[i])) {
			d--;
			a-=m[i];
			ans++;
		}
	}
	if (!a)cout << ans;
	else cout << -1;
	cout <<endl;
	return 0;
}
