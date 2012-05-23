#include <cstdio>
bool d[1002];
int n,x;
int main(){
	scanf("%d",&n);
	for (;n;n--) {
		scanf("%d",&x);
		d[x]=1;
	}
	for (int i=1;i<=1000;++i) if (d[i]) n++;
	printf("%d\n",n);
	for (int i=1;i<=1000;++i){
		if (d[i]){
			printf("%d",i);
			n--;
			if (n!=0) printf(" ");
			else {printf("\n");return 0;}
		}
	}
}
