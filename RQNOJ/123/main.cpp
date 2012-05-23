#include <cstdio>
#include <cstring>
#define MAXN 202
#define MAXV 5002
#define MAXK 60 
int n,k,v;
inline int _(int d){
	d%=MAXK;
	if (d<0) d+=MAXK;
}
class IncQueue{
public:
	int d[MAXK],qt;
	IncQueue(){
		memset(d,200,sizeof(d));
	}
	void push(int a){
		int want=a;
		if (a<d[k]) return ;
		for (int i=1;i<=k;++i){
			 if (a>d[i]){
			 	int t=d[i];
				d[i]=a;
				a=t;
			 }
		}
	}
}f[MAXV];
int V[MAXN],W[MAXN];
int main(){
	scanf("%d%d%d",&k,&v,&n);
	for (int i=1;i<=n;++i){
		scanf("%d%d",&V[i],&W[i]);
	}
	f[0].push(0);
	for (int i=1;i<=n;++i){
		for (int j=v;j>=V[i];--j){
			for (int K=1;K<=k;++K){
				if (f[j-V[i]].d[K]<0) break;
				f[j].push(f[j-V[i]].d[K]+W[i]);
			}
		}
	}
	int ans=0;
	for (int i=1;i<=k;++i){
		ans+=f[v].d[i];
	}
	printf("%d\n",ans);
	return 0;
}
