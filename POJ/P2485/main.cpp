#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAXN 502
int N;
struct Edge
{
    int u,v,w;
} E[MAXN*MAXN];
bool cmp(Edge a,Edge b){return a.w<b.w;}
namespace Set
{
    int d[MAXN];
    void Init(int N)
    {
        for (int i=1;i<=N;++i)
        {
            d[i]=i;
        }
    }
    int Fa(int v)
    {
        return d[v]==v?v:d[v]=d[Fa(v)];
    }
    void Merge(int a,int b)
    {
        d[Fa(b)]=d[Fa(a)];
    }
};
void Main()
{
    scanf("%d",&N);
    Set::Init(N);
    int M=0;
    for (int i=1;i<=N;++i)
    {
        for (int j=1;j<=N;++j)
        {
            int t;
            scanf("%d",&t);
            if (j<i)
            {
                ++M;
                E[M].u=i;
                E[M].v=j;
                E[M].w=t;
            }
        }
    }
    std::sort(E+1,E+M+1,cmp);
    int Count=N-1;
    int Ans=0;
    for (int i=1;i<=M;++i)
    {
        if (Set::Fa(E[i].u)!=Set::Fa(E[i].v))
        {
            Set::Merge(E[i].u,E[i].v);
            Ans=E[i].w;
            if (--Count==0) break;
        }
    }
    printf("%d\n",Ans);
}
int main()
{
    int T;
    for (scanf("%d",&T);T;T--)
    {Main();}
   // while (1);
    return 0;
}
