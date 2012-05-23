#include <stdio.h>
int k,n,m;
int main(){
  double gold=0.6180339887,rg=1/gold;
  while (~scanf("%d%d",&n,&m)){
    if (n>m){
	  k=n;
	  n=m;
	  m=k;
	}
    k=n*gold;
	if (n!=(int)(k*rg)) ++k;
	printf("%d\n",m!=(int)(k*rg)+k);
  }
  return 0;
}
