#include <cstdio>
int x1,y1,x2,y2,w,h;
struct STR{
	int x1,y1,x2,y2;
};
int main(){
	scanf("%d %d %d %d",&x1,&y1,&w,&h);
	struct STR A;
	A.x1=x1;A.y1=y1;A.x2=x1+w;A.y2=y1+h;
	scanf("%d %d %d %d",&x1,&y1,&w,&h);
	struct STR B;
	B.x1=x1;B.y1=y1;B.x2=x1+w;B.y2=y1+h;
	if ((B.x1==A.x1)&&(B.x2==A.x2)&&(B.y1<A.y1)&&(B.y2>A.y2)){
		printf("Yes\n");return 0;
	}
	if ((B.y1==A.y1)&&(B.y2==A.y2)&&(B.x1<A.x1)&&(B.x2>A.x2)){
		printf("Yes\n");return 0;
	}

	if (B.x1==A.x2){
		printf("No\n");
		return 0;
	}
	if (B.x2==A.x1){
		printf("No\n");
		return 0;
	}
	if (B.y2==A.y1){
		printf("No\n");
		return 0;
	}
	if (B.y1==A.y2){
		printf("No\n");
		return 0;
	}
	if ((B.x1<=A.x1)&&(B.x2>=A.x1)&&(A.y1<=B.y1)&&(A.y2>=B.y1)){
		printf("Yes\n");return 0;
	}
	if ((B.x1<=A.x1)&&(B.x2>=A.x1)&&(A.y1<=B.y2)&&(A.y2>=B.y2)){
		printf("Yes\n");return 0;
	}
	if ((B.x1<=A.x2)&&(B.x2>=A.x2)&&(A.y1<=B.y1)&&(A.y2>=B.y1)){
		printf("Yes\n");return 0;
	}
	if ((B.x1<=A.x2)&&(B.x2>=A.x2)&&(A.y1<=B.y2)&&(A.y2>=B.y2)){
		printf("Yes\n");return 0;
	}
	if ((A.x1<=B.x1)&&(A.x2>=B.x1)&&(A.y1<=B.y1)&&(A.y2>=B.y2)){
		printf("Yes\n");return 0;
	}
	if ((B.x1<=A.x1)&&(B.x2>=A.x1)&&(B.y1<=A.y1)&&(B.y2>=A.y2)){
		printf("Yes\n");return 0;
	}
	
	printf("No\n");
	return 0;

}
