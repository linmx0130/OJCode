#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
using std::map;
using std::string;
map<string,int> Belong;
string Party[25];
int CountP[25];
int N,M,Ptot;
char Buf[100];
int main()
{
	scanf("%d\n",&N);
	for (int i=1;i<=N;++i)
	{
		gets(Buf);
		if (Buf[strlen(Buf)-1]=='\n') Buf[strlen(Buf)-1]=0;
		string n1=Buf;
		gets(Buf);
		if (Buf[strlen(Buf)-1]=='\n') Buf[strlen(Buf)-1]=0;
		string n2=Buf;
		if (n2=="independent")
		{
			Party[++Ptot]=n2;
			Belong[n1]=Ptot;
		}
		else
		{
			bool flag=0;
			for (int i=1;i<=Ptot;++i)
			{
				if (Party[i]==n2)
				{
					Belong[n1]=i;
					flag=1;
					break;
				}
			}
			if (!flag) 
			{
				Party[++Ptot]=n2;
				Belong[n1]=Ptot;
			}
		}
	}
	scanf("%d\n",&M);
	for (int i=1;i<=M;++i)
	{
		gets(Buf);
		if (Buf[strlen(Buf)-1]=='\n') Buf[strlen(Buf)-1]=0;
		string t=Buf;
		CountP[Belong[t]]++;
	}
	int Max=0,MaxT;
	for (int i=1;i<=Ptot;++i)
	{
		if (CountP[i]>Max)
		{
			Max=CountP[i];
			MaxT=i;
		}
	}
	int countMax=0;
	for (int i=1;i<=Ptot;++i)
	{
		if (CountP[i]==Max)
		{
			countMax++;
		}
	}
	if (countMax>1) puts("tie");
	else puts(Party[MaxT].c_str());
	return 0;
}
