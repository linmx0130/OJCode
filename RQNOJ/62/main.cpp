#include <cstdio>
int n,a[102],tot,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",a+i);
		tot+=a[i];
	}
	tot/=n;
	for (int i=1;i<=n;++i){
		int tmp=a[i]-tot;
		if (tmp) {a[i+1]+=a[i]-tot;ans++;}
	}
	printf("%d\n",ans);
	return 0;
}
