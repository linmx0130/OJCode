#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using std::map;
int N;
#define MAXN 8005
struct SegTree
{
	int d[MAXN*4],L[MAXN*4],R[MAXN*4],rl[MAXN*4],rr[MAXN*4],tot;
	int Line[MAXN];
	bool lazy[MAXN*4];
	void build(int l,int r,int now){
		d[now]=-1;
		lazy[now]=0;
		rl[now]=l;rr[now]=r;
		L[now]=R[now]=0;
		if (l==r) return ;
		int mid=(l+r)>>1;
		if (l<=mid)
		{
			L[now]=++tot;
			build(l,mid,tot);
		}
		if (mid<r)
		{
			R[now]=++tot;
			build(mid+1,r,tot);
		}
	}
	void init(int n){
		memset(d,0,sizeof(d));
		memset(Line,0,sizeof(Line));
		memset(L,0,sizeof(L));
		memset(R,0,sizeof(R));
		build(0,n,0);
		tot=0;
	}
	void unlazy(int now){
		lazy[now]=0;
		if (L[now])
		{
			lazy[L[now]]=1;
			d[L[now]]=d[now];
		}
		if (R[now])
		{
			lazy[R[now]]=1;
			d[R[now]]=d[now];
		}
	}
	void modify(int l,int r,int c,int now){
		if (lazy[now]) unlazy(now);
		if (l>r)
		{
			fprintf(stderr,"Oooops!");
		}
		if (rl[now]==l&&rr[now]==r)
		{
			d[now]=c;
			lazy[now]=1;
			return ;
		}
		int mid=(rl[now]+rr[now])>>1;
		//All left
		if (r<=mid)
		{
			modify(l,r,c,L[now]);
			return ;
		}
		//All right
		if (l>mid)
		{
			modify(l,r,c,R[now]);
			return ;
		}
		modify(l,mid,c,L[now]);
		modify(mid+1,r,c,R[now]);
	}
	int Query(int now){
		if (lazy[now])unlazy(now);
		if (rl[now]==rr[now])
		{
			Line[rl[now]]=d[now];
		}
		if (L[now]) Query(L[now]);
		if (R[now]) Query(R[now]);
	}
}T;
int Work[MAXN][3];
int Color[MAXN];
void Main()
{
	int MaxR=0;
	for (int i=0;i<N;++i)
	{
		scanf("%d%d%d",&Work[i][0],&Work[i][1],&Work[i][2]);
		Work[i][0]++;
		if (Work[i][1]>MaxR) MaxR=Work[i][1];
	}
	T.init(MaxR);
	for (int i=0;i<N;++i)
	{
		T.modify(Work[i][0],Work[i][1],Work[i][2],0);
	}
	T.Query(0);
	memset(Color,0,sizeof(Color));
	int Last=T.Line[1];
	for (int i=2;i<=MaxR;++i)
	{
		if (T.Line[i]!=Last)
		{
			if (Last!=-1)
			{
				Color[Last]++;
			}
			Last=T.Line[i];
		}
	}
	if (Last!=-1) Color[Last]++;
	for (int i=0;i<=8000;++i)
	{
		if (Color[i]) printf("%d %d\n",i,Color[i]);
	}
}
int main()
{
	while (~scanf("%d",&N))
	{
		Main();
		puts("");
	}
	return 0;
}
