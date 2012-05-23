#include <cstdio>
#define MAXN 50002
#define S(a) (a+MAXN)
int Set[MAXN*2];

int Set_fa(int v){
	if (Set[v]==v) return v;
	Set[v]=Set_fa(Set[v]);
	return Set[v];
}
inline void Set_union(int a,int b){
	int fa=Set_fa(a);
	int fb=Set_fa(b);
	Set[fa]=fb;
}
#define Set_same(a,b) (Set_fa(a)==Set_fa(b))
int n;
int main(){
	int k;
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;++i){
		Set[S(i)]=S(i);
		Set[S(-i)]=S(-i);
	}
	int o,x,y;
	int ans=0;
	for (;k;k--){
		scanf("%d %d %d",&o,&x,&y);
		if ((x>n)||(y>n)) {ans++;continue;}
		if (o==1){
			if (Set_same(S(x),S(-y))) {
				ans++;continue;
			}
			Set_union(S(x),S(y));
			Set_union(S(-x),S(-y));
		}
		if (o==2){
			if (Set_same(S(x),S(y))){
				ans++;continue;
			}
			Set_union(S(x),S(-y));
			Set_union(S(-x),S(y));
		}
	}
	printf("%d\n",ans);
	return 0;
}
