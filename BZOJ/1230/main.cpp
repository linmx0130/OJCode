#include <cstdio>
#include <cstring>
#define MAXN 100002
class Node{
public:
	int l,r,sum;
	bool lazy;
};
class LineTree{
public:
	Node d[MAXN*4];
	void build(int l,int r,int pos){
		d[pos].l=l;
		d[pos].r=r;
		d[pos].lazy=0;
		if (l!=r){
			int mid=(l+r)>>1;
			build(l,mid,pos<<1);
			build(mid+1,r,(pos<<1)+1);
		}
	}
	inline LineTree(int n){
		build(1,n,1);
	}

	void __update(int l,int r,int pos){
		if ((d[pos].l==l)&&(d[pos].r==r)) {
			d[pos].lazy=!d[pos].lazy;
			d[pos].sum=(r-l+1)-d[pos].sum;
			return ;
		}
		int qmid=d[pos].l+d[pos].r;
		qmid>>=1;
		if (d[pos].lazy){
			//向下传
			d[pos].lazy=0;
			d[pos<<1].sum=(d[pos<<1].r-d[pos<<1].l+1)-d[pos<<1].sum;
			d[pos<<1].lazy=!d[pos<<1].lazy;
			d[1+(pos<<1)].sum=d[1+(pos<<1)].r-d[1+(pos<<1)].l+1-d[1+(pos<<1)].sum;
			d[1+(pos<<1)].lazy=!d[1+(pos<<1)].lazy;
		}
		if ((d[pos].l<=l)&&(qmid>=r)){
			int tmp=d[1+(pos<<1)].sum;
			__update(l,r,pos<<1);
			d[pos].sum=d[pos<<1].sum+tmp;
			return ;
		}
		if ((l>qmid)&&(r<=d[pos].r)){
			int tmp=d[pos<<1].sum;
			__update(l,r,(pos<<1)+1);
			d[pos].sum=tmp+d[1+(pos<<1)].sum;
			return ;
		}
		__update(l,qmid,pos<<1);
		__update(qmid+1,r,(pos<<1)+1);
		d[pos].sum=d[pos<<1].sum+d[1+(pos<<1)].sum;
	}
	inline void update(int l,int r){
		__update(l,r,1);
	}
	int __sum(int l,int r,int pos){
		if ((d[pos].l==l)&&(d[pos].r==r)) return d[pos].sum;
		int qmid=(d[pos].l+d[pos].r)>>1;
		if (d[pos].lazy){
			//向下传
			d[pos].lazy=0;
			d[pos<<1].sum=(d[pos<<1].r-d[pos<<1].l+1)-d[pos<<1].sum;
			d[pos<<1].lazy=!d[pos<<1].lazy;
			d[1+(pos<<1)].sum=d[1+(pos<<1)].r-d[1+(pos<<1)].l+1-d[1+(pos<<1)].sum;
			d[1+(pos<<1)].lazy=!d[1+(pos<<1)].lazy;
		}
		if ((d[pos].l<=l)&&(r<=qmid)){
			return __sum(l,r,pos<<1);
		}
		if ((l>qmid)&&(r<=d[pos].r)){
			return __sum(l,r,1+(pos<<1));
		}
		int a=__sum(l,qmid,pos<<1);
		int b=__sum(qmid+1,r,1+(pos<<1));
		return a+b;
	}
	inline int sum(int l,int r){
		return __sum(l,r,1);
	}
};
int main(){
	int n,m;
	for (;~scanf("%d%d",&n,&m);){
		LineTree t(n);
		for (int i=1;i<=m;++i){
			int op,x,y;
			scanf("%d%d%d",&op,&x,&y);
			if (op==0){
				t.update(x,y);
			}
			if (op==1){
				printf("%d\n",t.sum(x,y));
			}
		}
	}
	return 0;
}
