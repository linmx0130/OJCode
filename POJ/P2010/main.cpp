#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using std::sort;
#define MAXN 100002
#define L(t) (t<<1)
#define R(t) ((t<<1)|1)
#define FA(t) (t>>1)
int N,C,F;
struct CowType
{
	int s,f;
}d[MAXN];
bool cmp(const CowType &a, const CowType &b)
{
	return a.s<b.s;
}
struct Heap
{
	int d[MAXN],tot;
	void init()
	{
		tot=0;
	}
	void rise(int t)
	{
		while (t!=1 && d[t]>d[FA(t)])
		{
			int k=d[t];
			d[t]=d[FA(t)];
			d[FA(t)]=k;
			t=FA(t);
		}
	}
	void sink(int t)
	{
		while ((t<<1) <= tot)
		{
			int maxt=t;
			if (L(t)<=tot) if (d[L(t)]>d[maxt]) maxt=L(t);
			if (R(t)<=tot) if (d[R(t)]>d[maxt]) maxt=R(t);
			if (maxt==t) break;
			int k=d[t];d[t]=d[maxt];d[maxt]=k;t=maxt;
		}
	}
	void push(int f)
	{
		d[++tot]=f;
		rise(tot);
	}
	void pop()
	{
		d[1]=d[tot--];
		sink(1);
	}
}H;
int UpMin[MAXN],DownMin[MAXN];
int main()
{
	scanf("%d%d%d",&N,&C,&F);
	for (int i=1;i<=C;++i)
	{
		scanf("%d%d",&d[i].s,&d[i].f);
	}
	sort(d+1,d+C+1,cmp);
	H.init();
	N>>=1;
	for (int i=1;i<=N;++i) {H.push(d[i].f);UpMin[N]+=d[i].f;}
	for (int i=N+1;i<C;++i)
	{
		UpMin[i]=UpMin[i-1]+d[i].f;
		H.push(d[i].f);
		UpMin[i]-=H.d[1];
		H.pop();
	}
	H.init();
	for (int i=C;i>=C-N+1;--i) {H.push(d[i].f);DownMin[C-N+1]+=d[i].f;}
	for (int i=C-N;i>=1;--i)
	{
		DownMin[i]=DownMin[i+1]+d[i].f;
		H.push(d[i].f);
		DownMin[i]-=H.d[1];
		H.pop();
	}
	int AnsS=-1;
	for (int i=N+1;i<=C-N;++i)
	{
		if (UpMin[i-1]+DownMin[i+1]+d[i].f<=F)
		{
			if (d[i].s>AnsS) AnsS=d[i].s;
		}
	}
	printf("%d\n",AnsS);
	return 0;
}
