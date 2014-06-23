#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using std::sort;
using std::priority_queue;
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
priority_queue<int> H1,H2;
int UpMin[MAXN],DownMin[MAXN];
int main()
{
	scanf("%d%d%d",&N,&C,&F);
	for (int i=1;i<=C;++i)
	{
		scanf("%d%d",&d[i].s,&d[i].f);
	}
	sort(d+1,d+C+1,cmp);
	N>>=1;
	for (int i=1;i<=N;++i) {H1.push(d[i].f);UpMin[N]+=d[i].f;}
	for (int i=N+1;i<C;++i)
	{
		UpMin[i]=UpMin[i-1]+d[i].f;
		H1.push(d[i].f);
		UpMin[i]-=H1.top();
		H1.pop();
	}
	for (int i=C;i>=C-N+1;--i) {H2.push(d[i].f);DownMin[C-N+1]+=d[i].f;}
	for (int i=C-N;i>=1;--i)
	{
		DownMin[i]=DownMin[i+1]+d[i].f;
		H2.push(d[i].f);
		DownMin[i]-=H2.top();
		H2.pop();
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
