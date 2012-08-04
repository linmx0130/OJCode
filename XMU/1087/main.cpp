#include <cstdio>
int main(){
	int h,m,s;
  scanf("%d:%d:%d",&h,&m,&s);
	if ((h==12)){
	  printf("PM 12:%02d:%02d\n",m,s);
		return 0;
	}
	if ((h==0)){
		printf("AM 12:%02d:%02d\n",m,s);
		return 0;
	}
	if (h==12){
		printf("PM 12:%02d:%02d\n",m,s);
		return 0;
	}
	if (h>12){
		printf("PM %02d:%02d:%02d\n",h-12,m,s);
	}else {
		printf("AM %02d:%02d:%02d\n",h,m,s);
	}
	return 0;
}
