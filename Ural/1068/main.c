#include <stdio.h>
int n,t;
int main(){
  scanf("%d",&n);
  t=(n>0)?(n):(2-n);
  printf("%d\n",(1+n)*t/2);
  return 0;
}
