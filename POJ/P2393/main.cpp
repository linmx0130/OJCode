#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 10005
int N,S;
int C[MAXN],Y[MAXN];
int main()
{
    for (;~scanf("%d%d",&N,&S);)
    {
        for (int i=1;i<=N;++i)
        {
            scanf("%d%d",&C[i],&Y[i]);
        }
        int MinCost=0x70000000;
        long long Ans=0;
        for (int i=1;i<=N;++i)
        {
            MinCost+=S;
            if (MinCost>C[i])
            {
                MinCost=C[i];
            }
            Ans+=(long long)MinCost*Y[i];   
        }
        printf("%I64d\n",Ans);
    }
}
