#include <stdio.h>
int d[101];
int main(n,i,j,x,max){
	scanf("%d",&n);
	max=0;
	for (i=1;i<=n;++i){
		for (j=1;j<=n;++j){
			scanf("%d",&x);
			if (x>=3) d[i]++;
		}
		if (d[max]<d[i]) max=i;
	}
	printf("%d\n",max);
	return 0;
}
