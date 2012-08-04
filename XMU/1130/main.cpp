#include <cstdio>
int n,m;
int Set[50002];
int Set_fa(int v){
	if (Set[v]==v) return v;
	Set[v]=Set_fa(Set[v]);
	return Set[v];
}
void Set_union(int x,int y){
	int fx=Set_fa(x),fy=Set_fa(y);
	Set[fx]=Set[fy];
}
#define Set_same(x,y) (Set_fa(x)==Set_fa(y))
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;++i) Set[i]=i;
	int s,t;
	for (;m;m--){
		scanf("%d%d",&s,&t);
		Set_union(s,t);
	}
	scanf("%d",&m);
	char op;
	for (;m;m--){
		scanf("\n%c %d %d",&op,&s,&t);
		if (op=='C') Set_union(s,t);
		if (op=='Q') {
			printf((Set_same(s,t))?"yes\n":"no\n");
		}
	}
	return 0;
}
