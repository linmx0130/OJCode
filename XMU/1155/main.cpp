#include <cstdio>
using namespace std;
int w[1861];
int main(){
	int ans=0;
	for (int i=1;i<=1861;++i){
		ans+=i*i;
		w[i]=ans;
	}
	int C;
	scanf("%d",&C);
	for (;C;C--){
		int x;
		scanf("%d",&x);
		int l=1,r=1861;
		int flag=0;
		while (l<r){
			if (x<w[(l+r)/2]){
				r=(l+r)/2;
				continue;
			}
			if (x>w[(l+r)/2]) {
				l=(l+r)/2+1;
				continue;
			}
			if (x==w[(l+r)/2]) {
				flag=1;
				break;
			}
		}
		if (flag) printf("Yes\n"); 
		else printf("No\n");
	}
	return 0;
}
