#include <cstdio>
#define MAXN 1002
#define A(x) (x*4-2)
#define B(x) (x*4-1)
#define C(x) (x*4)
#define D(x) (x*4+1)
class Node{
public:
	int x1,y1,x2,y2;
	bool mark,lazy;
};
class SegTree{
public:
	Node d[MAXN*MAXN*4*4];
	void build(int x1,int y1,int x2,int y2,int pos){
		if (x1>x2) x1--;
		if (y1>y2) y1--;
		d[pos].x1=x1;
		d[pos].y1=y1;
		d[pos].x2=x2;
		d[pos].y2=y2;
		d[pos].mark=d[pos].lazy=0;
		if ((x1==x2)&&(y1==y2)) return;
		int xmid=(x1+x2)>>1;
		int ymid=(y1+y2)>>1;
		build(x1,y1,xmid,ymid,A(pos));
		build(x1,ymid+1,xmid,y2,B(pos));
		build(xmid+1,y1,x2,ymid,C(pos));
		build(xmid+1,ymid+1,x2,y2,D(pos));
	}
	void insert(int x1,int y1,int x2,int y2,int pos){
		if (x1>x2) x1--;
		if (y1>y2) y1--;
		if ((d[pos].x1==x1)&&(d[pos].x2==x2)&&(d[pos].y1==y1)&&(d[pos].y2==y2))
		{
			d[pos].mark=!d[pos].mark;
			d[pos].lazy=!d[pos].lazy;
			return ;
		}
		if (d[pos].lazy){
			d[pos].lazy=0;
			d[A(pos)].lazy=!d[A(pos)].lazy;
			d[A(pos)].mark=!d[A(pos)].mark;
			d[B(pos)].lazy=!d[B(pos)].lazy;
			d[B(pos)].mark=!d[B(pos)].mark;
			d[C(pos)].lazy=!d[C(pos)].lazy;
			d[C(pos)].mark=!d[C(pos)].mark;
			d[D(pos)].lazy=!d[D(pos)].lazy;
			d[D(pos)].mark=!d[D(pos)].mark;
		}
		int xmid=(d[pos].x1+d[pos].x2)>>1;
		int ymid=(d[pos].y1+d[pos].y2)>>1;
		if ((d[pos].x1<=x1)&&(x2<=xmid)&&(d[pos].y1<=y1)&&(y2<=ymid)){
			insert(x1,y1,x2,y2,A(pos));
			return;
		}
		if ((d[pos].x1<=x1)&&(x2<=xmid)&&(ymid<y1)&&(y2<=d[pos].y2)){
			insert(x1,y1,x2,y2,B(pos));
			return;
		}
		if ((xmid<x1)&&(x2<=d[pos].x2)&&(d[pos].y1<=y1)&&(y2<=ymid)){
			insert(x1,y1,x2,y2,C(pos));
			return;
		}
		if ((xmid<x1)&&(x2<=d[pos].x2)&&(ymid<y1)&&(y2<=d[pos].y2)){
			insert(x1,y1,x2,y2,D(pos));
			return;
		}

		if ((d[pos].x1<=x1)&&(x2<=xmid)&&(d[pos].y1<=y1)&&(y2<=d[pos].y2))
		{
			insert(x1,y1,x2,ymid,A(pos));
			insert(x1,ymid+1,x2,y2,B(pos));
			return;
		}

		if ((xmid<x1)&&(x2<=d[pos].x2)&&(d[pos].y1<=y1)&&(y2<=d[pos].y2))
		{
			insert(x1,y1,x2,ymid,C(pos));
			insert(x1,ymid+1,x2,y2,D(pos));
			return ;
		}

		if ((d[pos].x1<=x1)&&(x2<=d[pos].x2)&&(d[pos].y1<=y1)&&(y2<=ymid))
		{
			insert(x1,y1,xmid,y2,A(pos));
			insert(xmid+1,y1,x2,y2,C(pos));
			return ;
		}

		if ((d[pos].x1<=x1)&&(x2<=d[pos].x2)&&(ymid<y1)&&(y2<=d[pos].y2))
		{
			insert(x1,y1,xmid,y2,B(pos));
			insert(xmid+1,y1,x2,y2,D(pos));
			return ;
		}

		insert(x1,y1,xmid,ymid,A(pos));
		insert(x1,ymid+1,xmid,y2,B(pos));
		insert(xmid+1,y1,x2,ymid,C(pos));
		insert(xmid+1,ymid+1,x2,y2,D(pos));
	}
	bool query(int x,int y,int pos){
		if (d[pos].lazy){
			d[pos].lazy=0;
			d[A(pos)].lazy=!d[A(pos)].lazy;
			d[A(pos)].mark=!d[A(pos)].mark;
			d[B(pos)].lazy=!d[B(pos)].lazy;
			d[B(pos)].mark=!d[B(pos)].mark;
			d[C(pos)].lazy=!d[C(pos)].lazy;
			d[C(pos)].mark=!d[C(pos)].mark;
			d[D(pos)].lazy=!d[D(pos)].lazy;
			d[D(pos)].mark=!d[D(pos)].mark;
		}
		if ((d[pos].x1==x)&&(d[pos].x2==x)&&(d[pos].y1==y)&&(d[pos].y2==y)){
			return d[pos].mark;
		}
		int xmid=(d[pos].x1+d[pos].x2)>>1;
		int ymid=(d[pos].y1+d[pos].y2)>>1;
		if ((d[pos].x1<=x)&&(x<=xmid)){
			if ((d[pos].y1<=y)&&(y<=ymid)){
				return query(x,y,A(pos));
			}
			if ((ymid<y)&&(y<=d[pos].y2)){
				return query(x,y,B(pos));
			}
		}
		if ((x<xmid)&&(x<=d[pos].x2)){
			if ((d[pos].y1<=y)&&(y<=ymid)){
				return query(x,y,C(pos));
			}
			if ((ymid<y)&&(y<=d[pos].y2)){
				return query(x,y,D(pos));
			}
		}
	}
	inline int iquery(int x,int y){
		return query(x,y,1)?1:0;
	}
}t;

void work(){
	int n,T;
	scanf("%d%d",&n,&T);
	t.build(1,1,n,n,1);
	for (;T;--T){
		char C;
		scanf("\n%c",&C);
		if (C=='C'){
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			t.insert(x1,y1,x2,y2,1);
		}
		if (C=='Q'){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",t.iquery(x,y));
		}
	}
}
int main(){
	int N;
	scanf("%d",&N);
	for (;N;--N){
		work();
	}
}
