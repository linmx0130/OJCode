#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#define MAXN 500005
#define FA(t) (t>>1)
#define L(t) (t<<1)
#define R(t) (L(t)+1)
struct Heap
{
	int tot,d[MAXN],Key[MAXN],To[MAXN];
	void rise(int t)
	{
		while (t>1)
		{
			if (d[t]<d[FA(t)])
			{
				int k=d[t];d[t]=d[FA(t)];d[FA(t)]=k;
				k=Key[t];Key[t]=Key[FA(t)];Key[FA(t)]=k;
				To[Key[t]]=t;
				To[Key[FA(t)]]=FA(t);
				t=FA(t);
			}else break;
		}
	}
	void sink(int t)
	{
		while (t<=tot)
		{
			int mint=t;
			if (L(t)<=tot) if (d[L(t)]<d[mint]) mint=L(t);
			if (R(t)<=tot) if (d[R(t)]<d[mint]) mint=R(t);
			if (mint==t) return ;
			int k=d[t];d[t]=d[mint];d[mint]=k;
			k=Key[t];Key[t]=Key[mint];Key[mint]=k;
			To[Key[t]]=t;
			To[Key[mint]]=mint;
			t=mint;
		}
	}
	void Push(int key,int v)
	{
		++tot;
		d[tot]=v;Key[tot]=key;To[key]=tot;
		rise(tot);
	}
	void Modify(int key,int v)
	{
		int t=To[key];
		if (v>d[t])
		{
			d[t]=v;
			sink(t);
		}else
		{
			d[t]=v;
			rise(t);
		}
	}
}H;
struct Treap
{
	int L[MAXN*2],R[MAXN*2],V[MAXN*2],Key[MAXN*2],tot,Root;
	int Find_Ret,seed;
	Treap()
	{
		seed=0xAC;
	}
	void rot_r(int &x)
	{
		int k=L[x];
		L[x]=R[k];
		R[k]=x;
		x=k;
	}
	void rot_l(int &x)
	{
		int k=R[x];
		R[x]=L[k];
		L[k]=x;
		x=k;
	}
	int Insert(int &now,int d)
	{
		if (!now)
		{
			now=++tot;
			V[now]=d;
			Key[now]=seed*=113;
			return Key[now];
		}
		if (d<=V[now])
		{
			if (Insert(L[now],d)>Key[now])
			{
				rot_r(now);
			}
		}else
		{
			if(Insert(R[now],d)>Key[now])
			{
				rot_l(now);
			}
		}
		return Key[now];
	}
	int Find_Lower(int now,int d)
	{
		Find_Ret=-0x40000000;
		while (now)
		{
			if (V[now]==d) 
			{
				Find_Ret=V[now];
				break;
			}
			if (V[now]<d)
			{
				if (V[now]>Find_Ret) Find_Ret=V[now];
				now=R[now];
			}
			else
			{
				now=L[now];
			}
		}
		return Find_Ret;
	}
	int Find_Upper(int now,int d)
	{
		Find_Ret=0x40000000;
		while (now)
		{
			if (V[now]==d) 
			{
				Find_Ret=V[now];
				break;
			}
			if (V[now]>d)
			{
				if (V[now]<Find_Ret) Find_Ret=V[now];
				now=L[now];
			}
			else
			{
				now=R[now];
			}
		}
		return Find_Ret;
	}
}T;
int Seq[MAXN],BeforeMeMin=0x7fffffff;
int Saq[MAXN];
int N,M;
inline int Abs(int a){return a>0?a:-a;}
inline int Min(int a,int b){return a<b?a:b;}
int MinSortGap=0x7fffffff;
int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;++i) 
	{
		scanf("%d",&Seq[i]);
		Saq[i]=Seq[i];
		if (i>1)
		{
			int tmp=T.Find_Lower(T.Root,Seq[i]);
			if (MinSortGap>Seq[i]-tmp) MinSortGap=Seq[i]-tmp;
			tmp=T.Find_Upper(T.Root,Seq[i]);
			if (MinSortGap>tmp-Seq[i]) MinSortGap=tmp-Seq[i];
		}
		T.Insert(T.Root,Seq[i]);
	}
	for (int i=1;i<N;++i)
	{
		H.Push(i,Abs(Seq[i]-Seq[i+1]));
	}
	char buf[30];
	for (;M;M--)
			
	{
		scanf("%s",buf);
		if (buf[0]=='I')
		{
			int A,B;
			scanf("%d%d",&A,&B);
			BeforeMeMin=Min(BeforeMeMin,Abs(Seq[A]-B));
			if (A<N)H.Modify(A,Abs(Saq[A+1]-B));
			Seq[A]=B;
			if (MinSortGap!=0){
				int tmp=T.Find_Lower(T.Root,B);
				if (MinSortGap>B-tmp) MinSortGap=B-tmp;
				tmp=T.Find_Upper(T.Root,B);
				if (MinSortGap>tmp-B) MinSortGap=tmp-B;
			}
			T.Insert(T.Root,B);
		}
		if (buf[0]=='M'&&buf[4]=='G')
		{
			printf("%d\n",Min(BeforeMeMin,H.d[1]));
		}
		if (buf[4]=='S')
		{
			printf("%d\n",MinSortGap);
		}
	}
	return 0;
}
