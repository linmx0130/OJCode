#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using std::sort;
#define MAXN 105
int N,M;
struct ProblemNode
{
	int A,S;
};
ProblemNode P[MAXN][12];
char Buf[30];
struct Team
{
	int id,time,ptot;
}Scoreboard[MAXN],TmpSb[MAXN];
int Rank[MAXN],RankT[MAXN];
bool cmp(const Team & a, const Team & b)
{
	return (a.ptot!=b.ptot)? (a.ptot>b.ptot) : (a.time!=b.time?a.time<b.time:a.id<b.id);
}
void GetSB(Team *SB,int EP)
{
	for (int i=1;i<=N;++i)
	{
		SB[i].id=i;
		SB[i].time=SB[i].ptot=0;
		for (int j=1;j<=M;++j)
		{
			if (P[i][j].S>=0)
			{
				SB[i].time+=P[i][j].S;
				SB[i].time+=(P[i][j].A-1)*EP;
				SB[i].ptot++;
			}
		}
	}
	sort(SB+1,SB+N+1,cmp);
}
void GetRank(int *Rank,Team * SB)
{
	int Tot=0,LastTime=0,LastPtot=0;
	for (int i=1;i<=N;++i)
	{
		if (SB[i].time==LastTime && SB[i].ptot==LastPtot)
		{
			Rank[SB[i].id]=Tot;
		}
		else
		{
			Rank[SB[i].id]=++Tot;
			LastTime=SB[i].time;
			LastPtot=SB[i].ptot;
		}
	}
}
inline bool Check(int FA)
{
	GetSB(TmpSb,FA);
	GetRank(RankT,TmpSb);
	for (int i=1;i<=N;++i) if (Rank[i]!=RankT[i]) return 0;
	return 1;
}
void Main()
{
	for (int i=1;i<=N;++i)
	{
		for (int j=1;j<=M;++j)
		{
			P[i][j].A=0;
			scanf("%s",Buf);
			char *c=Buf;
			for (;(*c)!='/';c++)
			{
				P[i][j].A=P[i][j].A*10+(*c)-'0';
			}
			c++;
			if ((*c)=='-')
			{
				P[i][j].S=-1;
			}else
			{
				P[i][j].S=0;
				for (;*c;c++)
				{
					P[i][j].S=P[i][j].S*10+(*c)-'0';
				}
			}
		}
	}
	GetSB(Scoreboard,20);
	GetRank(Rank,Scoreboard);
	int L=1,R=20;
	while (L<R)
	{
		int mid=(L+R)>>1;
		if (Check(mid))
		{
			R=mid;
		}else
		{
			L=mid+1;
		}
	}
	printf("%d ",L);
	L=20,R=100005;
	while (L<R)
	{
		int mid=(L+R+1)>>1;
		if (Check(mid))
		{
			L=mid;
		}else
		{
			R=mid-1;
		}
	}
	if (R==100005) puts("*");
	else printf("%d\n",R);


}
int main()
{
	while (scanf("%d%d",&N,&M),N)
	{
		Main();
	}
	return 0;
}
