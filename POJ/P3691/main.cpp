#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define MAXN 1005
struct Node
{
	int ch[4],c,fail;
	bool flag;
}T[MAXN];
int N;
int GetNum(char c)
{
	if (c=='A') return 0;
	if (c=='T') return 1;
	if (c=='G') return 2;
	if (c=='C') return 3;
}
void InitNode(int t,int v)
{
	T[t].ch[0]=T[t].ch[1]=T[t].ch[2]=T[t].ch[3]=0;
	T[t].c=v;
	T[t].flag=0;
}
char Buf[25];
char S[1005];
int D[1005],Root,Ttot;
void Insert(char *s,int now)
{
	for (char *c=s;*c;c++)
	{
		int d=GetNum(*c);
		if (!T[now].ch[d])
		{
			T[now].ch[d]=++Ttot;
			InitNode(Ttot,d);
		}
		now=T[now].ch[d];
	}
	T[now].flag=1;
}
void BuildAC()
{
	std::queue<int> Q;
	Q.push(Root);T[Root].fail=Root;
	while (!Q.empty())
	{
		int now=Q.front();
		Q.pop();
		for (int k=0;k<4;++k)
		{
			if (T[now].ch[k])
			{
				if (now==Root) T[T[now].ch[k]].fail=Root;
				else
				{
					int s=T[now].ch[k];
					int p=T[now].fail;
					T[s].fail=T[p].ch[k];
					if (T[T[s].fail].flag) T[s].flag=1;
				}
				Q.push(T[now].ch[k]);
			}else
			{
				if (now==Root) T[now].ch[k]=Root;
				else T[now].ch[k]=T[T[now].fail].ch[k];
			}
		}
	}
}
int F[1005][1005];
int Q[1005*1005][2];
bool inQ[1005][1005];
void Main()
{
	Root=Ttot=1;
	InitNode(1,-1);
	for (int i=1;i<=N;++i)
	{
		scanf("%s",Buf);
		Insert(Buf,Root);
	}
	BuildAC();
	memset(F,60,sizeof(F));
	scanf("%s",S+1);
	int L=strlen(S+1);
	for (int i=1;i<=L;++i)
	{
		D[i]=GetNum(S[i]);
	}
	F[0][1]=0;
	int Qh=0,Qt=1;Q[1][0]=0;Q[1][1]=1;
	inQ[0][1]=1;
	int Ans=F[1][1];
	while (Qh!=Qt)
	{
		++Qh;int i=Q[Qh][0],j=Q[Qh][1];
		for (int k=0;k<4;++k)
		{
			int nj=T[j].ch[k],w=(D[i+1]==k)?0:1;
			if (!nj) nj=Root;
			if (T[nj].flag) continue;
			if (F[i+1][nj]>F[i][j]+w)
			{
				F[i+1][nj]=F[i][j]+w;
				if (i+1==L)
				{
					if (Ans>F[i+1][nj]) Ans=F[i+1][nj];
					continue;
				}
				if (!inQ[i+1][nj])
				{
					inQ[i+1][nj]=1;
					++Qt;Q[Qt][0]=i+1;Q[Qt][1]=nj;
				}
			}
		}
		inQ[i][j]=0;
	}
	if (Ans==1010580540) puts("-1");
	else printf("%d\n",Ans);
}
int main()
{
	for (int i=1;i;++i) {
		scanf("%d",&N);if (!N) break;
		printf("Case %d: ",i);	
		Main();
	}
	return 0;
}
