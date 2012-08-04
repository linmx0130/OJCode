#include <cstdio>
struct rec_t{
	int left,right,top,bottom;
};
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
int main(){
	int x,y,w,h;
	scanf("%d %d %d %d",&x,&y,&w,&h);
	struct rec_t a;
	a.left=x;
	a.right=x+w;
	a.bottom=y;
	a.top=y+h;
	scanf("%d %d %d %d",&x,&y,&w,&h);
	struct rec_t b;
	b.left=x;
	b.right=x+w;
	b.bottom=y;
	b.top=y+h;
/*正确做法，无法AC
	struct rec_t c;
	c.left=MAX(a.left,b.left);
	c.right=MIN(a.right,b.right);
	c.top=MAX(a.top,b.top);
	c.bottom=MIN(a.bottom,b.bottom);
	if ((c.left>=c.right)||(c.bottom>=c.top)){
		printf("No\n");
	}
	else printf("Yes\n");

*/
//AC做法
	if ((b.left>=a.right)||(b.bottom>=a.top)||(b.right<=a.left)||(b.top<=a.bottom)){
		printf("No\n");
	}else printf("Yes\n");
	return 0;
}
