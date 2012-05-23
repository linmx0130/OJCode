#include <cstdio>
#include <ctime>
#include <cstdlib>

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	srand(time(0));
	printf("%d %d\n",n,m);
	for (int i=1;i<=n;++i){
		int a=rand()%n+1;
		int b=rand()%n+1;
		if (a<b)
		printf("%d %d %d\n",rand()%2,a,b);
		else 
		printf("%d %d %d\n",rand()%2,b,a);
	}
	return 0;
}
