#include <cstdio>
#include <cstring>
#include <cstdlib>
struct Node
{
	Node *Lc,*Rc;
	int rL,rR;
	long long sum;
	Node(int L,int R)
	{
		rL=L,rR=R;
		Lc=Rc=NULL;
		sum=0;
	}
	void Plus(int pos,int A)
	{
		sum+=A;
		if (rL==rR)
		{
			return ;
		}
		int mid=(rL+rR)>>1;
		if (pos<=mid) Lc->Plus(pos,A);
		else Rc->Plus(pos,A);
	}
	long long Sum(int L,int R)
	{
		if ((rL==L)&&(rR==R))
		{
			return sum;
		}
		int mid=(rL+rR)>>1;
		if (R<=mid) return Lc->Sum(L,R);
		if (L>mid) return Rc->Sum(L,R);
		long long Ans=0;
		Ans+=Lc->Sum(L,mid);
		Ans+=Rc->Sum(mid+1,R);
		return Ans;
	}
}*T;
int N;
void BuildTree(Node *T,int L,int R)
{
	if (L==R) return ;
	int mid=(L+R)>>1;
	T->Lc=new Node(L,mid);
	T->Rc=new Node(mid+1,R);
	BuildTree(T->Lc,L,mid);
	BuildTree(T->Rc,mid+1,R);
}
int main()
{
	scanf("%d",&N);
	T=new Node(1,N);
	BuildTree(T,1,N);
	for (int i=1;i<=N;++i)
	{
		int a;
		scanf("%d",&a);
		T->Plus(i,a);
	}
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		int o,a,b;
		scanf("%d%d%d",&o,&a,&b);
		if (o==1)
		{
			T->Plus(a,b);
		}else 
		{
			printf("%d\n",T->Sum(a,b));
		}
	}
	return 0;
}
