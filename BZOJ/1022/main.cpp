#include <cstdio>
int main(){
	int T,n,k,ans,g;bool t;
	scanf("%d",&T);
	for (;T;T--){
		scanf("%d",&n);
		ans=0;g=0;t=0;
		for (;n;n--){
			scanf("%d",&k);
			ans^=k;
			if (k==1)g++;
			if (k>1) t=1;
		}
		if (t) {
			if (ans) printf("John\n");else printf("Brother\n");
		}else{
			if (g%2) printf("Brother\n"); else printf("John\n");
		}
	}
	return 0;
}
