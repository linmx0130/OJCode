#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 102
int mark[MAXN];
class eList{
public:
	int tot,Head[MAXN],Pre[MAXN*MAXN],V[MAXN*MAXN];
	void AddEdge(int a,int b){
		++tot;
		V[tot]=b;
		Pre[tot]=Head[a];
		Head[a]=tot;
	}
}g;
int n;
int one;
void work(int now){
	int p;
	for (p=g.Head[now];p;p=g.Pre[p]){
		if (mark[g.V[p]]){
			if (mark[g.V[p]]&1) {
				mark[now]=2;
			}
			else {
				mark[now]=1;
				++one;
			}
			return;
		}
	}
	for (p=g.Head[now];p;p=g.Pre[p]){
		if (!mark[g.V[p]]){
			mark[now]=1;
			mark[g.V[p]]=2;
			++one;
			return;
		}
	}
	puts("0");
	exit(0);
}
int main(){
	scanf("%d",&n);
	int i;
	for (i=1;i<=n;++i){
		int tmp;
		scanf("%d",&tmp);
		while (tmp){
			g.AddEdge(i,tmp);
			scanf("%d",&tmp);
		}
	}
	for (i=1;i<=n;++i){
		if (!mark[i]) work(i);
	}
	printf("%d\n",one);
	for (i=1;i<=n;++i){
		if (mark[i]==1) printf("%d ",i);
	}
	puts("");
	return 0;
}
