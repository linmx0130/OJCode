#include <cstdio>
#define MAXN 100002
int tot;
int n,m;
int d[MAXN];
int main(){
    freopen("task.in","r",stdin);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i){
        scanf("%d",d+i);
        tot+=d[i];
    }
    int l=0,r=tot,mid=0;
    while (l<r){
          mid=(l+r)/2;
          int now=0,ren=1;
          for (int i=1;i<=n;++i){
              if (now+d[i]>mid)
              {
                  ren++;
                  now=d[i];
              }
              else{
                   now+=d[i];
                   }
              if (ren>m){
                         break;
                         }
          }
          if (ren<=m) r=mid;
          else l=mid+1;
    }
    printf("%d\n",l);
    while(1);
    return 0;
}
