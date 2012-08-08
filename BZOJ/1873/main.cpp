#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>
#define MAXN 20002
#define MAXM 50005
using std::string;
using std::map;
const char liansha[][500]=
{
"","","",
"%s is on a killing spree!\0",
"%s is dominating!\0",
"%s has a mega kill!\0",
"%s is unstoppable!\0",
"%s is wicked sick!\0",
"%s has a monster kill!\0",
"%s is godlike!\0",
"%s is beyond godlike. someone kill him!\0"
};
char pos[][100]=
{
"","","",
"killing spree","dominating","mega kill","unstoppable","wicked sick","monster kill","godlike","beyond godlike"
};
struct Player
{
	string name;
	int Nkill,Tenkill,lasttime,type;
}d[MAXN];
map<string,int> f;
char buf[500],buf2[500];
int main()
{
	int n,m;
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{

		scanf("%s%d",buf,&d[i].type);
		d[i].name=buf;
		f[d[i].name]=i;
		d[i].lasttime=-10000;
	}
	bool Firstkill=0;int OWN=0;
	for (scanf("%d",&m);m;m--)
	{
		int Minute,Second,time;
		scanf("%d:%d %s is killed by %s",&Minute,&Second,buf,buf2);
		time=Minute*60+Second;
		int Killer=f[buf2],beKilled=f[buf];
		if (Killer==beKilled)
		{
			printf("%s has killed himself.\n",buf2);
		}else
		if (!Killer)
		{
			//wild
			printf("%s has been killed by %s.\n",buf,buf2);
		}else
		{
			//basic
			if (d[beKilled].Nkill>=3) printf("%s has just ended %s's %s.\n",buf2,buf,pos[d[beKilled].Nkill]);
			else printf("%s pawned %s's head.\n",buf2,buf);
			if (!Firstkill)
			{
				Firstkill=1;
				printf("%s just drew first blood.\n",buf2);
			}
			d[beKilled].Nkill=0;
			if (++d[Killer].Nkill>10) d[Killer].Nkill=10;
			if (time-d[Killer].lasttime<=10)
			{
				if (++d[Killer].Tenkill>3) d[Killer].Tenkill=3;
			}else d[Killer].Tenkill=1;
			d[Killer].lasttime=time;
			if (OWN>0)
			{
				if (d[Killer].type) OWN++;else OWN=-1;
			}
			else 
			{
				if (!d[Killer].type) OWN--;else OWN=1;
			}
			if (d[Killer].Nkill>=3) {printf(liansha[d[Killer].Nkill],buf2);puts("");}
			if (d[Killer].Tenkill==2) printf("%s just got a Double Kill!\n",buf2);
			if (d[Killer].Tenkill==3) printf("%s just got a Triple Kill!\n",buf2);
			if (OWN>=5) printf("The Scourge is OWNING!\n");
			if (OWN<=-5) printf("The Sentinel is OWNING!\n");
		}
	}
	return 0;
}

