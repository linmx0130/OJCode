#include <cstdio>
double sn;
int k;
int main(){
	scanf("%d",&k);
	int i;
	for (i=1;sn<=k;++i){
		sn+=(double)1/i;
	}
	printf("%d\n",i-1);
	return 0;
}
