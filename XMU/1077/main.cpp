#include <cstdio>
#define MAXN 100002
#define MAXM 200002
int n,m;
int Connect[MAXN],Data[MAXM*2],Pre[MAXM*2],Wei[MAXM*2];
int f[MAXN];
int queue[MAXN*10];
bool inqueue[MAXN];
void spfa(){
	int h=0,t=1;
	queue[1]=1;
	inqueue[1]=1;
	for (int i=2;i<=n;++i) f[i]=2147483647;
	f[1]=0;
	do{
		int o=queue[++h];
		inqueue[o]=0;
		for (int p=Connect[o];p;p=Pre[p]){
			if (f[Data[p]]>f[o]+Wei[p]){
				f[Data[p]]=f[o]+Wei[p];
				if (!inqueue[Data[p]]){
					inqueue[Data[p]]=1;
					queue[++t]=Data[p];
				}
			}
		}
	}while(h<t);
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;++i){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		int t=(i<<1)-1;
		Data[t]=y;
		Wei[t]=w;
		Pre[t]=Connect[x];
		Connect[x]=t;

		Data[++t]=x;
		Wei[t]=w;
		Pre[t]=Connect[y];
		Connect[y]=t;
	}
	spfa();
	printf("%d\n",(f[n]==2147483647)?-1:f[n]);
	return 0;
}
