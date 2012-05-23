#include <cstdio>
int n,T,w1[35],w2[35],t1[35],t2[35];
int f[1080002];
inline int max(int a,int b){
	return a>b?a:b;
}
inline int min(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d %d",&n,&T);
	for (int i=1;i<=n;++i){
		scanf("%d %d %d %d",&w1[i],&t1[i],&w2[i],&t2[i]);
	}
	for (int i=1;i<=n;++i){
		int tt=min(t1[i],t2[i]);
		for (int j=T;j>=tt;--j){
			if (j>=t1[i])f[j]=max(f[j],f[j-t1[i]]+w1[i]);
			if (j>=t2[i])f[j]=max(f[j],f[j-t2[i]]+w2[i]);
		}
	}
	printf("%d\n",f[T]);
	return 0;
}
