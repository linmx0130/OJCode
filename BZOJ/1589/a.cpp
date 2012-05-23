/*本程序根据标程改写，添加注释以供读者理解*/
#include <cstdio>
#include <cstring>
#define MAXN 200002
int n;
int a[MAXN],f[MAXN],d[MAXN],ans[MAXN],q[MAXN],v[MAXN];
int main(){
  scanf("%d",&n);
  for (int i=1;i<=n;++i){
		a[i]=1;
  }
  for (int i=1;i<=n;++i){
    scanf("%d",&f[i]);
    d[f[i]]++;
  }
  int l=0,r=0;
  for (int i=1;i<=n;++i){
    if (d[i]==0){
      q[r]=i;
      r++;
    }
  }
  //将入度为0的点入队
  while (l<r){
    int x=q[l];
    v[x]=1;
    d[f[x]]--;
    if (!d[f[x]]){
      q[r]=f[x];
      r++;
    }
    l++;
  }
  //拓扑排序
  for (int i=1;i<=n;++i){
    if (!v[i]){
      int x=i,st=i,sum=a[x];
      v[x]=1;
      while (f[x]!=st){
        x=f[x];
	v[x]=1;
	sum+=a[x];
      }
      x=i;
      ans[x]=sum;
      while (f[x]!=st){
        x=f[x];
	ans[x]=sum;
      }
    }
  }
  //缩强连通
  for (int i=r;i>=0;--i){
    ans[q[i]]=a[q[i]]+ans[f[q[i]]];
  }
  //根据拓扑排序的队列逆推倒，获取结果
  for (int i=1;i<=n;++i) printf("%d\n",ans[i]);
  return 0;
}
