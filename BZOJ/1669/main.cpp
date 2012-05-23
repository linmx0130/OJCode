#include <cstdio>
int a[5002],f[5002];
int n,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",a+i);
	}
	f[1]=a[1];
	ans=1;
	for (int i=2;i<=n;++i){
		int left=1;
		int right=ans;
		while(left<right){
			int mid=(left+right)>>1;
			if (f[mid]>a[i]) right=mid;
			if (f[mid]<a[i]) left=mid+1;
		}
		int mid=(left+right)>>1;
		if (f[mid]>a[i]) f[mid]=a[i];
		if ((f[mid]<a[i])&&(mid==ans)){
			f[++ans]=a[i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
