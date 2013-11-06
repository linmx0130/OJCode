#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
#define MAXN 1000000
map<int ,int > Ans;
//int Queue[MAXN+3];
//int RMQ[23][MAXN+3];
//int Pow[23];
//int Log[MAXN+3];
int Dfs(int now)
{
	//cerr << now << endl;
	//system("pause");
	int &t1=Ans[now];
	if (t1) return t1;
	if (now%2==1)
	{
		//return (now<=MAXN)? RMQ[0][now]=Ans[now]=Dfs(now*3+1)+1:Ans[now]=Dfs(now*3+1)+1;
		return t1=Dfs(now*3+1)+1;
	}
	else 
	{
		/*return (now<=MAXN)? RMQ[0][now]=Ans[now]=Dfs(now>>1)+1:Ans[now]=Dfs(now>>1)+1;*/
		return t1=Dfs(now>>1)+1;
	}
}
void Init()
{
	Ans[1]=1;
	//Dfs(113383);
	//cerr << "success!" << endl;
	//while(1);
	/*
	for (int i=1;i<=MAXN;++i)
	{
		if (!Ans[i]) {
			//cerr << i << endl;
			Dfs(i);
		}
		//fprintf(stderr,"I am here!%d\n",i);
	}
	*/
	//fprintf(stderr,"He is here!\n");
	/*
	for (int i=0;i<=21;++i)
	{
		Pow[i]=1<<i;
	}
	
	int Eax=1;
	for (int i=2;i<=MAXN;++i)
	{
		if (i==Pow[Eax])
		{
			Log[i]=Eax;
			Eax++;
		}
		else Log[i]=Eax;
	}
	for (int i=1;i<=MAXN;++i)
	{
		RMQ[0][i]=Ans[i];
	}
	for (int i=1;i<=21;++i)
	{
		int Lim=MAXN-Pow[i]+1;
		for (int j=1;j<=Lim;++j)
		{
			RMQ[i][j]=max(RMQ[i-1][j],RMQ[i-1][j+Pow[i-1]]);
		}
	}
	*/
}
void Solve(int a,int b)
{
	int L,R;
	L=a;R=b;
	if (L>R)
	{
		int k=L;
		L=R;
		R=k;
	}
	if (L==R) 
	{
		printf("%d %d %d\n",a,b,Dfs(L));
		return ;
	}
	/*
	int Len=R-L+1;
	int LogLen=Log[Len];
	int ans=max(RMQ[LogLen-1][L],RMQ[LogLen-1][R-Pow[LogLen-1]+1]);
	printf("%d %d %d\n",a,b,ans);
	*/
	int Out=0;
	for (int i=L;i<=R;++i)
	{
		if (Dfs(i)>Out) Out=Ans[i];
	}
	printf("%d %d %d\n",a,b,Out);
}
int main()
{
	//freopen("uva100.in","r",stdin);
	//freopen("myout.out","w",stdout);
	Init();
	//printf("He is here!\n");
	int a,b;
	while (scanf("%d%d",&a,&b)!=EOF)
	{
		Solve(a, b);
	}
	return 0;
}
