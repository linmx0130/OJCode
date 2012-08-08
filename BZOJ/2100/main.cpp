#include <cstdio>
#include <cstring>
int c,p,pb,pa1,pa2;
#define MAXN 100002
#define MAXC 200002
class eList
{
public:
	int Head[MAXN],Pre[MAXC*2],V[MAXC*2],W[MAXC*2],tot;
	void __AddEdge(int a,int b,int c)
	{
		++tot;
		V[tot]=b;
		W[tot]=c;
		Pre[tot]=Head[a];
		Head[a]=tot;
	}
	void AddEdge(int a,int b,int c)
	{
		__AddEdge(a,b,c);
		__AddEdge(b,a,c);
	}
}g;
int dist[MAXN],dis[MAXN];
inline int min(int a,int b)
{
	return a<b?a:b;
}
struct QType
{
	int a,b;
};
#define L(t) (t<<1)
#define R(t) ((t<<1)+1)
#define FA(t) (t>>1)
class Heap
{
public:
	 QType d[MAXC*4];
	 int tot;
	 void rise(int t)
	 {
		while (t>1)
		{
			if (d[t].a<d[FA(t)].a)
			{
				QType k;
				k=d[t];
				d[t]=d[FA(t)];
				d[FA(t)]=k;
				t=FA(t);
			}else break;
		}
	 }
	 void sink(int t)
	 {
		while (t<=tot)
		{
			int mint=t;
			if (L(t)<=tot) if (d[mint].a>d[L(t)].a) mint=L(t);
			if (R(t)<=tot) if (d[mint].a>d[R(t)].a) mint=R(t);
			if (mint==t) break;
			QType k=d[t];
			d[t]=d[mint];
			d[mint]=k;
			t=mint;
		}
	 }
	 void push(int b,int a)
	 {
		d[++tot].a=a;d[tot].b=b;
		rise(tot);
	 }
	 void pop()
	 {
		d[1]=d[tot--];
		sink(1);
	 }
	 void init()
	 {
		tot=0;
	 }
}q;
//int q[MAXC*30];
bool inqueue[MAXN];
/*
void spfa(int s,int *dist)
{
	int qh=0,qt=1;
	q[1]=s;
	inqueue[s]=1;
	dist[s]=0;
	while (qh<qt)
	{
		++qh;
		int now=q[qh];
		for (int p=g.Head[now];p;p=g.Pre[p])
		{
			if (dist[g.V[p]]>dist[now]+g.W[p])
			{
				dist[g.V[p]]=dist[now]+g.W[p];
				if (!inqueue[g.V[p]])
				{
					inqueue[g.V[p]]=1;
					++qt;
					q[qt]=g.V[p];
				}
			}
		}
		inqueue[now]=0;
	}
}*/
void dijkstra(int s,int *dist)
{
	q.init();
	dist[s]=0;
	q.push(s,0);
	memset(inqueue,0,sizeof(inqueue));
	while (q.tot)
	{
		int now=q.d[1].b;q.pop();
		if (inqueue[now]) continue;
		inqueue[now]=1;
		for (int p=g.Head[now];p;p=g.Pre[p])
		{
			if (dist[g.V[p]]>dist[now]+g.W[p])
			{
				dist[g.V[p]]=dist[now]+g.W[p];
				q.push(g.V[p],dist[g.V[p]]);
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d%d",&c,&p,&pb,&pa1,&pa2);
	for (int i=1;i<=c;++i)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		g.AddEdge(x,y,z);
	}
	memset(dis,60,sizeof(dis));
	memset(dist,60,sizeof(dist));
	dijkstra(pb,dist);
	dijkstra(pa1,dis);
	printf("%d\n",min(dist[pa1]+dis[pa2],dist[pa2]+dis[pa2]));
	return 0;
}
