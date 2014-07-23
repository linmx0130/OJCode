#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 100003
int N;
struct People
{
	int s,b,k;
}d[MAXN];
bool cmp(const People & a, const People &b)
{
	return a.s!=b.s?a.s<b.s:a.b<b.b;
}
int Q[MAXN],Qt;
int Last[MAXN];
int Ans,AnsL[MAXN];
int F[MAXN][2];
struct SegTreeNode
{
	int L,R,Ans,Anst;
	SegTreeNode *Lc,*Rc;
	SegTreeNode(int L,int R)
	{
		this->L=L;this->R=R;Ans=Anst=0;
		this->Lc=this->Rc=NULL;
	}
	void Modify(int d,int b,int t)
	{
		if (b>Ans) {Ans=b;Anst=t;}
		if (L!=R)
		{
			int mid=(L+R)>>1;
			if (d<=mid)
			{
				if (Lc!=NULL) Lc->Modify(d,b,t);
				else{Lc=new SegTreeNode(L,mid);Lc->Modify(d,b,t);}
			}else
			{
				if (Rc!=NULL) Rc->Modify(d,b,t);
				else{Rc=new SegTreeNode(mid+1,R);Rc->Modify(d,b,t);}
			}
		}
	}
	int Find(int L,int R)
	{
		if (this->L==L && this->R==R) return this->Anst;
		int mid=(this->L+this->R)>>1;
		if (L>mid) if (Rc) return Rc->Find(L,R);else return 0;
		if (R<=mid) if (Lc) return Lc->Find(L,R);else return 0;
		int t1=0,t2=0;
		if (Lc) t1=Lc->Find(L,mid);
		if (Rc) t2=Rc->Find(mid+1,R);
		if (F[t1][0]>F[t2][0]) return t1;
		else return t2;
	}
};
void Print(int now)
{
	if (now==0) return ;
	Print (F[now][1]);
	printf("%d ",d[now].k);
}
int main()
{
	freopen("people.in","r",stdin);
	freopen("people.out","w",stdout);
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		scanf("%d%d",&d[i].s,&d[i].b);
		d[i].k=i;
	}
	std::sort(d+1,d+N+1,cmp);
	F[1][0]=1;F[1][1]=0;
	SegTreeNode *T;T=new SegTreeNode(1,1000000002);
	int LastS=1,Start2;
	for (int i=2;i<=N;++i)
	{
		if (d[i].s==d[1].s)
		{
			F[i][0]=1;F[i][1]=0;
		}else 
		{
			Start2=i;
			break;
		}
	}
	for (int i=Start2;i<=N;++i)
	{
		if (d[i].s!=d[LastS].s)
		{
			for (int j=LastS;j<i;++j)
			{
				T->Modify(d[j].b,F[j][0],j);
			}
			LastS=i;
		}
		int t=T->Find(1,d[i].b-1);
		F[i][0]=F[t][0]+1;F[i][1]=t;
	}
	int maxt=1;
	for (int i=2;i<=N;++i)
	{
		if (F[i][0]>F[maxt][0]) maxt=i;
	}
	printf("%d\n",F[maxt][0]);
	Print(maxt);
	puts("");
	return 0;
}
