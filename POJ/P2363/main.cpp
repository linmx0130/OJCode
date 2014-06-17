#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using std::min;
void Main()
{
	int N,t;
	int Ans=0x7fffffff;
	scanf("%d",&N);
	if (N==0) 
	{
		puts("6");
		return ;
		// f**k
	}
	for (int a=1;a<=N/2+1;++a)
	{
		if (N%a==0)
		{
			t=N/a;
			for (int b=a;b<=t/2+1;++b)
			{
				if (t%b==0)
				{
					int c=t/b;
					Ans=min(Ans,a*b+b*c+c*a);
				}
			}
		}
	}
	printf("%d\n",Ans*2);
}
int main()
{
	int C;
	for (scanf("%d",&C);C;C--)
	{
		Main();
	}
	return 0;
}
