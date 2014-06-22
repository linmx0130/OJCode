#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#define MAXN 50002
using std::string;
using std::sort;
int N;
struct Node
{
	string Label;
	int Priority;
}d[MAXN];
char Buf[MAXN];
bool cmp(const Node & a, const Node & b)
{
	return a.Label<b.Label;
}
void Input()
{
	for (int i=1;i<=N;++i)
	{
		scanf("%s",Buf);
		char *c;
		d[i].Label="";
		for (c=Buf;(*c)!='/';c++) d[i].Label+=*c;
		c++;
		d[i].Priority=0;
		for (;(*c)!='\0';c++) d[i].Priority=d[i].Priority*10+(*c)-'0';
	}
}
int RMQ[17][MAXN];
int RMQ_Point[17][MAXN];
int Pow2[17];
void RMQ_Init()
{
	Pow2[0]=1;
	for (int i=1;i<17;++i) Pow2[i]=Pow2[i-1]<<1;
	for (int i=1;i<=N;++i)
	{
		RMQ[0][i]=d[i].Priority;
		RMQ_Point[0][i]=i;
	}
	for (int k=1;Pow2[k]<=N;++k)
	{
		for (int i=1;i+Pow2[k]-1<=N;++i)
		{
			if (RMQ[k-1][i]>RMQ[k-1][i+Pow2[k-1]])
			{
				RMQ[k][i]=RMQ[k-1][i];
				RMQ_Point[k][i]=RMQ_Point[k-1][i];
			}else
			{
				RMQ[k][i]=RMQ[k-1][i+Pow2[k-1]];
				RMQ_Point[k][i]=RMQ_Point[k-1][i+Pow2[k-1]];
			}
		}
	}
}
int Query(int l,int r)
{
	int L=r-l+1;
	if (L==1) return l;
	int k=0;
	for (;Pow2[k+1]<L;++k);
	if (RMQ[k][l]>RMQ[k][r-Pow2[k]+1])
	{
		return RMQ_Point[k][l];
	}else
	{
		return RMQ_Point[k][r-Pow2[k]+1];
	}
}
void BuildTree(int L,int R)
{
	int t=Query(L,R);
	printf("(");
	if (L<t) BuildTree(L,t-1);
	printf("%s/%d",d[t].Label.c_str(),d[t].Priority);
	if (t<R) BuildTree(t+1,R);
	printf(")");
}
void Main()
{
	Input();
	sort(d+1,d+N+1,cmp);
	RMQ_Init();
	BuildTree(1,N);
	puts("");
}
int main()
{
	while (scanf("%d",&N),N!=0)
	{
		Main();
	}
	return 0;
}
