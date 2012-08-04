#include <iostream>
using namespace std;
string ge[11]={"","one","two","three","four","five","six","seven","eight","nine","ten"};
string tens[11]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
string shi[11]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
int main(){
	int n;
	cin >>n;
	if (n<=10) {
		cout << ge[n] <<endl;
		return 0;
	}
	if (n<20) {
		cout << tens[n-10] <<endl;
		return 0;
	}
	cout << shi[n/10] <<" "<<ge[n%10] <<endl;
	return 0;
}
