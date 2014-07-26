#include <cstdio>
#include <cstring>
//#include <cstdlib>
#define DEBUG PrintTree(Root);puts("");PrintSeg(Root);puts("\n");
int max(int a,int b) {return a>b?a:b;}
#define MAXN 100000
int N,M,Ttot;
struct Node
{
	int k,s, max,lmax,rmax,sum;
	int c[2],p;
	bool d;
}T[MAXN*2];
int d[MAXN],Root;
char Buf[10];
/*
void PrintTree(int now)
{
	printf("%d: k=%d s=%d c1=%d c2=%d p=%d d=%d\n",now,
		T[now].k,T[now].s,T[now].c[0],T[now].c[1],T[now].p,T[now].d);
	printf("    sum=%d max=%d lmax=%d rmax=%d\n",
				T[now].sum,T[now].max,T[now].lmax,T[now].rmax);
	if (T[now].c[0]) PrintTree(T[now].c[0]);
	if (T[now].c[1]) PrintTree(T[now].c[1]);
}
void PrintSeg(int now)
{
	if (T[now].c[0]) PrintSeg(T[now].c[0]);
	printf("%d ",T[now].k);
	if (T[now].c[1]) PrintSeg(T[now].c[1]);
}
void swap(int &a,int &b){int k=a;a=b;b=k;}
*/
void SetC(int now,int c,int d)
{
	T[now].c[d]=c;T[c].p=now;T[c].d=d;
}
void Updata(int now)
{
	int l=T[now].c[0],r=T[now].c[1];
	T[now].s=T[l].s+T[r].s+1;
	T[now].sum=T[l].sum+T[r].sum+T[now].k;
	T[now].lmax=T[now].rmax=T[now].max=-0x3f3f3f3fll;
	if (l) 
	{
		T[now].lmax=max(T[l].lmax,T[l].sum+T[now].k);
		if (r) T[now].lmax=max(T[now].lmax,T[l].sum+T[now].k+T[r].lmax);
	}else
		if (r)T[now].lmax=max(T[now].k,T[now].k+T[r].lmax);
		else T[now].lmax=T[now].k;
	if (r)
	{
		T[now].rmax=max(T[r].rmax,T[r].sum+T[now].k);
		if (l)T[now].rmax=max(T[now].rmax,T[r].sum+T[now].k+T[l].rmax);
	}
	else 
		if (l)T[now].rmax=max(T[now].k,T[now].k+T[l].rmax);
		else T[now].rmax=T[now].k;

	T[now].max=T[now].k;
	if (l) T[now].max=max(T[now].max,max(T[l].max,T[l].rmax+T[now].k));
	if (r) T[now].max=max(T[now].max,max(T[r].max,T[r].lmax+T[now].k));
	if (l&&r) T[now].max=max(T[now].max,T[r].lmax+T[now].k+T[l].rmax);
}
int NewNode(int v)
{
	++Ttot;
	T[Ttot].k=T[Ttot].sum=T[Ttot].max=T[Ttot].lmax=T[Ttot].rmax=v;
	T[Ttot].s=1;
	T[Ttot].c[0]=T[Ttot].c[1]=0;
	return Ttot;
}
int BuildTree(int L,int R,int fa)
{
	int mid=(L+R)>>1;
	int now=++Ttot;
	Node &t=T[now];
	t.k=t.sum=t.max=t.lmax=t.rmax=d[mid];
	t.p=fa;
	if (L<mid) {t.c[0]=BuildTree(L,mid-1,now),T[t.c[0]].d=0;}
	if (mid<R) {t.c[1]=BuildTree(mid+1,R,now),T[t.c[1]].d=1;}
	Updata(now);
	return now;
}
void Rotate(int now)
{
	int p=T[now].p;bool d=T[now].d;
	SetC(p,T[now].c[!d],d);
	SetC(T[p].p,now,T[p].d);
	SetC(now,p,!d);
	Updata(p);Updata(now);
}
void Splay(int now,int f)
{
	while (T[now].p!=f)
	{
		if (T[T[now].p].p==f) Rotate(now);
		else (T[now].d==T[T[now].p].d) ? (Rotate(T[now].p),Rotate(now)):
			(Rotate(now),Rotate(now));
	}
	if (f==0) Root=now;
}
int FindKth(int now,int k)
{
	while (1)
	{
		if (T[T[now].c[0]].s+1==k) return now;
		if (k<=T[T[now].c[0]].s) now=T[now].c[0];
		else 
		{
			k-=T[T[now].c[0]].s+1;
			now=T[now].c[1];
		}
	}
}
void Insert(int x,int y)
{
	int t;
	Splay(FindKth(Root,x),0);
	Splay(t=FindKth(T[Root].c[0],x-1),Root);
	int p=NewNode(y);
	SetC(t,p,1);
	Updata(t);Updata(Root);
}
void Delete(int x)
{
	Splay(FindKth(Root,x),0);
	Splay(FindKth(T[Root].c[0],x-1),Root);
	SetC(T[Root].c[0],T[Root].c[1],1);
	Root=T[Root].c[0];
	T[Root].p=0;
	Updata(Root);
}
void Replace(int x,int y)
{
	Splay(FindKth(Root,x),0);
	T[Root].k=y;
	Updata(Root);
}
int Query(int x,int y)
{
	Splay(FindKth(Root,x),0);
	Splay(FindKth(Root,y),Root);
	return T[T[T[Root].c[1]].c[0]].max;
}
int main()
{
	scanf("%d\n",&N);
	T[0].k=T[0].max=T[0].lmax=T[0].rmax=-0x7fffffff;
	T[0].sum=0;
	N+=2;
	d[0]=d[N]=0;
	for (int i=2;i<N;++i) scanf("%d",&d[i]);
	Root=BuildTree(1,N,0);
	scanf("%d\n",&M);
	int x,y;
	for (int i=1;i<=M;++i)
	{
		//printf("Operate %d:\n",i);
		scanf("%s",Buf);
		if (Buf[0]=='I')
		{
			scanf(" %d %d\n",&x,&y);
			Insert(x+1,y);
		}
		if (Buf[0]=='D')
		{
			scanf(" %d\n",&x);
			Delete(x+1);
		}
		if (Buf[0]=='R')
		{
			scanf(" %d %d\n",&x,&y);
			Replace(x+1,y);
		}
		if (Buf[0]=='Q')
		{
			scanf(" %d %d\n",&x,&y);
			printf("%d\n",Query(x,y+2));
		}
//DEBUG;
	}
	return 0;
}
