#include <stdio.h>
int t;
int main(){
  long long p,e,i,d,n;
  for(;scanf("%lld%lld%lld%lld",&p,&e,&i,&d),~p;){
    n=(5544*p+14421*e+1288*i-d+21252)%21252;
	printf("Case %d: the next triple peak occurs in %lld days.\n",++t,n?n:21252);
  }
  return 0;
}
