#include <cstdio>
int ans;
int main(){
	int n;
	ans=1;
	scanf("%d",&n);
	int x;
	for (int i=1;i<=n;++i){
		scanf("%d",&x);
		ans*=x;
		if (ans>=9973) ans%=9973;
	}
	printf("%d\n",ans);
	return 0;
}
