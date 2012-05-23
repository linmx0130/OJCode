#include <cstdio>
int n,k;
int get(int d){
	if (d<k+2) return 1;
	if ((d&1)!=(k&1)) return 1;
	int a=d-k,b;
	a=a>>1;
	b=d-a;
	return get(a)+get(b);
}
int main(){
	scanf("%d%d",&n,&k);
	printf("%d\n",get(n));
	return 0;
}
