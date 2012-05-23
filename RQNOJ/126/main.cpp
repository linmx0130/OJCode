#include <cstdio>
struct Std_t{
	int Tot,C,M,E,Num;
}d[10002];
int n;
inline bool operator>(Std_t a,Std_t b){
	if (a.Tot>b.Tot) return 1;
	if (a.Tot<b.Tot) return 0;

	if (a.C>b.C) return 1;
	if (a.C<b.C) return 0;
	if (a.Num<b.Num) return 1;
	return 0;
}
void qsort(int l,int r){
	int i=l,j=r;
	struct Std_t mid=d[(l+r)/2],k;
	do{
		while (d[i]>mid) 
			++i;
		while (mid>d[j]) 
			--j;
		if (i<=j){
			k=d[i];
			d[i]=d[j];
			d[j]=k;
			++i;--j;
		}
	}while (i<=j);
	if (l<j) qsort(l,j);
	if (i<r) qsort(i,r);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		int C,M,E;
		scanf("%d %d %d",&C,&M,&E);
		d[i].Tot=C+M+E;
		d[i].Num=i;
		d[i].C=C;
		d[i].M=M;
		d[i].E=E;
	}
	qsort(1,n);
	for (int i=1;i<=5;++i){
		printf("%d %d\n",d[i].Num,d[i].Tot);
	}
	return 0;
}
