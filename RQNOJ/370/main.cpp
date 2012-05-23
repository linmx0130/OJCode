#include <cstdio>
#include <cstring>
#include <algorithm>
struct eData{
	int f,t,w;
}e[10005];
int n,k;
int Set[105];
bool cmp(eData a,eData b){
	return a.w<b.w;
}
int Set_fa(int a){
	if (Set[a]==a) return a;
	return Set[a]=Set_fa(Set[a]);
}
int main(){
	scanf("%d%d",&n,&k);
	int ans=0;
	for (int i=1;i<=k;++i){
		scanf("%d%d%d",&e[i].f,&e[i].t,&e[i].w);
		ans+=e[i].w;
	}
	for (int i=1;i<=n;++i) Set[i]=i;
	std::sort(e+1,e+k+1,cmp);
	int tot=0,i=0;
	while (tot<n-1){
		++i;
		if (Set_fa(e[i].f)==Set_fa(e[i].t)) continue;
		Set[Set_fa(e[i].f)]=Set_fa(e[i].t);
		ans-=e[i].w;
		tot++;
	}
	printf("%d\n",ans);
	return 0;
}
