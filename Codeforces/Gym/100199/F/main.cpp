#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define MAXN 305
#define PI 3.14159265
struct IslandType
{
	double x,y,r;
}Island[MAXN],Ship;
double Sqr(double x){return x*x;}
double Dis(int i,int j)
{
	return sqrt(Sqr(Island[i].x-Island[j].x)+Sqr(Island[i].y-Island[j].y));
}
int N;
struct eList
{
	int Head[MAXN],Pre[MAXN*MAXN],V[MAXN*MAXN],tot;
	int W[MAXN*MAXN];
	void AddEdge(int a,int b,int c)
	{
		++tot;
		V[tot]=b;W[tot]=c;Pre[tot]=Head[a];Head[a]=tot;
	}
}G;
int Tan[MAXN];
int Q[MAXN];
bool inQ[MAXN];
int Dist[MAXN];
int Count[MAXN];
bool SPFA(int S)
{
	memset(Count,0,sizeof(Count));
	int Qh=0,Qt=1;
	Q[1]=S;
	memset(Dist,100,sizeof(Dist));
	Dist[S]=0;
	while (Qh!=Qt)
	{
		++Qh;if (Qh>=MAXN) Qh-=MAXN;
		int now=Q[Qh];
		for (int p=G.Head[now];p;p=G.Pre[p])
		{
			if (Dist[G.V[p]]>Dist[now]+G.W[p])
			{
				Dist[G.V[p]]=Dist[now]+G.W[p];
				if (!inQ[G.V[p]])
				{
					++Qt;if (Qt>=MAXN) Qt-=MAXN;
					Q[Qt]=G.V[p];
					inQ[G.V[p]]=1;
					if (++Count[G.V[p]]>=N)
					{
						return 1;
					}
				}
			}
		}
		inQ[now]=0;
	}
	return 0;
}
int GetTan(double y,double x)
{
	if (x>0 && y>=0) return 1;
	if (x<=0 && y>0) return 2;
	if (x<0 && y<=0) return 3;
	if (x>=0 && y<0) return 4;
}
int main()
{
	freopen("out.in","r",stdin);
	freopen("out.out","w",stdout);
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		scanf("%lf%lf%lf",&Island[i].x,&Island[i].y,&Island[i].r);
	}
	scanf("%lf%lf%lf",&Ship.x,&Ship.y,&Ship.r);
	for (int i=1;i<=N;++i)
	{
		Tan[i]=GetTan(Island[i].y-Ship.y,Island[i].x-Ship.x);
	}
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=N;++j)
		{
			if (i!=j)
			{
				if (Dis(i,j)<Island[i].r+Island[j].r+Ship.r*2)
				{
					int t=Tan[j]-Tan[i];
					if (t==3) t=-1;
					if (t==-3) t=1;
					G.AddEdge(i,j,t);
//					printf("%d %d %lf\n",i,j,t);
				}
			}
		}
	}
	int S=N+1;
	for (int i=1;i<=N;++i) G.AddEdge(S,i,0);
	if (SPFA(S))
	{
		puts("NO");
	}else
	{
		puts("YES");
	}
	return 0;
}
