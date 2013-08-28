#include <cstdio>
#include <cstdlib>
#include <cstring>
struct Node
{
	Node *Lc,*Rc;
	int rL,rR;
	long long Sum;
	long long Lazy;
	Node(int L,int R)
	{
		Lc=Rc=NULL;
		rL=L;rR=R;Sum=0;Lazy=0;
	}
	void UnLazy()
	{
		if (Lc)
		{
			Lc->Sum+=Lazy*(Lc->rR-Lc->rL+1);
			Lc->Lazy+=Lazy;
		}
		if (Rc)
		{
			Rc->Sum+=Lazy*(Rc->rR-Rc->rL+1);
			Rc->Lazy+=Lazy;
		}
		Lazy=0;
	}
	void Plus(int L,int R,int d)
	{
		Sum+=(long long)d*(R-L+1);
		if (rL==L&&rR==R)
		{
			Lazy+=d;
			return ;
		}
		if (Lazy) UnLazy();
		int mid=(rL+rR)>>1;
		if (R<=mid)
		{
			Lc->Plus(L,R,d);
			return ;
		}
		if (L>mid)
		{
			Rc->Plus(L,R,d);
			return ;
		}
		Lc->Plus(L,mid,d);
		Rc->Plus(mid+1,R,d);
	}
	long long Query(int L,int R)
	{
		if (Lazy) UnLazy();
		if (rL==L&&rR==R)
		{
			return Sum;
		}
		int mid=(rL+rR)>>1;
		if (R<=mid) return Lc->Query(L,R);
		if (L>mid) return Rc->Query(L,R);
		return Lc->Query(L,mid)+Rc->Query(mid+1,R);
	}
}*T;
int N;
void BuildTree(Node *T)
{
	if (T->rL==T->rR) return ;
	int mid=(T->rL+T->rR)>>1;
	T->Lc=new Node(T->rL,mid);
	T->Rc=new Node(mid+1,T->rR);
	BuildTree(T->Lc);BuildTree(T->Rc);
}
int main()
{
	scanf("%d",&N);
	T=new Node(1,N);
	BuildTree(T);
	for (int i=1;i<=N;++i)
	{
		int x;
		scanf("%d",&x);
		T->Plus(i,i,x);
	}
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		int o;
		scanf("%d",&o);
		if (o==1)
		{
			int a,b,x;
			scanf("%d%d%d",&a,&b,&x);
			T->Plus(a,b,x);
		}
		if (o==2)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			printf("%lld\n",T->Query(a,b));
		}
	}
	return 0;
}

