#include <cstdio>
#include <cstring>
#define MAXN 100002
bool used[MAXN];
class QBst{
	int data[MAXN];
	int left[MAXN],right[MAXN];
	int tot;
	int ltot[MAXN],rtot[MAXN],me[MAXN];
	int QBstBuild(int l,int r){
		int now=++tot;
		int tmp=(l+r)/2;
		data[now]=tmp;
		if (l==r) return now;
		if (tmp>l) left[now]=QBstBuild(l,tmp-1);
		if (tmp<r) right[now]=QBstBuild(tmp+1,r);
		return now;
	}
public :
	int ptot;
	QBst(int n){
		memset(left,0,sizeof(left));
		memset(right,0,sizeof(right));
		memset(ltot,0,sizeof(ltot));
		memset(rtot,0,sizeof(rtot));
		memset(me,0,sizeof(me));
		tot=0;
		ptot=0;
		QBstBuild(1,n);
	}
	void insert(int x,int pos){
		if (x>data[pos]){
			rtot[pos]++;
	 		insert(x,right[pos]);
		}
		if (x<data[pos]){
			ltot[pos]++;
			insert(x,left[pos]);
		}
		if (x==data[pos]){
			me[pos]=1;
			ptot++;
		}
	}
	void del(int x,int pos){
		if (x>data[pos]){
			rtot[pos]--;
			del(x,right[pos]);
		}
		if (x<data[pos]){
			ltot[pos]--;
			del(x,left[pos]);
		}
		if (x==data[pos]){
			me[pos]=0;
			ptot--;
		}
	}
	int find(int k,int pos){
		if (me[pos]){
			if (ltot[pos]+1==k) return data[pos];
			if (ltot[pos]>=k) return find(k,left[pos]);
			return find(k-ltot[pos]-1,right[pos]);
		}
		else 
		{
			if (ltot[pos]>=k) return find(k,left[pos]);
			return find(k-ltot[pos],right[pos]);
		}
	}
};

int main(){
	int n,m;
	scanf("%d",&n);
	QBst d(MAXN);
	int op,a;
	for (;n;n--){
		scanf("%d%d",&op,&a);
		if ((op==1)&&(!used[a])) {
			used[a]=1;
			d.insert(a,1);
		}
		if ((op==2)&&(used[a])) {
			used[a]=0;
			d.del(a,1);
		}
		if (op==3){
			if (a<=d.ptot) printf("%d\n",d.find(a,1));
			else printf("-1\n");
		}
	}
	return 0;
}
