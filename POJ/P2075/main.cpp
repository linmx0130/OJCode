#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using std::map;
using std::string;
using std::vector;
using std::sort;
float TotalCable;
int N,M;
char Buf[30];
string s;
map <string,int > ID;
struct Edge
{
	int u,v;float l;
};
bool cmp(const Edge & a, const Edge & b)
{
	return a.l<b.l;
}
vector <Edge> d;
vector <int> S;
int Fa(int t)
{
	return S[t]==t?t:S[t]=Fa(S[t]);
}
int main()
{
	scanf("%f",&TotalCable);
	scanf("%d",&N);
	S.push_back(0);
	for (int i=1;i<=N;++i)
	{
		scanf("%s",Buf);
		s=Buf;
		ID[s]=i;
		S.push_back(i);
	}
	scanf("%d",&M);
	for (int i=1;i<=M;++i)
	{
		scanf("%s",Buf);
		s=Buf;
		int a=ID[s];
		scanf("%s",Buf);
		s=Buf;
		int b=ID[s];
		float t;
		scanf("%f",&t);
		d.push_back((Edge){a,b,t});
	}
	sort(d.begin(),d.end(),cmp);
	int Count=0;float Len=0;
	for (int i=0;i!=d.size()&& Count+1<N;++i)
	{
		if (Fa(d[i].u)!=Fa(d[i].v))
		{
			Len+=d[i].l;
			S[Fa(d[i].u)]=Fa(d[i].v);
			Count++;
		}
	}
	if (Len<=TotalCable)
	{
		printf("Need %.1f miles of cable\n",Len);
	}else
	{
		puts("Not enough cable");
	}
	return 0;
}
