#include <cstdio>
#include <cstring>
bool f[100002],tf[100002];
int n;
int d[102];
int ans;
#define MAX(a,b) (a>b?a:b)
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&d[i]);
	int max=0,tmp;
	tf[0]=1;
	for (int i=1;i<=n;++i){
		memcpy(f,tf,sizeof(tf));
		for (int j=max;j>=0;--j){
			if (tf[j]) {
				if (j-d[i]>=0) f[j-d[i]]=1;
				else f[d[i]-j]=1;
				f[j+d[i]]=1;
			}
		}
		memcpy(tf,f,sizeof(tf));
		max+=d[i];
	}
	for (int i=1;i<=max;++i){
		if (tf[i]) {
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
