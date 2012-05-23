//根据网络的题解完成
#include <cstdio>
#define MIN(a,b) (a<b?a:b)
long long ans,l;
int n,m;
long long f[2000002];
int main(){
	scanf("%d %d",&n,&m);
	int lim=MIN(n,m);
	l=100000000000000000;
	for (int i=n;i;i--){
		f[i]=(n/i)*(m/i);
		if (f[i]==l) f[i]=f[i+1];
		else{
			l=f[i];
			for (int j=2;j<=(lim/i);++j){
				f[i]-=f[i*j];
			}
		}
		ans+=f[i]*i;
	}
	printf("%lld\n",ans*2-n*m);
	return 0;
}
