#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using std::sort;
#define MAXW 2000005
#define LOWBIT(t) (t&(-t))
struct TreeArr
{
	int D[MAXW];
	int N;
	void Add(int p,int v)
	{
	//	fprintf(stderr,":TreeArr::Add(%d,%d) Start\n",p,v);
		for (int i=p;i<=N;i+=LOWBIT(i))
		{
			D[i]+=v;
		}
	//	fprintf(stderr,":TreeArr::Add(%d,%d) End\n",p,v);
	}
	int Sum(int p)
	{
	//	fprintf(stderr,":TreeArr::Sum(%d) Start\n",p);
		int ret=0;
		for (int i=p;i;i-=LOWBIT(i))
		{
			ret+=D[i];
		}
	//	fprintf(stderr,":TreeArr::Sum(%d) Return with %d\n",p,ret);
		return ret;
	}
	void Clean()
	{
		memset(D,0,sizeof(D));
	}
}T;
int W,M;
struct Operate_Str
{
	int Type;
	int d[4];
}OpList[200005],TmpList[200005];
int QueryTotal;
int QueryAns[10005];
bool cmp(Operate_Str A,Operate_Str B)
{
	if (A.d[0]!=B.d[0])
	{
		return A.d[0]<B.d[0];
	}else
	{
		return A.Type<B.Type;
	}
}
void OrzCdq(int L,int R)
{
//	fprintf(stderr,":OrzCdq(%d,%d) Start\n",L,R);
	if (L==R) {//fprintf(stderr,":OrzCdq(%d,%d) End\n",L,R);
	return ;}
	int Mid=(L+R)/2;
	OrzCdq(L,Mid);OrzCdq(Mid+1,R);
	int TmpTotal=0;
	for (int i=L;i<=Mid;++i)
	{
		if (OpList[i].Type==1)
		{
			TmpList[++TmpTotal]=OpList[i];
		}
	}	
	for (int i=Mid+1;i<=R;++i)
	{
		if (OpList[i].Type!=1)
		{
			TmpList[++TmpTotal]=OpList[i];
		}
	}
	
	sort(TmpList+1,TmpList+TmpTotal+1,cmp);
//	fprintf(stderr,":OrzCdq(%d,%d) Prepared1!\n",L,R);
	for (int i=1;i<=TmpTotal;++i)
	{
		if (TmpList[i].Type==1)
		{
			T.Add(TmpList[i].d[1],TmpList[i].d[2]);
		}
		if (TmpList[i].Type==2)
		{
			QueryAns[TmpList[i].d[2]]+=T.Sum(TmpList[i].d[1]);
		}
		if (TmpList[i].Type==3)
		{
			QueryAns[TmpList[i].d[2]]-=T.Sum(TmpList[i].d[1]);
		}
	}
//	fprintf(stderr,":OrzCdq(%d,%d) Prepared2!\n",L,R);
	for (int i=1;i<=TmpTotal;++i)
	{
		if (TmpList[i].Type==1)
		{
			T.Add(TmpList[i].d[1],-TmpList[i].d[2]);
		}
	}
//	fprintf(stderr,":OrzCdq(%d,%d) Prepared3!\n",L,R);
//	fprintf(stderr,":OrzCdq(%d,%d) End\n",L,R);
}
int main()
{
//	freopen("mokia.in","r",stdin);
//	freopen("mokia.out","w",stdout);
	scanf("%d",&W);scanf("%d",&W);
	T.N=W;
	int Tmp;
	for (;~scanf("%d",&Tmp);)
	{
		if (Tmp==3) break;
		if (Tmp==1)
		{
			++M;
			OpList[M].Type=1;
			scanf("%d%d%d",&OpList[M].d[0],&OpList[M].d[1],&OpList[M].d[2]);
		}
		if (Tmp==2)
		{
			int x0,y0,x1,y1;
			scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
			++QueryTotal;
			++M;
			OpList[M].Type=2;
			OpList[M].d[0]=x1;
			OpList[M].d[1]=y1;
			OpList[M].d[2]=QueryTotal;
			++M;
			OpList[M].Type=2;
			OpList[M].d[0]=x0-1;
			OpList[M].d[1]=y0-1;
			OpList[M].d[2]=QueryTotal;
			++M;
			OpList[M].Type=3;
			OpList[M].d[0]=x0-1;
			OpList[M].d[1]=y1;
			OpList[M].d[2]=QueryTotal;
			++M;
			OpList[M].Type=3;
			OpList[M].d[0]=x1;
			OpList[M].d[1]=y0-1;
			OpList[M].d[2]=QueryTotal;
		}
	}
	OrzCdq(1,M);
	for (int i=1;i<=QueryTotal;++i)
	{
		printf("%d\n",QueryAns[i]);
	}
	return 0;
}
