#include <cstdio>
#include <algorithm>
#include <cstring>
int n,m;
#define MAXN 100002
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define FA(x) (x>>1)
int s[MAXN],d[MAXN];
int t[30][MAXN];
struct NodeType{
	int l,r;
}T[MAXN*4];
int tol[30][MAXN];
void buildtree(int level,int now,int l,int r){
	T[now].l=l;
	T[now].r=r;
	if (l==r) return;
	int mid=(l+r)>>1,lsame=(mid)-l+1;
	for (int i=l;i<=r;++i){
		if (t[level][i]<s[mid]) lsame--;;
	}
	int Ll=l,Lr=mid,Rl=mid+1,Rr=r;
	int Ltot=0,Rtot=0;
	for (int i=l;i<=r;++i){
		if (i==l) tol[level][i]=0;
		else tol[level][i]=tol[level][i-1];


		if (t[level][i]<s[mid]){
			t[level+1][Ll+Ltot++]=t[level][i];
			tol[level][i]++;
		}
		
		if  (t[level][i]>s[mid]){
			t[level+1][Rl+Rtot++]=t[level][i];
		}

		if (t[level][i]==s[mid]){
			if (lsame>0){
				lsame--;
				tol[level][i]++;
				t[level+1][Ll+Ltot++]=t[level][i];
			}else {
				t[level+1][Rl+Rtot++]=t[level][i];
			}
		}
	}
	buildtree(level+1,L(now),Ll,Lr);
	buildtree(level+1,R(now),Rl,Rr);
}//n log n
int find(int level,int now,int l,int r,int k){
	if (l==r) return t[level][l];
	int s,ss;
	
	if (l==T[now].l) ss=0;
	else ss=tol[level][l-1];
	s=tol[level][r]-ss;

	if (s>=k){
		return find(level+1,L(now),T[now].l+ss,T[now].l+ss+s-1,k);
	}else {
		int mid=(T[now].l+T[now].r)>>1;
		int ee=l-T[now].l+1-ss;
		int e=r-l+1-s;
		return find(level+1,R(now),mid+ee,mid+ee+e-1,k-s);
	}
	
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",d+i);
		t[1][i]=s[i]=d[i];
	}
	std::sort(s+1,s+n+1);
	buildtree(1,1,1,n);
	int l,r,k;
	for (int i=1;i<=m;++i){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",find(1,1,l,r,k));
	}
	return 0;
}
