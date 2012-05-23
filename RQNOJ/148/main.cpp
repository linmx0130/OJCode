#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int GF[256];
int n;
class RDig{
public:
	int a[1002];
	int len;
	RDig(){
		len=1000;
		memset(a,0,sizeof(a));
	}
	RDig Ne(){
		RDig re;
		for (int i=len+1,j=1000;i<=1000;++i,--j){
			re.a[i]=a[j];
		}
		re.len=len;
		return re;
	}
	RDig operator+(RDig b){
		RDig r;
		for (int i=1000;i>len;--i){
			r.a[i]=a[i]+b.a[i];
			if (r.a[i+1]>=n){
				r.a[i]+=1;
				r.a[i+1]-=n;
			}
		}
		r.len=len;
		if (r.a[r.len+1]>=n){
			r.a[r.len+1]-=n;
			r.a[r.len--]=1;
		}
		return r;
	}
	bool Getp(){
		for (int i=len+1,j=1000;i<=j;++i,--j){
			if (a[i]!=a[j]) return false;
		}
		return true;
	}
};
void init(){
	GF['1']=1;
	GF['2']=2;
	GF['3']=3;
	GF['4']=4;
	GF['5']=5;
	GF['6']=6;
	GF['7']=7;
	GF['8']=8;
	GF['9']=9;
	GF['A']=10;
	GF['B']=11;
	GF['C']=12;
	GF['D']=13;
	GF['E']=14;
	GF['F']=15;
}
int main(){
	init();
	cin >>n;
	string s;
	cin >>s;
	RDig d;
	for (int i=s.size()-1;i>=0;--i){
		d.a[d.len--]=GF[s[i]];
	}
	if (d.Getp()) {
		cout <<"0\n";
		return 0;
	}
	for (int i=1;i<=30;++i){
		d=d+d.Ne();
		if (d.Getp()){
			cout <<i <<endl;
			return 0;
		}
	}
	cout <<"Impossible\n";
	return 0;
}
