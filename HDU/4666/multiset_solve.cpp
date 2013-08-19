#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#define MAXN 60005
#define MAXK 5
using std::multiset;
multiset <int> Sum[33];
int N,K;
int P[MAXN][MAXK];
int main()
{
	while (~scanf("%d%d",&N,&K))
	{
		for (int i=0;i<(1<<K);++i)
		{
			Sum[i].clear();
		}
		memset(P,0,sizeof(P));
		for (int i=0;i<N;++i)
		{
			int Od;
			scanf("%d",&Od);
			if (Od==0)
			{
				for (int j=0;j<K;++j)
				{
					scanf("%d",&P[i][j]);
				}
				for (int Sta=0;Sta<(1<<K);++Sta)
				{
					int Tmp=0;
					for (int j=0;j<K;++j)
					{
						if (Sta&(1<<j))
						{
							Tmp-=P[i][j];
						}else Tmp+=P[i][j];
					}
					Sum[Sta].insert(Tmp);
				}
			}else{
				int p;scanf("%d",&p);p--;
				for (int Sta=0;Sta<(1<<K);++Sta)
				{
					int Tmp=0;
					for (int j=0;j<K;++j)
					{
						if (Sta&(1<<j))
						{
							Tmp-=P[p][j];
						}else Tmp+=P[p][j];
					}
					multiset<int>::iterator t=Sum[Sta].find(Tmp);
					Sum[Sta].erase(t);
				}
			}
			int Ans=0;
			for (int Sta=0;Sta<=(1<<(K-1));++Sta)
			{
				if (Sum[Sta].size()<2) continue;
				multiset<int>::iterator t1,t2;
				t1=Sum[Sta].end();t1--;
				t2=Sum[Sta].begin();
				if ((*t1)-(*t2)>Ans) Ans=(*t1)-(*t2);
			}
			printf("%d\n",Ans);
		}
	}
	return 0;
}
