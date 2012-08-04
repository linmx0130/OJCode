#include <iostream>
#define MAXN 100002
#define MAXM 200002
using namespace std;
int n,m;
class Edge{
private:

public:
	int x,y,w;
}d[MAXM];
int Set[MAXN];
int Set_fa(int v){
	if (Set[v]==v) return v;
	Set[v]=Set_fa(Set[v]);
	return Set[v];
}
void Set_union(int x,int y){
	int fx=Set_fa(x);
	int fy=Set_fa(y);
	Set[fx]=fy;
}
#define Set_same(x,y) (Set_fa(x)==Set_fa(y))
void qsort(int l,int r){
	int i=l,j=r,mid=d[(l+r)/2].w;
	class Edge k;
	do{
		while(d[i].w<mid) i++;
		while(d[j].w>mid) j--;
		if (i<=j){
			k=d[i];d[i]=d[j];d[j]=k;
			i++;j--;
		}
	}while(i<=j);
	if (l<j) qsort(l,j);
	if (i<r) qsort(i,r);
}
int main(){
	cin >>n >>m;
	int x,y,w;
	for (int i=1;i<=n;++i) Set[i]=i;
	for (int i=0;i<m;++i){
		cin >> x>>y>>w;
		d[i].x=x;d[i].y=y;d[i].w=w;
	}
	qsort(0,m-1);
	int ans=0,t=0;;
	for (int i=0;(i<m)&&(t<n-1);++i){
		x=d[i].x;
		y=d[i].y;
		w=d[i].w;
		if (!Set_same(x,y)){
			Set_union(x,y);
			ans+=w;
			t++;
		}
	}
	if (t==n-1)cout << ans <<endl;
	else cout <<-1 <<endl;
	return 0;
}
