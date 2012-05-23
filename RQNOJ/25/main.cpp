#include <cstdio>
#define MAXN 20002
int a[MAXN],ans;
int n,tot;
void heap_up(int x){
	int k;
	if (a[x]<a[x>>1]){
		k=a[x];
		a[x]=a[x>>1];
		a[x>>1]=k;
		heap_up(x>>1);
	}
}
inline void ins(int x){
	a[++tot]=x;
	heap_up(tot);
}
void heap_down(int x){
	int k;
	if (x>(tot>>1)) return ;
	if ((a[x]<a[x<<1])&&(a[x]<a[(x<<1)+1]))return ;
	if ((a[x]==a[x<<1])&&(a[x]==a[(x<<1)+1])) return;
	if (a[x<<1]<a[(x<<1)+1]){
		k=a[x<<1];
		a[x<<1]=a[x];
		a[x]=k;
		heap_down(x<<1);
	}else{
		k=a[(x<<1)+1];
		a[(x<<1)+1]=a[x];
		a[x]=k;
		heap_down((x<<1)+1);
	}
}
inline void del(){
	a[1]=a[tot--];
	heap_down(1);
}
inline int pop(){
	int k=a[1];
	del();
	return k;
}
int main(){
	scanf("%d",&n);
	int x,y;
	for (int i=1;i<=n;++i) {
		scanf("%d",&x);
		ins(x);
	}
	for (;n>1;--n){
		x=pop();
		y=pop();
		ans+=(x+y);
		ins(x+y);
	}
	printf("%d\n",ans);
	return 0;
}
