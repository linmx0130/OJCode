#include <cstdio>
#include <cstring>
#define MAXN 1002
int f[MAXN][2];
int n;
int Connect[MAXN],V[MAXN*2],Pre[MAXN*2];
int tot=0;
bool Done[MAXN];
#define MIN(a,b) (a<b?a:b)
void init(){
	scanf("%d",&n);
	int a,b;
	for (int i=1;i<n;++i){
		scanf("%d %d",&a,&b);
		a++;b++;
		V[++tot]=b;
		Pre[tot]=Connect[a];
		Connect[a]=tot;
		V[++tot]=a;
		Pre[tot]=Connect[b];
		Connect[b]=tot;
	}
}
void search(int now){
	int tmp1=0,tmp2=0;
	Done[now]=1;
	for (int o=Connect[now];o;o=Pre[o]){
		if(!Done[V[o]]){
			search(V[o]);
			tmp1+=f[V[o]][1];
			tmp2+=MIN(f[V[o]][1],f[V[o]][0]);
		}
	}
	f[now][0]=tmp1;
	f[now][1]=tmp2+1;
}
int main(){
	init();
	search(1);
	printf("%d\n",MIN(f[1][0],f[1][1]));
	return 0;
}
