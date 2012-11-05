#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 100002
int N;
inline int Sqr(int x)
{
	return x*x;
}
inline int Dis(int x1,int y1,int x2,int y2)
{
	return Sqr(x1-x2)+Sqr(y1-y2); 
}
struct HeapAtom
{
	int Id,Dis;
};
bool cmp(HeapAtom a,HeapAtom b)
{
	return a.Dis<b.Dis;
}
#define FA(t) (t>>1)
#define L(t) (t<<1)
#define R(t) (L(t)+1)
struct Heap
{
	HeapAtom d[MAXN],k;
	int tot;
	void rise(int t)
	{
		while (t>1)
		{
			if (d[FA(t)].Dis<d[t].Dis)
			{
				k=d[FA(t)];
				d[FA(t)]=d[t];
				d[t]=k;
				t=FA(t);
			}else break;
		}
	}
	void sink(int t)
	{
		while (t<=tot)
		{
			int mint=t;
			if (L(t)<=tot) if (d[L(t)].Dis>d[mint].Dis) mint=L(t);
			if (R(t)<=tot) if (d[R(t)].Dis>d[mint].Dis) mint=R(t);
			if (mint==t) return ;
			k=d[t];
			d[t]=d[mint];
			d[mint]=k;
			t=mint;
		}
	}
	void Push(int Id,int Dis)
	{
		++tot;
		d[tot].Id=Id;
		d[tot].Dis=Dis;
		rise(tot);
	}
	void Pop()
	{
		d[1]=d[tot--];
		sink(1);
	}
}H;
bool Used[MAXN];
int Pos[MAXN][2];
int X1,Y1,X2,Y2;
HeapAtom d[MAXN];
int main()
{
	scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		scanf("%d%d",&Pos[i][0],&Pos[i][1]);
		d[i].Id=i;
		d[i].Dis=Dis(X1,Y1,Pos[i][0],Pos[i][1]);
		H.Push(i,Dis(X2,Y2,Pos[i][0],Pos[i][1]));
	}
	std::sort(d+1,d+N+1,cmp);
	int Ans=0x7fffffff;
	for (int i=1;i<=N;++i)
	{
		Used[d[i].Id]=1;
		while (H.tot&&Used[H.d[1].Id]) H.Pop();
		int Tmp=d[i].Dis;
		if (H.tot) Tmp+=H.d[1].Dis;
		if (Tmp<Ans) Ans=Tmp;
	}
	printf("%d\n",Ans);
	return 0;
}
