#include <cstdio>
int n,m;
int a[102];
int b[102];
void qsortb(int l,int r){
	int i=l,j=r,mid=b[(i+j)/2];
	do{
		while (b[i]>mid) i++;
		while (b[j]<mid) j--;
		if (i<=j){
			int k=b[i];
			b[i]=b[j];
			b[j]=k;
			i++;j--;
		}
	}while(i<=j);
	if (l<j) qsortb(l,j);
	if (i<r) qsortb(i,r);
}
void qsorta(int l,int r){
	int i=l,j=r,mid=a[(i+j)/2];
	do{
		while (a[i]>mid) i++;
		while (a[j]<mid) j--;
		if (i<=j){
			int k=a[i];
			a[i]=a[j];
			a[j]=k;
			i++;j--;
		}
	}while(i<=j);
	if (l<j) qsorta(l,j);
	if (i<r) qsorta(i,r);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;++i) scanf("%d",&a[i]);
	for (int i=0;i<n;++i) scanf("%d%%",&b[i]);
	qsortb(0,n-1);
	qsorta(0,m-1);
	double ans=0;
	for (int i=0;i<m;++i){
		ans+=(double)a[i]*b[i];
	}
	ans/=100;
	printf("%.0lf\n",ans);
	return 0;
}
