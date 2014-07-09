#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using std::min;
using std::max;
#define MAXN 50005
int F[2][17][MAXN];
int Pow2[17];
int N,Ans;
void RMQ_Init()
{
	Pow2[0]=1;
	for (int i=1;Pow2[i-1]<=N;++i)
	{
		Pow2[i]=Pow2[i-1]<<1;
	}
	for (int i=1;Pow2[i]<=N;++i)
	{
		for (int j=1;j+Pow2[i]-1<=N;++j)
		{
			F[0][i][j]=min(F[0][i-1][j],F[0][i-1][j+Pow2[i-1]]);
			F[1][i][j]=max(F[1][i-1][j],F[1][i-1][j+Pow2[i-1]]);
		}
	}
}
inline int RMQ_Query(int q,int L,int R)
{
	int d=R-L+1,logd;
	for (logd=-1;Pow2[logd+1]<=d;++logd);
	if (q) return max(F[q][logd][L],F[q][logd][R-Pow2[logd]+1]);
	else return min(F[q][logd][L],F[q][logd][R-Pow2[logd]+1]);
}
int getR(int s)
{
	int L=s,R=N;
	while (L<R)
	{
		int mid=(L+R+1)>>1;
		if (RMQ_Query(0,s,mid)==F[0][0][s])
		{
			L=mid;
		}else
		{
			R=mid-1;
		}
	}
	return L;
}
void Main()
{
	for (int i=1;i<=N;++i)
	{
		scanf("%d",&F[0][0][i]);
		F[1][0][i]=F[0][0][i];
	}
	RMQ_Init();
	Ans=-1;
	for (int l=1;l<=N;++l)
	{
		int r=getR(l);
		if (l==r) continue;
		
		int max=RMQ_Query(1,l,r);
		int L=l,R=r;
		while (L<R)
		{
			int mid=(L+R)>>1;
			if (max==RMQ_Query(1,l,mid))
			{
				R=mid;
			}else
			{
				L=mid+1;
			}
		}
		if (R-l>Ans) Ans=R-l;
	}
	printf("%d\n",Ans);
}
int main()
{
	while (scanf("%d",&N)!=EOF)
	{
		Main();
	}
	return 0;
}
