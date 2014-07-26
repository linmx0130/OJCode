#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using std::max;
#define MAXN 50005
struct SegTree
{
	int L,R;
	long long max,lmax,rmax,sum;
	int Lc,Rc;
}T[MAXN*4];
int N,Ttot;
int d[MAXN];
void Updata(int now)
{
	if (T[now].Lc && T[now].Rc)
	{
		int lc=T[now].Lc,rc=T[now].Rc;
		T[now].sum=T[lc].sum+T[rc].sum;
		T[now].max=max(T[lc].max,T[rc].max);
		T[now].max=max(T[now].max,T[lc].rmax+T[rc].lmax);
		T[now].lmax=max(T[lc].lmax,T[lc].sum+T[rc].lmax);
		T[now].rmax=max(T[rc].rmax,T[rc].sum+T[lc].rmax);
	}
}
int BuildTree(int L,int R)
{
	int now=++Ttot;
	T[now].L=L,T[now].R=R;
	if (L==R)
	{
		T[now].max=T[now].lmax=T[now].rmax=T[now].sum=d[L];
	}else
	{
		int mid=(L+R)>>1;
		T[now].Lc=BuildTree(L,mid);
		T[now].Rc=BuildTree(mid+1,R);
		Updata(now);
	}
	return now;
}
void Modify(int now,int pos,int y)
{
	if (T[now].L==pos && T[now].R==pos)
	{
		T[now].max=T[now].lmax=T[now].rmax=T[now].sum=y;
		return ;
	}
	if (pos<=T[T[now].Lc].R) Modify(T[now].Lc,pos,y);
	else Modify(T[now].Rc,pos,y);
	Updata(now);
}
long long QueryR(int now,int L,int R)
{
	if (R!=T[now].R) 
	{puts("Oooops!");exit(0);}
	if (T[now].L==L && T[now].R==R) return T[now].rmax;
	int mid=(T[now].L+T[now].R)>>1;
	if (L>mid) return QueryR(T[now].Rc,L,R);
	return max( QueryR(T[now].Rc,mid+1,R) , QueryR(T[now].Lc,L,mid)+T[T[now].Rc].sum );
}
long long QueryL(int now,int L,int R)
{
	if (L!=T[now].L) 
	{puts("Oooops!");exit(0);}
	if (T[now].L==L && T[now].R==R) return T[now].lmax;

	int mid=(T[now].L+T[now].R)>>1;
	
	if (R<=mid) return QueryL(T[now].Lc,L,R);
	
	return max( QueryL(T[now].Lc,L,mid) , QueryL(T[now].Rc,mid+1,R)+T[T[now].Lc].sum );
}
long long Query(int now,int L,int R)
{
	if (T[now].L==L && T[now].R==R)
	{
		return T[now].max;
	}
	if (R<=T[T[now].Lc].R) return Query(T[now].Lc,L,R);
	if (L>T[T[now].Lc].R) return Query(T[now].Rc,L,R);
	int mid=T[T[now].Lc].R;
	long long Ret=max(Query(T[now].Lc,L,mid),Query(T[now].Rc,mid+1,R));
	Ret=max(Ret,QueryR(T[now].Lc,L,mid)+QueryL(T[now].Rc,mid+1,R));
	return Ret;
}
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;++i) scanf("%d",&d[i]);	
	BuildTree(1,N);
	int Q;scanf("%d",&Q);
	for (;Q;Q--) 
	{
		int o,x,y;
		scanf("%d%d%d",&o,&x,&y);
		if (o==0)
		{
			Modify(1,x,y);
		}
		if (o==1)
		{
			printf("%lld\n",Query(1,x,y));
		}
	}
	return 0;
}
