#include <cstdio>
#include <map>
using namespace std;
#define MAXN 25
int ans;
class Node{
public:
	int l,r;
	bool fill;
};
class LineTree{
public:
	Node d[MAXN*4];
	void build(int l,int r,int pos){
		d[pos].l=l;
		d[pos].r=r;
		d[pos].fill=0;
		if (l!=r){
			build(l,(l+r)>>1,pos<<1);
			build(1+((l+r)>>1),r,(pos<<1)+1);
		}
	}
	inline void init(int n){
		build(1,n,1);
	}
	bool  __insert(int l,int r,int pos){
		if (d[pos].fill) return 0;
		if ((d[pos].l==l)&&(d[pos].r==r)){
			d[pos].fill=1;
			return 1;
		}
		int qmid=(d[pos].l+d[pos].r)>>1;
		if ((d[pos].l<=l)&&(r<=qmid)){
			bool xxx=__insert(l,r,pos<<1);
			d[pos].fill=d[pos<<1].fill&&d[1+(pos<<1)].fill;
			return xxx;
		}
		if ((qmid<l)&&(r<=d[pos].r)){
			bool xxx=__insert(l,r,1+(pos<<1));
			d[pos].fill=d[1+(pos<<1)].fill&&d[pos<<1].fill;
			return xxx;
		}
		if ((d[pos].l<=l)&&(r<=d[pos].r)){
			bool xxx=__insert(l,qmid,pos<<1);
			bool yyy=__insert(qmid+1,r,1+(pos<<1));
			d[pos].fill=d[pos<<1].fill&&d[1+(pos<<1)].fill;
			return xxx||yyy;
		}
	}
	inline bool insert(int l,int r){
		return __insert(l,r,1);
	}
}t;
map<int,int> Data;
int a[MAXN];
void sort(int l,int r){
	int i=l,j=r,mid=a[(l+r)>>1];
	do{
		while(a[i]<mid) i++;
		while(a[j]>mid) j--;
		if (i<=j){
			int k=a[i];
			a[i]=a[j];
			a[j]=k;
			++i;--j;
		}
	}while(i<=j);
	if (l<j) sort(l,j);
	if (i<r) sort(i,r);
}
int d[MAXN][2];
void work(){
	ans=0;
	int n;
	scanf("%d",&n);
	t.init(MAXN-1);
	int x,y;
	for (int i=1;i<=n<<1;i+=2){
		scanf("%d%d",&x,&y);
		a[i]=x;
		a[i+1]=y;
		d[(i+1)>>1][0]=x;
		d[(i+1)>>1][1]=y;
	}
	sort(1,n<<1);
	int tot=0;
	for (int i=1;i<=n<<1;i++){
		if (a[i]!=a[i-1]) Data[a[i]]=++tot;
	}
	for (int i=n;i>=1;--i){
		if (t.insert(Data[d[i][0]],Data[d[i][1]])) ans++;
	}
	printf("%d\n",ans);
}
int main(){
	int N;
	scanf("%d",&N);
	for (;N;--N){
		work();
	}
	return 0;
}
