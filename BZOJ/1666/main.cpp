#include <cstdio>
int main(){
	int n,ans=0;
	scanf("%d",&n);
	for (;n!=1;){
		if (n&1){
			n*=3;
			n++;
			ans++;
		}else{
			n>>=1;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
