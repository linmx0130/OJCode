#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
int C;
char Buf[205];
char Lx[25][205];
void Main()
{
	memset(Lx,0,sizeof(Lx));
	scanf("%s",Buf);
	int i,j,p;
	for (i=0,j=0,p=0;Buf[p]!='\0';++p)
	{
		Lx[i][j]=Buf[p];
		if (i&1)
		{
			if (--j==-1)
			{
				++i;j=0;
			}
		}else
		{
			if (++j==C)
			{
				++i;j=C-1;
			}
		}
	}
	for (int J=0;J<C;++J)
	{
		for (int I=0;I<i;++I)
		{
			putchar(Lx[I][J]);
		}
	}
	putchar('\n');
}
int main()
{
	while (scanf("%d",&C),C)
	{
		Main();
	}
}
