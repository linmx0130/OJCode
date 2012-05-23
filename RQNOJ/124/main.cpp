#include <cstdio>
int main(){
	int i,a,n;
	scanf("%d",&n);
	for (;n;n--){
		scanf("%d",&a);
		if (a<=0||a>67108863) {printf("None\n");continue;}
		bool ff=0;
		for (int i=0,j=1;a;(++i),(j<<=1)){
			if (a&j) {
				if (ff) printf(" %c",'A'+i);
				else {printf("%c",'A'+i);ff=1;}
				a-=j;
			}
		}
		if (!ff) printf("None");
		printf("\n");
	}
	return 0;
}
