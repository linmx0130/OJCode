#include <cstdio>
#define MAXN (50002*3)
int fa[MAXN],p[MAXN];
int n,m,ans;
int find(int x){
	if (p[x]==x) return x;
	p[x]=find(p[x]);
	return p[x];
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n*3;++i){
		p[i]=i;
	}
	for (int i=1;i<=n;++i){
		fa[i]=i+n;
		fa[i+n]=i+n+n;
		fa[i+n+n]=i;
	}
	for (;m;m--){
		int o,x,y;
		scanf("%d %d %d",&o,&x,&y);
		if (x>n||y>n) {
			ans++;continue;
		}
		int a[3],b[3];
		a[0]=find(x);b[0]=find(y);
		a[1]=fa[a[0]];a[2]=fa[a[1]];
		b[1]=fa[b[0]];b[2]=fa[b[1]];
		int k,same=0;
		for (int i=0;i<3;++i){
			if (a[0]==b[i]){
				k=i;
				same=1;
				break;
			}
		}
		if (o==1){
			if (same){
				if (a[0]!=b[0]) ans++;
			}else{
				for (int i=0;i<3;++i){
					p[b[i]]=a[i];
				}
			}
		}
		else {
			if (x==y){
				ans++;
				continue;
			}
			if (same){
				if (fa[b[0]]!=a[0]) ans++;
			}
			else {
				for (int i=0;i<3;++i){
					p[b[i]]=a[(i+2)%3];
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}

