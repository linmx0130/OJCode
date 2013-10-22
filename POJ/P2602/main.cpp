#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 1000005
int N;
int A[MAXN],B[MAXN];
int main()
{
    while (~scanf("%d",&N))
    {
        //memset(B,0,sizeof(B));
        B[0]=0;
        for (int i=1;i<=N;++i)
        {
            char a,b;
            a=getchar();
            a=getchar();
            b=getchar();
            b=getchar(); 
            A[i]=a-'0';
            B[i]=b-'0'; 
        }
        for (int i=N;i>=1;--i)
        {
            B[i]+=A[i];
            if (B[i]>=10) {B[i-1]++;B[i]-=10;}
        }
        for (int i=!B[0];i<=N;++i)
        {
            putchar(B[i]+48);
        }
        putchar('\n');
    }
    return 0;
}
