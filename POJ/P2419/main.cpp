#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#define MAXN 105
struct BitSet
{
	int d[5];
	inline void Mark(int T)
	{
		int pos=T/20;
		T%=20;
		d[pos]|=1<<T;
	}
}D[MAXN];
inline bool Same(const BitSet &a ,const BitSet & b)
{
	for (int i=0;i<5;++i)
	{
		if (a.d[i]!=b.d[i]) return false;
	}
	return true;
}
int P,T;
bool Ign[MAXN];
int main()
{
	scanf("%d%d",&P,&T);
	int a,b;
	while (scanf("%d%d",&a,&b)!=EOF)
	{
		D[a].Mark(b);
	}
	int Ans=P;
	for (int i=1;i<=P;++i)
	{
		if (Ign[i]) continue;
		for (int j=i+1;j<=P;++j)
		{
			if (Same(D[i],D[j]))
			{
				Ign[j]=1;
				Ans--;
			}
		}
	}
	printf("%d\n",Ans);
	return 0;
}
