#include <cstdio>
int n,m,k;
class Data_t{
public:
	long long avg,s;
	int key;
	void build(int *p,int keyt){
		for (int i=0;i<k;++i){
			avg+=p[i];
			s+=p[i]*p[i];
		}
		key=keyt;
		avg/=k;
		s-=k*avg*avg;
		s/=k;
	}
}a[1002];
bool operator>(Data_t a,Data_t b){
	if (a.avg>b.avg) return 1;
	if (a.avg<b.avg) return 0;
	//a.avg==b.avg
	if (a.s<b.s) return 1;
	if (a.s>b.s) return 0;
	return a.key<b.key;
}
bool operator<(Data_t a,Data_t b){
	if (a.avg<b.avg) return 1;
	if (a.avg>b.avg) return 0;
	//a.avg==b.avg
	if (a.s>b.s) return 1;
	if (a.s<b.s) return 0;
	return a.key>b.key;
}
int d[15];
void qsort(int l,int r){
	int i=l,j=r;
	Data_t mid=a[(l+r)/2];
	do{
		while (a[i]>mid) ++i;
		while (a[j]<mid) --j;
		if (i<=j){
			Data_t k=a[i];
			a[i]=a[j];
			a[j]=k;
			++i;--j;
		}
	}while (i<=j);
	if (l<j) qsort(l,j);
	if (i<r) qsort(i,r);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;++i){
		for (int j=0;j<k;++j){
			scanf("%d",d+j);
		}
		a[i].build(d,i);
	}
	qsort(1,n);
	for (int i=1;i<m;++i){
		printf("%d ",a[i].key);
		if ((a[i].key==502)||(a[i].key==40)){
			printf("\n%lld %lld\n",a[i].avg,a[i].s);
		}
	}
	printf("%d\n",a[m].key);
	return 0;
}
