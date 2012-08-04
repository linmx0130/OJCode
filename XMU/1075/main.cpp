#include <cstdio>
#define MAXN 100
#define MAXM 10002
int n;
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
	scanf("%d",&n);
	int t=0,w;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=n;++j){
			scanf("%d",&w);
			Data[++t]=j;
			Wei[t]=w;
			Pre[t]=Connect[i];
			Connect[i]=t;
		}
	}
	spfa();
	printf("%d\n",(f[n]==2147483647)?-1:f[n]);
	return 0;
}
