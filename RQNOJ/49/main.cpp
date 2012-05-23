#include <cstdio>
int f[35][35];
int root[35][35];
int score[35];
bool done[35][35];
int n;
#define MAX(a,b) (a>b?a:b)
void pr(int l,int r){
	if ((l==1)&&(r==n)) printf("%d",root[l][r]);
	else printf(" %d",root[l][r]);
	if (l<root[l][r]) pr(l,root[l][r]-1);
	if (root[l][r]<r)pr(root[l][r]+1,r);
}
void dp(int l,int r){
	if (done[l][r])return;
	done[l][r]=1;
	int max=0,maxt;
	if (l==r) {
		f[l][r]=score[l];
		root[l][r]=l;
		return ;
	}
	if (l>r) {f[l][r]=1;return;}
	for (int i=l;i<=r;++i){
		dp(l,i-1);
		dp(i+1,r);
		if (f[l][i-1]*f[i+1][r]+score[i]>max){
			max=f[l][i-1]*f[i+1][r]+score[i];
			maxt=i;
		}
	}
	f[l][r]=max;
	root[l][r]=maxt;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i)scanf("%d",&score[i]);
	dp(1,n);
	printf("%d\n",f[1][n]);
	pr(1,n);
	printf("\n");
	return 0;
}
