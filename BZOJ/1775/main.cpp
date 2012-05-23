#include <cstdio>
#include <cstring>
int n,v;
int p,g;
int gp,pv;
int f[100002],s[100002];
#define MAX(a,b) (a>b?a:b)
int main(){
	scanf("%d %d",&n,&v);
	for (int i=1;i<=n;++i){
		scanf("%d %d",&p,&g);
		memset(s,0,sizeof(s));
		for (int j=p;j<=v;++j) s[j]=f[j-p];
		for (int j=1;j<=g;++j){
			scanf("%d %d",&gp,&pv);
			for (int ii=v;ii>=gp+p;--ii){
				s[ii]=MAX(s[ii],s[ii-gp]+pv);
			}
		}
		for (int j=p;j<=v;++j){
			f[j]=MAX(f[j],s[j]);
		}
	}
	printf("%d\n",f[v]);
	return 0;
}
