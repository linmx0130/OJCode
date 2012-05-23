#include <cstdio>
#define MAXN 10002
int n;
int d[MAXN];
unsigned long long ans;
inline int abs(int a){
	return a>0?a:-a;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&d[i]);
		for (int j=1;j<i;++j){
			ans+=abs(d[j]-d[i]);
		}
	}
	printf("%llu\n",ans*2);
	return 0;
}
