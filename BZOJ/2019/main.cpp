#include <cstdio>
int D,P,C,F,S;
int Connect[250],Data[600],Pre[600],V[600],Total;
int f[250],Len[250];
int inqueue[250];
int queue[1000];
int qt,qh;
void AddEdge(int x,int y,int w){
	Data[++Total]=w;
	V[Total]=y;
	Pre[Total]=Connect[x];
	Connect[x]=Total;
}
int main(){
	scanf("%d %d %d %d %d",&D,&P,&C,&F,&S);
	int x,y,w;
	for (int i=1;i<=P;++i){
		scanf("%d %d",&x,&y);
		AddEdge(x,y,-D);
	}
	for (int i=1;i<=F;++i){
		scanf("%d %d %d",&x,&y,&w);
		AddEdge(x,y,w-D);
	}
	qt=1;
	queue[1]=S;
	inqueue[S]=1;
	Len[1]=1;
	while (qt>qh){
		qh++;
		int o=queue[qh];
		inqueue[o]=0;
		for (int now=Connect[o];now;now=Pre[now]){
			if (f[V[now]]>f[o]+Data[now]){
				Len[V[now]]=Len[o]+1;
				if (Len[V[now]]>C) {
					printf("-1\n");
					return 0;
				}
				f[V[now]]=f[o]+Data[now];
				if (!inqueue[V[now]]){
					queue[++qt]=V[now];
					inqueue[V[now]]=1;
				}
			}
		}
	}
	int min=2147483647;
	for (int i=1;i<=C;++i){
		if (min>f[i]) min=f[i];
	}
	printf("%d\n",-min+D);
	return 0;
}
