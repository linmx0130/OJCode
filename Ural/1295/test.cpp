#include <cstdio>
int k=3;
int main(){
	printf("3 ");
	do
	{
		k*=3;
		k%=100;
		printf("%d ",k);
	}while (k!=3);
}
