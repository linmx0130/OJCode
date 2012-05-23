#include <cstdio>
#include<cstring>
int n;
long long maxint;
long long d[202][2];
long long f[202][202];
bool done[202][202];
void dp(int l,int r){
     if (done[l][r]) return;
     done[l][r]=1;
     if(l==r) {f[l][r]=0;return;}
     for (int i=l;i<r;++i){
         dp(l,i);dp(i+1,r);
         long long will=f[l][i]+f[i+1][r]+d[l][0]*d[i][1]*d[r][1];
         if ((f[l][r]>will)||(f[l][r]==0)){
                           f[l][r]=will;
                           }
     }
}
int main(){
    freopen("1_data.in","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%lld%lld",&d[i][0],&d[i][1]);
				d[n+i][0]=d[i][0];
				d[n+i][1]=d[i][1];
    }
    dp(1,2*n);
		long long ans=f[1][n];
		for (int i=1;i<n;++i){
			if (ans>f[i][i+n-1]) ans=f[i][i+n-1];
		}
		printf("%lld\n",ans);
    while(1);
    return 0;
}
