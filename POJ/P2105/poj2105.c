#include <stdio.h>
int n,k,a,sum,j,b,i,col;
int main(){
  scanf("%d",&n);
  char s[32],*p;
  for (i=0;i!=n;++i){
    scanf("%s",s);
    p=s;
    k=8;
    col=4;
    while (col){
      a=(*p=='0')?0:1;
      k--;
      sum+=po(a,k);
      p++;
      if (k==0) {printf("%d",sum);
                 sum=0;k=8;col--;
		 if (col) printf(".");
      }
    }
    printf("\n");
  }
  return 0;
}
int po(int a,int n){
  int r=1;
  int i;
  if (!a) return 0;
  for (i=0;i!=n;++i) r*=2;
  return r;
}
