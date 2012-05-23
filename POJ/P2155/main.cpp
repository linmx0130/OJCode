#include <cstdio>
#include <cstring>
#define lowbit(t) (t&(-t))
#define MAXN 1002
int n;
class Array{
public:
	int d[MAXN][MAXN],n;
	void modify(int x,int y){
		for (int i=x;i>0;i^=lowbit(i)){
			for (int j=y;j>0;j^=lowbit(j)){
				d[i][j]++;
			}
		}
	}
	int query(int x,int y){
		int ret=0;
		for (int i=x;i<=n;i+=lowbit(i)){
			for (int j=y;j<=n;j+=lowbit(j)){
				ret+=d[i][j];
			}
		}
		return ret;
	}
	Array(int n){
		this->n=n;
		memset(d,0,sizeof(d));
	}
};
int main()
{
	int T;
	scanf("%d",&T);
	for (;T;--T){
		int n,t;char C;
		scanf("%d%d",&n,&t);
		Array a(n+1);
		for (;t;--t){
			scanf("\n%c",&C);
			if (C=='C'){
				int x1,y1,x2,y2;
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				x1++;y1++;x2++;y2++;
				a.modify(x2,y2);
				a.modify(x1-1,y2);
				a.modify(x2,y1-1);
				a.modify(x1-1,y1-1);
			}
			else {
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%d\n",a.query(x+1,y+1)&1);
			}
		}
		printf("\n");
	}
	return 0;
}
