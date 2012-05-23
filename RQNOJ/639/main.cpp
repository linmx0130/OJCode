#include <cstdio>
typedef struct {
	int left,right,top,bottom;
}REC;
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
#define ABS(a) ((a)>0?(a):-(a))
int main(){
	REC a,b,c;
	scanf("%d %d %d %d",&a.left,&a.bottom,&a.right,&a.top);
	scanf("%d %d %d %d",&b.left,&b.bottom,&b.right,&b.top);
	c.left=MAX(a.left,b.left);
	c.right=MIN(a.right,b.right);
	c.top=MIN(a.top,b.top);
	c.bottom=MAX(a.bottom,b.bottom);
	int Sc;
	if ((c.left>=c.right)||(c.bottom>=c.top)) Sc=0;
	else Sc=((c.right-c.left)*(c.top-c.bottom));
	int Sa=((a.right-a.left)*(a.top-a.bottom));
	int Sb=((b.right-b.left)*(b.top-b.bottom));
	if (Sc<0)Sc=0;
	int S1=Sc;
	int S2=Sa+Sb-2*Sc;
	int S3=100*100-S2-S1;
	printf("%d %d %d\n",S1,S2,S3);
	return 0;
}
