#include <stdio.h>
#define MAXN 100002
#define MAX(a,b) (((a)>(b))?(a):(b))
int a[MAXN],b[MAXN];
int n,m;
int check(int m){
    int ans=1,i;
    for (i=1;i<=n;++i){
	b[i]=b[i-1]+a[i];
	if (b[i]>m) {
	    b[i]=a[i];
	    ans++;
	}
    }
    return ans;
}
int main(){
  freopen("task.in","r",stdin);
  scanf("%d %d",&n,&m);
  int l=0,r=0;
  int i;
  for (i=1;i<=n;++i){
    scanf("%d",&a[i]);
    r+=a[i];
    l=MAX(l,a[i]);
  }
  int mid;
  while (l<r){
    mid=(l+r)/2;
    if (check(mid)<=m) r=mid;
    else l=mid+1;
  }
  printf("%d\n",l);
  while(1);
  return 0;
}
