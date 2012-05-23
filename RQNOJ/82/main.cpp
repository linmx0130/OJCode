#include <cstdio>
#include <cstring>
#define MAXN 10005
int n;
int a[MAXN];
int f[MAXN][2];
inline int min(int a,int b){
	return a<b?a:b;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	memset(f,60,sizeof(f));
	f[0][0]=0;
	for (int i=1;i<=n+2;++i){
		f[i][0]=min(min(f[i-1][1],f[i-1][0])+a[i],f[i][0]);
		f[i][1]=min(min(f[i-2][0],f[i-1][0]),f[i][1]);
	}
	//output
	int ans=21474836;
	for (int i=0;i<=2;++i){
		ans=min(ans,min(f[n+i][0],f[n+i][1]));
	}
	printf("%d\n",ans);
	return 0;
}
