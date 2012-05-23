#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100002
struct DNode{
	int s,e;
}di[MAXN],d[MAXN];
int n,nn;
bool operator< (struct DNode a,struct DNode b){
	if (a.s<b.s) return 1;
	if (a.s>b.s) return 0;
	return a.e<b.e;
}
int f[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d%d",&di[i].s,&di[i].e);
	std::sort(di+1,di+1+n);
	for (int i=1;i<=n;++i){
		if (di[i].s!=d[nn].s){
			d[++nn]=di[i];
		}
	}
	n=nn;
	int ans=0;
	for (int i=1;i<=n;++i){
		for (int j=i-1;j>=0;--j){
			if (d[i].s>d[j].e){
				f[i]=f[j]+1;
				if (f[i]>ans) ans=f[i];
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
	return 0;
}
