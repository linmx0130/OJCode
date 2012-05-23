#include <cstdio>
int n;
inline int sum(int x){
       return ((1+x)*x)>>1;
}
int main(){
    scanf("%d",&n);
    int t=0,time=0;;
    while (n)
    {
        t++;
        if (sum(t)>n){
                      n-=sum(--t);
                      time+=t;
                      t=0;
                      }
    }
    printf("%d\n",time);
    while (1);
    return 0;
}
