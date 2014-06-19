#include <cstdio>
#include <cstring>
#include <cstdlib>
int N,R;
struct LNode
{
	int T;
	struct LNode *up,*down;
	LNode()
	{
		up=down=NULL;
	}
};
void Main()
{
	LNode *bottom=new LNode();
	LNode *p=bottom,*top;
	for (int i=1;i<=N;++i)
	{
		p->up=new LNode();
		p->up->down=p;
		p=p->up;
		p->T=i;
	}
	top=p;
	for (;R;R--)
	{
		int P,C;
		scanf("%d%d",&P,&C);
		p=top;
		if (P==1) continue;
		for (int i=1;i<P;i++) p=p->down;
		LNode *q=p;
		for (int i=1;i<C;++i) q=q->down;
		q->down->up=p->up;
		p->up->down=q->down;
		q->down=top;
		top->up=q;
		p->up=NULL;
		top=p;
	}
	printf("%d\n",top->T);
}
int main()
{
	while (scanf("%d%d",&N,&R),N!=0)
	{
		Main();
	}
	return 0;
}
