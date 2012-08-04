#include <cstdio>
const int md[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int md1[14];
int main(){
	int n;
	scanf("%d",&n);
	int y,m,d;
	for (int i=1;i<=12;++i){
		md1[i]=md1[i-1]+md[i-1];
	}
	for (;n;n--){
		scanf("%d/%d/%d",&y,&m,&d);
		d+=md1[m];
		if ((m>2) ||((m==2)&&(d==29))){
			if ((y%100!=0)&&(y%4==0)) d++;
			if (y%400==0) d++;
		}
		printf("%d\n",d);
	}
	return 0;
}
