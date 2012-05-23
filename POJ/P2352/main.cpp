#include <cstdio>
#include <cstring>
#define MAXN 32005
int n;
int d[MAXN];
#define lowbit(x) (x&(-x))
class Array{
public:
	int a[MAXN],c[MAXN],n;
	Array(int n){
		this->n=n;
		memset(a,0,sizeof(a));
		memset(c,0,sizeof(c));
	}
	void plus(int x,int v){
		a[x]+=v;
		for (int i=x;i<=n;i+=lowbit(i)){
			c[i]+=v;
		}
	}
	int sum(int x){
		int ret=0;
		for (int i=x;i>0;i^=lowbit(i)) ret+=c[i];
		return ret;
	}
};
int main(){
	int n;
	scanf("%d",&n);
	Array a(32005);
	for (int i=1;i<=n;++i){
		int x,y; 
		scanf("%d%d",&x,&y);
		a.plus(x+1,1);
		d[a.sum(x+1)-1]++;
	}
	for (int i=0;i<n;++i){
		printf("%d\n",d[i]);
	}
	return 0;
}
