#include <cstdio>
#include <cstring>
#include <cstdlib>

int tot[16004];
int s1,s2,s3;
int main()
{
	scanf("%d%d%d",&s1,&s2,&s3);
	for (int i=1;i<=s1;++i)
	{
		for (int j=1;j<=s2;++j)
		{
			for (int k=1;k<=s3;++k)
				tot[i+j+k]++;
		}
	}
	int max=0;
	for (int i=1;i<=16000;++i) if (tot[i]>max) max=tot[i];
	for (int i=1;i<=16000;++i) if (tot[i]==max)printf("%d\n",i),exit(0);
}
