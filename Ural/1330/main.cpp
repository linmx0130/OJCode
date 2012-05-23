#include <cstdio>
#define MAXN 10002
#define LOWBIT(t) (t&(-t))
class Array{
public:
	int d[MAXN],n;
	void plus(int t,int dd){
		while (t<=n){
			d[t]+=dd;
			t=t+LOWBIT(t);
		}
	}
	int get(int t){
		int ret=0;
		while (t){
			ret+=d[t];
			t-=LOWBIT(t);
		}
		return ret;
	}
}d;
int n,tmp,i,q1,q2;
int main(){
	scanf("%d",&n);
	d.n=n;
	for (i=1;i<=n;++i){
		scanf("%d",&tmp);
		d.plus(i,tmp);
	}
	scanf("%d",&n);
	for (i=1;i<=n;++i){
		scanf("%d%d",&q1,&q2);
		printf("%d\n",d.get(q2)-d.get(q1-1));
	}
	return 0;
}
