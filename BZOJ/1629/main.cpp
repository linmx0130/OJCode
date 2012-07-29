#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100002
int n;
long long ans=-1000000000000LL,wtot;
struct Data_t{
	int w,s;
}d[MAXN];
bool cmp(Data_t a,Data_t b){
	return a.s<b.s;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d%d",&d[i].w,&d[i].s);
		d[i].s+=d[i].w;
	}
	std::sort(d+1,d+n+1,cmp);
	for (int i=1;i<=n;++i){
		wtot+=d[i].w;
		if (wtot-d[i].s>ans) ans=wtot-d[i].s;
	}
	printf("%lld\n",ans);
	return 0;
}
