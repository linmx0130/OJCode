#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
char Buf[10];
int Cd[20],Rd[20];
string Rec[20];
void Main()
{
	map<string,int> PN;
	int Ptot=0;
	memset(Cd,0,sizeof(Cd));
	memset(Rd,0,sizeof(Rd));
	for (int i=1;i<=16;++i)
	{
		int u,v;
		scanf("%s",Buf);
		if (!PN[Buf]) {PN[Buf]=++Ptot;Rec[Ptot]=Buf;}
		u=PN[Buf];
		scanf("%s",Buf);
		if (!PN[Buf]) {PN[Buf]=++Ptot;Rec[Ptot]=Buf;}
		v=PN[Buf];
		int a,b;scanf("%d%d",&a,&b);
		if (a>b) {Cd[u]++;Rd[v]++;}
		else {Cd[v]++;Rd[u]++;}
	}
	for (int i=1;i<=Ptot;++i)
	{
		if (!Rd[i])
		{
			puts(Rec[i].c_str());
			return ;
		}
	}
}
int main()
{
	int N;
	scanf("%d",&N);
	for (;N;N--)
	{
		Main();
	}
	return 0;
}
