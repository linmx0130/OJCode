#include <cstdio>
#include <cstring>
#include <cstdlib>
int N;
int main()
{
	scanf("%d",&N);
	int Count=1;
	for (int i=2;i<=10000;++i)
	{
		double t=(double)N/i;
		if (i&1)
		{
			if (((double)((int)t))==t)
			{
				if(t-i/2>0) Count++;
			}
		}
		else
		{
			if (((double)((int)t))==t-0.5)
			{
				if (t-i/2>0)Count++;
			}
		}
	}
	printf("%d\n",Count);
	return 0;
}
