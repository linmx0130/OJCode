#include <cstdio>
#include <cstring>
#include <cstdlib>
bool List[200];
void Work()
{
	int t,Ans=0;
	memset(List,0,sizeof(List));
	do
	{
		scanf("%d",&t);
		if (t==-1) exit(0) ;
		if (t==0) break;
		List[t]=1;
		if (!(t&1))
		{
			if (List[t>>1]) Ans++;
		}
		if (List[t<<1]) Ans++;
	}while (t!=0);
	printf("%d\n",Ans);
}
int main()
{
	while (1) Work();
};
