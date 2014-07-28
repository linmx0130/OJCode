#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 65
#define MAXP 100005+MAXN
int N;
int Q[MAXN][2];
int Matches[MAXP];
int Ans[MAXN],Anst;
bool Used[MAXP];
bool DFS(int now)
{
	for (int i=Q[now][0];i<=Q[now][1];++i)
	{
		if (!Used[i])
		{
			Used[i]=1;
			if (!Matches[i] || DFS(Matches[i]))
			{
				Matches[i]=now;
				return 1;
			}
		}
	}
	return 0;
}
void Main()
{
	memset(Matches,0,sizeof(Matches));
	memset(Used,0,sizeof(Used));
	Anst=0;
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		scanf("%d%d",&Q[i][0],&Q[i][1]);
	}
	Anst=0;
	for (int i=N;i>=1;--i)
	{
		memset(Used,0,sizeof(Used));
		if (DFS(i))
		{
			Ans[++Anst]=i;
		}
	}
	printf("%d\n",Anst);
	for (int i=Anst;i>1;--i) printf("%d ",Ans[i]);
	printf("%d\n",Ans[1]);
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--) Main();
	return 0;
}
