#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 100005
#define LEN(t) (T[t].rR-T[t].rL+1)
#define MAINTAIN(t) T[t].S=T[T[t].L].S+T[T[t].R].S
struct SegTreeNode
{
	int rL,rR,L,R;
	long long S,Lazy;
}T[MAXN*17];
int N,Q,Cnt=0;
int BuildTree(int L,int R)
{
	int now=++Cnt;
	T[now].rL=L;T[now].rR=R;
	T[now].S=T[now].L=T[now].R=0;
	T[now].Lazy=0;
	if (L<R)
	{
		int mid=(L+R)>>1;
		T[now].L=BuildTree(L,mid);
		T[now].R=BuildTree(mid+1,R);
	}
	return now;
}
void UnLazy(int now)
{
	if (T[now].L)
	{
		T[T[now].L].S+=T[now].Lazy*LEN(T[now].L);
		T[T[now].L].Lazy+=T[now].Lazy;
	}
	if (T[now].R)
	{
		T[T[now].R].S+=T[now].Lazy*LEN(T[now].R);
		T[T[now].R].Lazy+=T[now].Lazy;
	}
	T[now].Lazy=0;
}
void Add(int now,int rL,int rR,long long c)
{
	if (T[now].Lazy) UnLazy(now);
	if ((T[now].rL==rL)&&(T[now].rR==rR))
	{
		T[now].S+=c*LEN(now);
		T[now].Lazy=c;
		return ;
	}
	if (rR<=T[T[now].L].rR) 
	{
		Add(T[now].L,rL,rR,c);
		MAINTAIN(now);
		return ;
	}
	if (rL>=T[T[now].R].rL) 
	{
		Add(T[now].R,rL,rR,c);
		MAINTAIN(now);
		return ;
	}
	int mid=(T[now].rL+T[now].rR)>>1;
	Add(T[now].L,rL,mid,c);
	Add(T[now].R,mid+1,rR,c);
	MAINTAIN(now);
}
long long Query(int now,int rL,int rR)
{
	UnLazy(now);
	if ((T[now].rL==rL)&&(T[now].rR==rR)) return T[now].S;
	if (rR<=T[T[now].L].rR) return Query(T[now].L,rL,rR);
	if (rL>=T[T[now].R].rL) return Query(T[now].R,rL,rR);
	int mid=(T[now].rL+T[now].rR)>>1;
	return Query(T[now].L,rL,mid)+Query(T[now].R,mid+1,rR);
}
char Buf[5];
int main()
{
	scanf("%d%d",&N,&Q);
	BuildTree(1,N);
	for (int i=1;i<=N;++i)
	{
		int t;
		scanf("%d",&t);
		Add(1,i,i,t);
	}
	for (int i=1;i<=Q;++i)
	{
		scanf("%s",Buf);
		if (Buf[0]=='Q')
		{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%lld\n",Query(1,a,b));
		}
		if (Buf[0]=='C')
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			Add(1,a,b,c);
		}
	}
	return 0;
}
