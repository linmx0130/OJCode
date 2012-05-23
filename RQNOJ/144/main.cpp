#include <cstdio>
#include <string>
using namespace std;
int n,k;
string s[1002];
void qsort(int l,int r){
	int i=l,j=r;
	string mid=s[(l+r)>>1];
	do{
		while (s[i]<mid) i++;
		while (s[j]>mid) j--;
		if (i<=j){
			string k=s[i];
			s[i]=s[j];
			s[j]=k;
			i++;--j;
		}
	}while (i<=j);
	if (l<j)qsort(l,j);
	if (i<r) qsort(i,r);
}
int main(){
	scanf("%d %d",&n,&k);
	for (int i=0;i<n;++i) {
		char tmp[256];
		scanf("%s",tmp);
		s[i]=tmp;
	}
	qsort(0,n-1);
	printf("%s\n",s[k-1].c_str());
	return 0;
}
