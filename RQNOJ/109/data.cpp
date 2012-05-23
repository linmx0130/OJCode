#include <cstdio>
#include <cstdlib>
#include <ctime>
int main(){
	srand(time(0));
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d %d\n",n,m);
	for (int i=1;i<=n;++i){
		printf("%d %d %d\n",rand()%100+1,rand()%1000+1,rand()%10+1);
	}
	return 0;
}
