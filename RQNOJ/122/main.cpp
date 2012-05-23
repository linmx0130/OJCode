#include <cstdio>
int n;
char s[4][4][10]={{"hong","bai","qing","huang"},
	                {"bai","qing","huang","hong"},
                  {"qing","huang","hong","bai"},
                  {"huang","hong","bai","qing"},
                 };

int main(){
	scanf("%d",&n);
	printf("%s\n",s[((n-1)%16)/4][(n-1)%4]);
	int x=(n-1)%16/4;
	for (int i=0;i<3;++i){
		printf("%s ",s[x][i]);
	}
	printf("%s\n",s[x][3]);
	return 0;
}
