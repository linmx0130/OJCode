#include <cstdio>
int n,m;
int f[10002];
#define MAX(a,b) (a>b?a:b)
int main(){
	scanf("%d %d",&m,&n);
	int t,w;
	for (;n;n--){
		scanf("%d %d",&t,&w);
		for (int i=m;i-t>=0;--i){
			f[i]=MAX(f[i],f[i-t]+w);
		}
	}
	printf("%d\n",f[m]);
	return 0;
}
