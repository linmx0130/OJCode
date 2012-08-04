#include <cstdio>
#define MAXN 202
#define MAXM 202
struct node_t{
	int v,w;
	int op;
}Data[MAXM*2];
int Connect[1000],Pre[MAXM*2],Edgetot;
int h[MAXN],num[MAXN];
#define MIN(a,b) (a<b?a:b)
int S,T,n,m;
void AddEdge(int x,int y,int w){
	Edgetot++;
	Data[Edgetot].v=y;
	Data[Edgetot].w=w;
	Data[Edgetot].op=Edgetot+1;
	Pre[Edgetot]=Connect[x];
	Connect[x]=Edgetot;
	Edgetot++;
	Data[Edgetot].v=x;
	Data[Edgetot].w=0;
	Data[Edgetot].op=Edgetot-1;
	Pre[Edgetot]=Connect[y];
	Connect[y]=Edgetot;
}
int aug(int u,int flow){
	if (u==T) return flow;
	int l=flow;
	int tmp=n-1;
	for (int p=Connect[u];p;p=Pre[p]){
		if (h[u]==h[Data[p].v]+1&&Data[p].w){
			int f=aug(Data[p].v,MIN(l,Data[p].w));
			l-=f;
			Data[p].w-=f;
			Data[Data[p].op].w+=f;
			if (l==0||h[S]==n) return flow-l;
		}
		if (Data[p].w>0&&h[Data[p].v]<tmp){
			tmp=h[Data[p].v];
		}
	}
	if (l==flow){
		num[h[u]]--;
		if (num[h[u]]==0) h[S]=n;
		else{
			h[u]=tmp+1;
			num[h[u]]++;
		}
	}
	return flow-l;
}
int sap(){
	int ans=0;
	num[0]=n;
	while(h[S]<n){
		ans+=aug(S,2147483647);
	}
	return ans;
}
int main(){
	scanf("%d %d",&m,&n);
	int x,y,w;
	for (int i=1;i<=m;++i){
		scanf("%d %d %d",&x,&y,&w);
		AddEdge(x,y,w);
	}
	S=1;T=n;
	printf("%d\n",sap());
	return 0;
}
