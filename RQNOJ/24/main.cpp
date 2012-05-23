#include <cstdio>
int ans;
int k;
int x;
int main(){
	for (int i=1;i<=12;++i){
		scanf("%d",&x);
		ans+=(300-x);
		if (ans<0){
			printf("%d\n",-i);
			return 0;
		}
		k+=ans/100;
		ans%=100;
	}
	printf("%d\n",k*120+ans);
	return 0;
}
