#include <cstdio>
#define MAXN 100002
#define MAXM MAXN*4
int n,m;
int Connect[MAXN],Wei[MAXM],V[MAXM],Pre[MAXM],Total;
#define MIN(a,b) (a<b?a:b)
inline void AddEdge(int x,int y,int w){
	Total++;
	Wei[Total]=w;
	V[Total]=y;
	Pre[Total]=Connect[x];
	Connect[x]=Total;
}
int Rode_Pre[MAXN];
int ans,qt,qh;
int queue[MAXM*2];
bool inqueue[MAXN];
int f[MAXN];
void spfa(){
	inqueue[1]=1;
	queue[1]=1;
	qt=1;
	f[1]=2147483647;
	while (qh<qt){
		int o=queue[++qh];
		for (int now=Connect[o];now;now=Pre[now]){
			if (f[V[now]]<MIN(f[o],Wei[now])){
				f[V[now]]=MIN(f[o],Wei[now]);
				Rode_Pre[V[now]]=o;
				if (!inqueue[V[now]]){
					inqueue[V[now]]=1;
					queue[++qt]=V[now];
				}
			}
		}
		inqueue[o]=0;
	}
	ans=f[n];
}
void print(int k){
	if (k==0) return;
	print(Rode_Pre[k]);
	printf("%d ",k);
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;++i){
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		AddEdge(x,y,w);
		AddEdge(y,x,w);
	}
	spfa();
	//printf("%d\n",ans);
	if (f[n]){
	print(n);
	printf("\n");
	}else {
	  printf("-1\n");
	}
	return 0;
}
