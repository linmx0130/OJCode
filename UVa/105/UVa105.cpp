#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using std::max;
#define MAXL 10005

int Building[MAXL];
int main()
{
	//freopen("uva105.in","r",stdin);
	int L,R,H;
	int MaxR=0;
	for (;scanf("%d%d%d",&L,&H,&R)!=EOF;)
	{
		for (int i=L;i<R;++i)
		{
			Building[i]=max(Building[i],H);
		}
		MaxR=max(R,MaxR);
	}
	/*
	for (int i=1;i<=MaxR;++i)
	{
		printf("%d ",Building[i]);
	}
	*/
	//puts("");
	printf("1 ");
	for (int i=2;i<=MaxR;++i)
	{
		if (Building[i]!=Building[i-1])
		{
			printf("%d %d ",Building[i-1],i);
		}
	}
	puts("0");
	//while(1);
	return 0;
}
