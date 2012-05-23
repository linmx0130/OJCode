#include <cstdio>
#define MOD 10007
int a,b,k,n,m;
long long f[1002][2004];
long long pow(int a,int b){
	if (b==1) return a%MOD;
	if (b==2) return (a*a)%MOD;
	int k=pow(a,b>>1);
	if (b&1)
	{
		return (k*k*a)%MOD;
	}else return (k*k)%MOD;
}
int main(){
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
	f[0][0]=1;
	for (int i=1;i<=k;++i){
		f[i][0]=1;
		for (int j=1;j<i*2;++j){
			f[i][j]=f[i-1][j]+f[i-1][j-1];
			if (f[i][j]>=MOD) f[i][j]-=MOD;
		}
	}
	long long ans=(pow(a,n)*pow(b,m)%MOD)*f[k][n]%MOD;
	printf("%lld\n",ans);
	return 0;
}
