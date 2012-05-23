#include <cstdio>
#include <cstring>
#include <cstdlib>
int n;
long long pow(long long a,int p){
	if (p==1) return a%1000;
	if (p==2) return a*a%1000;
	long long k=pow(a,p>>1)%1000;
	if (p&1){
		return k*k*a%1000;
	}
	return k*k%1000;
}
int main(){
	scanf("%d",&n);
	long long a=1,b=pow(2,n),c=pow(3,n),d=pow(4,n);
	long long t=a+b+c+d;
	int ans=0;
	while (!(t%10)){
		ans++;t/=10;
	}
	printf("%d\n",ans);
}
