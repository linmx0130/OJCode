#include <cstdio>
#define MAXN 10002
int n;
int a[MAXN],f[MAXN],ans;
void search(){
	for (int i=3;i<=n;++i){
		f[i]=a[i-1]-f[i-1]-f[i-2];
		if ((f[i]<0)||(f[i]>1)) return;
	}
	if (f[n]+f[n-1]==a[n]) ans++;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",a+i);
	}
	if (a[1]==2){
		f[1]=1;f[2]=1;search();
	}
	if (a[1]==1){
		f[1]=1;f[2]=0;search();
		f[1]=0;f[2]=1;search();
	}
	if (!a[1]){
		search();
	}
	printf("%d\n",ans);
	return 0;
}
