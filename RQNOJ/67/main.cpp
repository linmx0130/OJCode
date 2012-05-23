#include <cstdio>
#include <cmath>
int x[23];
int ans;
int n,k;
inline bool check(int a){
	for (int i=2;i<=sqrt(a);++i){
		if (!(a%i))return false;
	}
	return true;
}
void search(int now,int sum,int st){
	if (now==k){
		ans+=check(sum);
		return;
	}
	for (int i=st+1;i<=n;++i){
		search(now+1,sum+x[i],i);
	}
}
int main(){
	scanf("%d %d",&n,&k);
	int max=0;
	for (int i=1;i<=n;++i){
		scanf("%d",&x[i]);
		max+=x[i];
	}
	search(0,0,0);
	printf("%d\n",ans);
	return 0;
}
