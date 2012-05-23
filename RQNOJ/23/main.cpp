#include <cstdio>
#define ABS(a) ((a)>0?(a):-(a))
struct Data_t{
	int x,y;
	int w;
}a[402];
int m,n,k,tot;
void qsort(int l,int r){
	int i=l,j=r,mid=a[(l+r)/2].w;
	do{
		while (a[i].w>mid) ++i;
		while (a[j].w<mid) --j;
		if (i<=j){
			struct Data_t k;
			k=a[i];
			a[i]=a[j];
			a[j]=k;
			++i;--j;
		}
	}while(i<=j);
	if (l<j) qsort(l,j);
	if (i<r) qsort(i,r);
}
int main(){
	int x;
	scanf("%d %d %d",&m,&n,&k);
	for (int i=1;i<=m;++i){
		for (int j=1;j<=n;++j){
			scanf("%d",&x);
			if (x) {
				struct Data_t d;
				d.x=i;d.y=j;d.w=x;
				a[tot++]=d;
			}
		}
	}
	qsort(0,tot-1);
	int ans=0;
	int nowx,nowy;
	nowx=0;nowy=a[0].y;
	for (int i=0;i<tot;++i){
		int dis=ABS(nowx-a[i].x)+ABS(nowy-a[i].y);
		int disr=a[i].x;
		if (dis+disr+1>k){
			printf("%d\n",ans);
			return 0;
		}
		k-=(dis+1);
		ans+=a[i].w;
		nowx=a[i].x;
		nowy=a[i].y;
	}
	printf("%d\n",ans);
	return 0;
}
