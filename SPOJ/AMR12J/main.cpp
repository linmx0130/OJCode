#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 200102
#define MAXVAL MAXN*2
struct Rectan
{
	int x1,y1,x2,y2;
}R[MAXN];
int XRec[MAXVAL],YRec[MAXVAL],Ans[MAXN];
int N,N2;
inline int GetNewValue(int *Rec,int v)
{
	int L=1,R=N2;
	while (L<R)
	{
		int mid=(L+R)>>1;
		if (Rec[mid]>=v) R=mid;
		else L=mid+1;
	}
	return L;
}
struct SegTree
{
	int L[MAXVAL],R[MAXVAL],Lc[MAXVAL],Rc[MAXVAL],V[MAXVAL],Mid[MAXVAL],tot;
	bool Lazy[MAXVAL];
	int BuildTree(int l,int r)
	{
		int now=++tot;
		L[now]=l,R[now]=r;
		V[now]=0;Lazy[now]=0;
		Mid[now]=(l+r)>>1;
		if (l<r)
		{
			Lc[now]=BuildTree(l,Mid[now]);
			Rc[now]=BuildTree(Mid[now]+1,r);
		}
		return now;
	}
	void Init(int N)
	{
		tot=0;
		BuildTree(1,N);
	}
	inline void UnLazy(int now)
	{
		if (Lazy[now])
		{
			if (Lc[now]) 
			{
				V[Lc[now]]=V[now];
				Lazy[Lc[now]]=1;
			}
			if (Rc[now])
			{
				V[Rc[now]]=V[now];
				Lazy[Rc[now]]=1;
			}
			Lazy[now]=0;
		}
	}
	void Modify(int now,int l,int r,int v)
	{
		UnLazy(now);
		if (L[now]==l && R[now]==r)
		{
			Lazy[now]=1;
			V[now]=v;
			return ;
		}
		if (r<=Mid[now]) {Modify(Lc[now],l,r,v);return ;}
		if (l>Mid[now]) {Modify(Rc[now],l,r,v);return ;}
		Modify(Lc[now],l,Mid[now],v);
		Modify(Rc[now],Mid[now]+1,r,v);
	}
	int Query(int now,int pos)
	{
		while (1)
		{
			if (Lazy[now]) 
				return V[now];
			if (L[now]==pos && R[now]==pos)
				return V[now];
			if (pos<=Mid[now]) now=Lc[now];
			else now=Rc[now];
		}
	}
}T;
struct eList
{
	int Head[MAXVAL],Pre[MAXVAL],V[MAXVAL],tot;
	inline void AddEdge(int a,int b)
	{
		++tot;
		V[tot]=b;Pre[tot]=Head[a];Head[a]=tot;
	}
}G,GS;
int main()
{
	scanf("%d",&N);
	N2=N<<1;
	for (int i=1;i<=N;++i)
	{
		scanf("%d%d%d%d",&R[i].x1,&R[i].y1,&R[i].x2,&R[i].y2);
		XRec[(i<<1)-1]=R[i].x1;
		XRec[(i<<1)]=R[i].x2;
		YRec[(i<<1)-1]=R[i].y1;
		YRec[(i<<1)]=R[i].y2;
	}
	std::sort(XRec+1,XRec+N+N+1);
	std::sort(YRec+1,YRec+N+N+1);
	for (int i=1;i<=N;++i)
	{
		R[i].x1=GetNewValue(XRec,R[i].x1);
		R[i].x2=GetNewValue(XRec,R[i].x2);
		R[i].y1=GetNewValue(YRec,R[i].y1);
		R[i].y2=GetNewValue(YRec,R[i].y2);
		G.AddEdge(R[i].x2,i);
		GS.AddEdge(R[i].x1,i);
	}
	T.Init(N*2);
	int point,p;
	for (int i=1;i<=N2;++i)
	{
		for (p=G.Head[i];p;p=G.Pre[p])
		{
			T.Modify(1,R[G.V[p]].y1,R[G.V[p]].y2,Ans[G.V[p]]);
		}
		for (p=GS.Head[i];p;p=GS.Pre[p])
		{
			point=GS.V[p];
			Ans[point]=T.Query(1,R[point].y1);
			T.Modify(1,R[point].y1,R[point].y2,point);
		}
	}
	for (int i=1;i<=N;++i)
	{
		printf("%d\n",Ans[i]-1);
	}
	return 0;
}
