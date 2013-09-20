#include <cstdio>
#include <cstring>
#include <cstdlib>
struct Matrix
{
	int d[2][2];
	void Clean()
		{
			memset(d,0,sizeof(d));
		}
	void Minus(Matrix b)
		{
			int dd[2][2];
			memset(dd,0,sizeof(dd));
			for (int i=0;i<2;++i)
			{
				for (int k=0;k<2;++k)
				{
					for (int j=0;j<2;++j)
					{
						dd[i][k]+=d[i][j]*b.d[j][k];
						dd[i][k]%=7;
					}
				}
			}
			for (int i=0;i<2;++i)
			{
				for (int j=0;j<2;++j)
				{
					d[i][j]=dd[i][j];
				}
			}
		}
};
int A,B,N;
Matrix PowM(Matrix m,int N)
{
	if (N==1) return m;
	Matrix t;
	t.Clean();
	t=PowM(m,N>>1);
	t.Minus(t);
	if (N&1) t.Minus(m);
	return t;
}
void Main()
{
	if (N<3)
	{
		puts("1");
		return ;
	}
	Matrix m;
	m.Clean();
	m.d[0][0]=A%7;
	m.d[0][1]=B%7;
	m.d[1][0]=1;
	m=PowM(m,N-2);
	int Ans=m.d[0][0]+m.d[0][1];
	Ans%=7;
	printf("%d\n",Ans);
//	printf("{ {%d %d}\n  {%d %d}}\n",m.d[0][0],m.d[0][1],m.d[1][0],m.d[1][1]);
}
int main()
{
	while (scanf("%d%d%d",&A,&B,&N),N)
	{
		Main();
	}
}
