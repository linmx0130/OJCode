#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define MAXN 8005
#define LOWBIT(t) (t&(-t))
int N;
struct TArr
{
	int d[MAXN];
	void Add(int pos,int T)
	{
		for (int i=pos;i<=N;i+=LOWBIT(i)) 
		{
			d[i]+=T;
		}
	}
	int Sum(int pos)
	{
		int ret=0;
		for (int i=pos;i;i-=LOWBIT(i))
		{
			ret+=d[i];
		}
		return ret;
	}
}T;
int A[MAXN],B[MAXN];
int main()
{
	scanf("%d",&N);
	for (int i=2;i<=N;++i)
	{
		scanf("%d",&A[i]);
		A[i]++;
	}
	for (int i=1;i<=N;++i)
	{
		T.Add(i,1);
	}
	for (int i=N;i>1;--i)
	{
		int L=1,R=N;
		while (L<R)
		{
			int mid=((L+R)>>1);
			if (T.Sum(mid)>=A[i])
			{
				R=mid;
			}else
			{
				L=mid+1;
			}
		}
		B[i]=L;
		T.Add(L,-1);
	}
	for (int i=1;i<=N;++i)
	{
		if (T.Sum(i))
		{
			B[1]=i;
			break;
		}
	}
	for (int i=1;i<=N;++i)
	{
		printf("%d\n",B[i]);
	}
	return 0;
}

