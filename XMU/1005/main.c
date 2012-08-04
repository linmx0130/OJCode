#include <stdio.h>
int n;
int l[15],u[15];
void print(){
  int i;
  for (i=1;i<n;++i) printf("%d ",l[i]);
  printf("%d\n",l[n]);
}
void search(int x){
  int i;
  if (x==n+1) {print();return;}
  for (i=1;i<=n;++i) {
    if (!u[i]){
	  u[i]=1;
	  l[x]=i;
	  search(x+1);
	  u[i]=0;
	}
  }
}
int main(){
  scanf("%d",&n);
  search(1);
  return 0;
}
