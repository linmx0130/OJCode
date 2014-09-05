#include <cstdio>
#include <cstring>
#include <cstdlib>
void Main()
{
	int f[2];
	scanf("%d%d",&f[0],&f[1]);
	int big=0,small=1;
	if (f[0]<f[1])
	{
		big^=1;small^=1;
	}
	int Ans[2];
	Ans[0]=0;Ans[1]=0;
	while (f[small])
	{
		Ans[big]+=f[big]/f[small];
		f[big]=f[big]%f[small];
		small^=1;big^=1;
	}
	Ans[small]--;
	printf("%d %d\n",Ans[0],Ans[1]);
}
int main()
{
	int N;
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		printf("Scenario #%d:\n",i);
		Main();
		putchar('\n');
	}
	return 0;
}
