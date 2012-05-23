#include <stdio.h>
float sum,a;
int main(){
  register i;
  sum=0;
  for (i=0;i!=12;++i){
    scanf("%f",&a);
    sum=sum+a/12;
  }
  printf("$%.2f\n",sum);
}
