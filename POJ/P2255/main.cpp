#include <cstdio>
#include <cstring>
#include <cstdlib>
char PreO[30],InO[30];
int N,now;
void Build(int L,int R)
{
	if (now==N)
	{
		return ;
	}
	for (int i=L;i<=R;++i)
	{
		if (InO[i]==PreO[now])
		{
			if (L<i) ++now,Build(L,i-1);
			if (i<R) ++now,Build(i+1,R);
			putchar(InO[i]);
			break;
		}
	}
}
void Main()
{
	N=strlen(PreO);
	now=0;
	Build(0,N-1);
	putchar('\n');
}
int main()
{
	while (scanf("%s%s",PreO,InO)==2)
	{
		Main();
	}
	return 0;
}
