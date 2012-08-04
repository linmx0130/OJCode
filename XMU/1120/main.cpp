#include <cstdio>
#include <map>
using namespace std;
map<int,bool> want;
int n,k,x;
int main(){
	scanf("%d %d",&n,&k);
	for (;n;n--){
		scanf("%d",&x);
		if (want[x]){
			printf("Yes\n");
			return 0;
		}
		else {
			want[k-x]=1;
		}
	}
	printf("No\n");
	return 0;
}
