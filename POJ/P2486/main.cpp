#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using std::min;
using std::max;
#define MAXN 155
#define MAXK 255
int N,K;
struct eList
{
    int tot,V[MAXN*2],Pre[MAXN*2],Head[MAXN];
    void AddEdge(int a,int b)
    {
        ++tot;
        Pre[tot]=Head[a];
        Head[a]=tot;
        V[tot]=b;
    }
    void AddEdge2(int a,int b)
    {
        AddEdge(a,b);
        AddEdge(b,a);
    }
    void Init()
    {
        memset(V,0,sizeof(V));
        memset(Pre,0,sizeof(Pre));
        memset(Head,0,sizeof(Head));
        tot=0;
    }
}g;
int W[MAXN];
int Size[MAXN];
bool Mark[MAXN];
int F[MAXN][MAXK][2];
void GetSize(int now)
{
    Size[now]=1;
    Mark[now]=1;
    for (int p=g.Head[now];p;p=g.Pre[p])
    {
        if (!Mark[g.V[p]])
        {
            GetSize(g.V[p]);
            Size[now]+=Size[g.V[p]];
        }
    }
}
bool Doing[MAXN];
int Tmp[MAXK][2];
void Dp(int now)
{
    if (Mark[now]) return ;
    Mark[now]=1;
    Doing[now]=1;
    F[now][0][0]=W[now];
    F[now][0][1]=W[now];
    if (Size[now]==1) {Doing[now]=0; return ;};
    for (int p=g.Head[now];p;p=g.Pre[p])
    {
        if (!Mark[g.V[p]]) Dp(g.V[p]);
    }
    for (int p=g.Head[now];p;p=g.Pre[p])
    {
        if (Doing[g.V[p]]) continue;
        for (int j=0;j<=K;++j)
        {
            Tmp[j][0]=F[now][j][0];
            Tmp[j][1]=F[now][j][1];
        }
        for (int k=K;k>=1;--k)
        {      
            
            for (int j=0;j<k;++j)
            {
                if (k-j-2>=0) if (F[now][k][0]<Tmp[k-j-2][0]+F[g.V[p]][j][0])
                {
                    F[now][k][0]=Tmp[k-j-2][0]+F[g.V[p]][j][0];
                }
                if (k-j-2>=0) if (F[now][k][1]<Tmp[k-j-2][1]+F[g.V[p]][j][0])
                {
                    F[now][k][1]=Tmp[k-j-2][1]+F[g.V[p]][j][0];
                }
                if (k-j-1>=0) if (F[now][k][1]<Tmp[k-j-1][0]+F[g.V[p]][j][1])
                {
                    F[now][k][1]=Tmp[k-j-1][0]+F[g.V[p]][j][1];
                }
            }
        }

        //F[now][k][0]+=W[now];F[now][k][1]+=W[now];
    }
    Doing[now]=0;
}
int main()
{
    //freopen("2486.in","r",stdin);
    //freopen("2486.out","w",stdout);
    while (scanf("%d%d",&N,&K)!=EOF)
    {
        g.Init();
        memset(Size,0,sizeof(Size));
        memset(W,0,sizeof(W));
        memset(Mark,0,sizeof(Mark));
        memset(F,0,sizeof(F));
        for (int i=1;i<=N;++i)
        {
            scanf("%d",&W[i]);
        }
        for (int i=1;i<=N-1;++i)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            g.AddEdge2(u,v);
        }
        GetSize(1);
        memset(Mark,0,sizeof(Mark));
        Dp(1);
        int Ans=0;
        for (int i=0;i<=K;++i)
        {
            if (Ans<F[1][i][1]) Ans=F[1][i][1];
            if (Ans<F[1][i][0]) Ans=F[1][i][0];
        }
        printf("%d\n",Ans);
    }
}
