#include <cstdio>
int c;
int bin(int n,int t){
	for (;n;n>>=1){
		if ((n&t)==t) return 1;
	}
	return 0;
}
int main(){
	int n,k,t;
	scanf ("%d",&c);
	for (;c;c--){
		scanf("%d%d",&n,&k);
		t=(1<<k)-1;
		if (bin(n,t)) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
