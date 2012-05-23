#include <cstdio>
#include <cstring>
//#include <algorithm>
int n,K;
int d[105];
int print[105][105];
int main(){
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;++i) scanf("%d",d+i);
	int eachlen=n/K;
	if (n%K) eachlen++;
	int i,j=1,k=1;
//	std::sort(d+1,d+n+1);
	for (i=1;i<=n;++i){
		print[k][j]=d[i];
		print[k][0]++;
		++k;
		if (k>eachlen){j++;k=1;}
	}
	for (i=1;i<=eachlen;++i){
		for (j=1;j<=print[i][0];++j){
			printf("%4d",print[i][j]);
		}
		puts("");
	}
	return 0;
}
