#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#define MAXS 300
#define MOD 20090717
#define CSET 26
struct Node
{
	int ch[CSET],fail;
	int c,status;
}T[MAXS];
int N,M,K,Root,Ttot;
char Buf[20];
void InitNode(int t,int v)
{
	memset(T[t].ch,0,sizeof(T[t].ch));
	T[t].fail=T[t].status=0;
	T[t].c=v;
}
void Insert(char *s,int id)
{
	int now=Root;
	for (char *c=s;*c;c++)
	{
		int d=(*c)-'a';
		if (!T[now].ch[d])
		{
			T[now].ch[d]=++Ttot;
			InitNode(Ttot,d);
		}
		now=T[now].ch[d];
	}
	T[now].status=1<<id;
}
void BuildAC()
{
	std::queue<int> Q;
	Q.push(Root);
	T[Root].fail=Root;
	while (!Q.empty())
	{
		int now=Q.front();Q.pop();
		for (int k=0;k<CSET;++k)
		{
			if (T[now].ch[k])
			{
				if (now==Root) T[T[now].ch[k]].fail=Root;
				else
				{
					int s=T[now].ch[k];
					int p=T[now].fail;
					T[s].fail=T[p].ch[k];
					T[s].status|=T[T[s].fail].status;
				}
				Q.push(T[now].ch[k]);
			}else
			{
				if (now==Root) T[now].ch[k]=T[now].fail;
				else
				{
					T[now].ch[k]=T[T[now].fail].ch[k];
				}
			}
		}
	}
}
#define LOWBIT(t) (t&(-t))
int Num1(int t)
{
	int ret=0;
	while (t)
	{
		t-=LOWBIT(t);
		ret++;
	}
	return ret;
}
int F[2][MAXS][1<<10];
bool inQ[2][MAXS][1<<10];
#define QSIZE 400000
int Q[QSIZE][3];
bool LenTouch[30];
void Main()
{
	memset(F,0,sizeof(F));
	memset(LenTouch,0,sizeof(LenTouch));
	Root=Ttot=1;InitNode(1,-1);
	for (int i=1;i<=M;++i)
	{
		scanf("%s",Buf);
		Insert(Buf,i-1);
	}
	BuildAC();
	F[0][1][0]=1;
	Q[1][0]=0;Q[1][1]=1;Q[1][2]=0;
	inQ[0][1][0]=1;
	int Qh=0,Qt=1;
	LenTouch[0]=1;
	while (Qh!=Qt)
	{
		++Qh;if (Qh==QSIZE) Qh=0;
		int i=Q[Qh][0],j=Q[Qh][1],k=Q[Qh][2];
		for (int c=0;c<CSET;++c)
		{
			int ni=i+1;
			if (!LenTouch[ni])
			{
				memset(F[ni&1],0,sizeof(F[ni&1]));
				memset(inQ[ni&1],0,sizeof(inQ[ni&1]));
				LenTouch[ni]=1;
			}
			int nj=T[j].ch[c];
			int nk=k|T[nj].status;
			F[ni&1][nj][nk]+=F[i&1][j][k];
			if (F[ni&1][nj][nk]>=MOD) F[ni&1][nj][nk]-=MOD;
			if (ni!=N)
			{
				if (!inQ[ni&1][nj][nk])
				{
					++Qt;if (Qt==QSIZE) Qt=0;
					Q[Qt][0]=ni;Q[Qt][1]=nj;Q[Qt][2]=nk;
					inQ[ni&1][nj][nk]=1;
				}
			}
		}
		inQ[i&1][j][k]=0;
	}
	{
	}
	int ends=(1<<M)-1;
	int Ans=0;
	for (int i=1;i<=Ttot;++i)
	{
		for (int j=0;j<=ends;++j)
		{
			if (Num1(j)>=K)
			{
				Ans+=F[N&1][i][j];
				if (Ans>=MOD) Ans-=MOD;
			}
		}
	}
	printf("%d\n",Ans);
}
int main()
{
	while (scanf("%d%d%d",&N,&M,&K),N) Main();
	return 0;
}
