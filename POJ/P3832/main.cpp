#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define MAXSIZE 50002
#define MAXN 50002
struct SegTreeNode
{
	int F,L,R,Cover;
	int Lc,Rc;
};
struct SegTree
{
	SegTreeNode d[MAXSIZE*4];
	int CoverLen[MAXSIZE*4];
	int NodeTot;
	void BuildTree(int now,int L,int R)
	{
		d[now].L=L;d[now].R=R;
		if (L==R) return ;
		int Mid=(L+R)>>1;
		++NodeTot;
		d[NodeTot].F=now;
		d[now].Lc=NodeTot;
		BuildTree(NodeTot,L,Mid);
		++NodeTot;
		d[NodeTot].F=now;
		d[now].Rc=NodeTot;
		BuildTree(NodeTot,Mid+1,R);
	}
	void init()
	{
		for (int i=1;i<=NodeTot;++i)
		{
			d[i].Cover=0;
		}
	}
	void GetLen(int now)
	{
		if (d[now].Cover) CoverLen[now]=d[now].R-d[now].L+1;
		else CoverLen[now]=CoverLen[d[now].Lc]+CoverLen[d[now].Rc];
	}
	void Mark(int now,int L,int R,int Delta)
	{
		if (L>R)
		{
			return ;
		}
		if ((d[now].L==L)&&(d[now].R==R))
		{
			d[now].Cover+=Delta;
			GetLen(now);
			GetLen(d[now].F);
			return ;
		}
		int Mid=(d[now].L+d[now].R)>>1;
		if (R<=Mid)
		{
			Mark(d[now].Lc,L,R,Delta);
			GetLen(d[now].F);
			return ;
		}
		if (L>Mid)
		{
			Mark(d[now].Rc,L,R,Delta);
			GetLen(d[now].F);
			return ;
		}
		Mark(d[now].Lc,L,Mid,Delta);
		Mark(d[now].Rc,Mid+1,R,Delta);
		GetLen(d[now].F);
		return ;
	}
}T;
struct eList
{
	int Head[MAXSIZE],Pre[MAXN*4],V[MAXN*4],tot;
	void Add(int a,int b)
	{
		++tot;
		V[tot]=b;
		Pre[tot]=Head[a];
		Head[a]=tot;
	}
	void init()
	{
		memset(Pre,0,sizeof(Pre));
		memset(Head,0,sizeof(Head));
		tot=0;
	}
}Header,Bottom;
struct Rect
{
	int x1,x2,y1,y2;
}d[MAXN*4];
int N,DTot;
int XList[MAXSIZE*8],XTot;
void InputMethod()
{
	DTot=XTot=0;
	for (int i=1;i<=N;++i)
	{
		int x1,y1,x2,y2,x3,y3,x4,y4;
		scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		++DTot;
		d[DTot].x1=x1;
		d[DTot].x2=x3;
		d[DTot].y1=y1;
		d[DTot].y2=y2;
		Header.Add(d[DTot].x1,DTot);
		Bottom.Add(d[DTot].x2,DTot);
		XList[++XTot]=d[DTot].x1;
		XList[++XTot]=d[DTot].x2;

		++DTot;
		d[DTot].x1=x4;
		d[DTot].x2=x2;
		d[DTot].y1=y1;
		d[DTot].y2=y2;
		Header.Add(d[DTot].x1,DTot);
		Bottom.Add(d[DTot].x2,DTot);
		XList[++XTot]=d[DTot].x1;
		XList[++XTot]=d[DTot].x2;

		++DTot;
		d[DTot].x1=x3;
		d[DTot].x2=x4;
		d[DTot].y1=y1;
		d[DTot].y2=y3;
		Header.Add(d[DTot].x1,DTot);
		Bottom.Add(d[DTot].x2,DTot);
		XList[++XTot]=d[DTot].x1;
		XList[++XTot]=d[DTot].x2;

		++DTot;
		d[DTot].x1=x3;
		d[DTot].x2=x4;
		d[DTot].y1=y4;
		d[DTot].y2=y2;
		Header.Add(d[DTot].x1,DTot);
		Bottom.Add(d[DTot].x2,DTot);
		XList[++XTot]=d[DTot].x1;
		XList[++XTot]=d[DTot].x2;
	}
};
void Main()
{
	T.init();
	Header.init();
	Bottom.init();
	InputMethod();
	std::sort(XList+1,XList+XTot+1);
	XList[0]=-1;
	int LastX=0;
	unsigned int Ans=0;
	for (int i=1;i<=XTot;++i)
	{
		if (XList[i]!=XList[i-1])
		{
			Ans+=T.CoverLen[1]*(XList[i]-LastX);
			LastX=XList[i];
			for (int p=Header.Head[XList[i]];p;p=Header.Pre[p])
			{
				T.Mark(1,d[Header.V[p]].y1+1,d[Header.V[p]].y2,1);
			}
			for (int p=Bottom.Head[XList[i]];p;p=Bottom.Pre[p])
			{
				T.Mark(1,d[Bottom.V[p]].y1+1,d[Bottom.V[p]].y2,-1);
			}
		}
	}
	printf("%u\n",Ans);
}
int main()
{
	T.NodeTot=1;
	T.BuildTree(1,0,50000);
	while (scanf("%d",&N),N)
	{
		Main();
	}
	return 0;
}
