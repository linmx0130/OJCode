#include <cstdio>
#include <cstring>
#include <cstdlib>
int GetAbsurdity(int x)
{
	while (x>0 && x%10==0) x/=10; 
	int d=x%10;
	int a=0;
	while (x>0)
	{
		a++;
		x/=10;
	}
	if (d==5) return 2*a-1;
	else return 2*a;
}
void Main()
{
	int c;scanf("%d",&c);
	while (c%10==0) c/=10;

	int ac=GetAbsurdity(c);
	double l=0.95*c,r=1.05*c;

	int L=l,R=r;

	if (L<l) L++;if (R>r) R--;
	int c1;
	c1=c/10*10+5;
	if (c1>=L && c1<=R && GetAbsurdity(c1)<ac)
	{
		puts("absurd"); return ;
	}
	c1=c/10*10;
	if (c1>=L && c1<=R && GetAbsurdity(c1)<ac)
	{
		puts("absurd"); return ;
	}
	c1=(c/10+1)*10+5;
	if (c1>=L && c1<=R && GetAbsurdity(c1)<ac)
	{
		puts("absurd"); return ;
	}
	c1=(c/10+1)*10;
	if (c1>=L && c1<=R && GetAbsurdity(c1)<ac)
	{
		puts("absurd"); return ;
	}
	puts("not absurd");
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--) 
		Main();
	return 0;
}
