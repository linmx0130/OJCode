#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
int d[10];
void Main()
{
	scanf("%d",&d[0]);
	printf("%d ",d[0]);
	for (int i=0;i<10;++i) scanf("%d",&d[i]);
	std::sort(d,d+10);
	printf("%d\n",d[7]);
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;++i)
	{
		Main();
	}
	return 0;
}
