#include <cstdio>
#include <cstring>
char d[10002][16];
char s[16];
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%s",d[i]);
	}
	int m,k;
	scanf("%d",&k);
	for (int i=1;i<=k;++i){
		scanf("%d %s",&m,s);
		int ans=0;
		for (int j=1;j<=m;++j){
			if (strcmp(d[j],s)>=0) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
