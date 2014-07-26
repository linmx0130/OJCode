#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 300203
#define DEBUG(t) puts(t);PrintTree(Root,0);puts("");CheckTree(Root);puts("");
int N,M,Ttot;
struct Node
{
	int k,s;
	int c[2],p;
	bool rv,d;
}T[MAXN];
int d[MAXN],Root;
int Seg[MAXN],SegTot;
char Buf[10];
void swap(int &a,int &b){int k=a;a=b;b=k;}
inline void SetC(int now,int c,bool d)
{
	T[now].c[d]=c;T[c].p=now;T[c].d=d;
}
inline void Updata(int now)
{
	T[now].s=T[T[now].c[0]].s+T[T[now].c[1]].s+1;
}
inline int BuildTree(int L,int R,int fa)
{
	int now=++Ttot;
	int mid=(L+R)>>1;
	T[now].k=d[mid];T[now].c[0]=T[now].c[1]=0;
	T[now].rv=0;
	T[now].p=fa;
	if (L<mid) {T[now].c[0]=BuildTree(L,mid-1,now);T[T[now].c[0]].d=0;}
	if (mid<R) {T[now].c[1]=BuildTree(mid+1,R,now);T[T[now].c[1]].d=1;}
	Updata(now);
	return now;
}
inline void UnLazy(int now)
{
	if (T[now].rv)
	{
		int l=T[now].c[0],r=T[now].c[1];
		if (l) T[l].rv^=1,T[l].d^=1;
		if (r) T[r].rv^=1,T[r].d^=1;
		swap(T[now].c[0],T[now].c[1]);
		T[now].rv=0;
	}
}
inline void Rotate(int now)
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
		UnLazy(T[now].p);
		UnLazy(now);
		if (T[T[now].p].p==f) Rotate(now);
		else (T[now].d==T[T[now].p].d) ? (Rotate(T[now].p),Rotate(now)):
			(Rotate(now),Rotate(now));
	}
	if (f==0) Root=now;
}
inline int FindRank(int now,int t)
{
	while (1)
	{
		UnLazy(now);
		if (T[T[now].c[0]].s+1==t) return now;
		if (t<=T[T[now].c[0]].s) now=T[now].c[0];
		else t-=T[T[now].c[0]].s+1,now=T[now].c[1];
	}
}
void PrintTree(int now,int rv)
{
	rv^=T[now].rv;
	int l=T[now].c[0],r=T[now].c[1];
	if (rv)
	{
		swap(l,r);
	}
	if (l) PrintTree(l,rv);
	printf("%d ",T[now].k);
	if (r) PrintTree(r,rv);
}
void PrintSeg(int now)
{
	UnLazy(now);
	int l=T[now].c[0],r=T[now].c[1];
	if (l) PrintSeg(l);
	Seg[++SegTot]=T[now].k;
	if (r) PrintSeg(r);
}

void CheckTree(int now)
{
	int l=T[now].c[0],r=T[now].c[1];
	if (l) if (T[l].p!=now) puts("Ooops!");
	if (r) if (T[r].p!=now) puts("Ooops!");
	if (l) if (T[l].d) puts("Oooooops!"); else CheckTree(l);
	if (r) if (!T[r].d) puts("Oooooops!"); else CheckTree(r);
}
void Cut(int a,int b,int c)
{
	//a=a+1-1
	b=b+2; //b=b+1+1
	c=c+1;
	Splay(FindRank(Root,a),0);
	Splay(FindRank(Root,b),Root);
	int t1=T[Root].c[1];
	int t2=T[t1].c[0];
	T[t1].c[0]=0;
	T[t2].p=0;
	Updata(t1);
	Updata(Root);

	Splay(FindRank(Root,c),0);
	Splay(FindRank(Root,c+1),Root);
	SetC(T[Root].c[1],t2,0);
	Updata(T[Root].c[1]);Updata(Root);
}
void Flip(int a,int b)
{
	//a=a+1-1;
	b=b+2;//b=b+1+1
	Splay(FindRank(Root,a),0);
	//DEBUG("Flip 1:")
	Splay(FindRank(Root,b),Root);
	//DEBUG("Flip 2:")
	int t=T[T[Root].c[1]].c[0];
	UnLazy(t);
	T[t].rv=1;
}
void Main()
{
	Ttot=0;
	N+=2;
	for (int i=2;i<N;++i) d[i]=i-1;
	d[1]=-233;d[N]=-233;
	Ttot=0;
	Root=BuildTree(1,N,0);
	//DEBUG("Start")
	for (;M;M--)
	{
		scanf("%s",Buf);
		if (Buf[0]=='C')
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			Cut(a,b,c);
	//		DEBUG("After Cut")
		}else
		{
			int a,b;
			scanf("%d%d",&a,&b);
			Flip(a,b);		
	//		DEBUG("After Flip")
		}
	}
	SegTot=0;
	PrintSeg(Root);
	SegTot--;
	for (int i=2;i<SegTot;++i) printf("%d ",Seg[i]);
	printf("%d\n",Seg[SegTot]);
}
int main()
{
	while (scanf("%d%d",&N,&M),N>0) Main();
	return 0;
}
