#include <cstdio>
int a[10];
int h,ans;
int main(){
	for (int i=0;i<10;++i) scanf("%d",a+i);
	scanf("%d",&h);
	for (int i=0;i<10;++i) ans+=(a[i]<=h+30)?1:0;
	printf("%d\n",ans);
	return 0;
}
