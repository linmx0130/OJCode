#include <cstdio>
#include <cstring>
#define MAXN 52
int m,n;
int source[MAXN][MAXN];
int high,wide;
int max(int a,int b){
	return a>b?a:b;
}
char cuba[6][8]={"+---+..",
				 "|   |/.",
				 "|   | +",
				 "+---+ |",
				 "./   /|",
		  		 "..+---+"};

char ans[500][500];
void Output();
void init(){
	for (int i=0;i<500;++i){
		for (int j=0;j<500;++j){
			ans[i][j]='.';
		}
	}
}
void Print(int x,int y){
	for (int i=0;i<6;++i){
		for (int j=0;j<7;++j){
			if (cuba[i][j]!='.') ans[x+i][y+j]=cuba[i][j];
		}
	}
//	Output();
//	puts("");
}
void Hall(int line,int num,int x,int y){
	for (int i=1;i<=source[line][num];++i){
		Print(x,y);
		x+=3;
	}
}
void Line(int line,int x,int y){
	for (int i=1;i<=n;++i){
		Hall(line,i,x,y);
		y+=4;
	}
}
void Output(){
	for (int i=high-1;i>=0;--i){
		for (int j=0;j<wide;++j){
			putchar(ans[i][j]);
		}
		puts("");
	}
}
int main(){
	init();
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;++i){
		for (int j=1;j<=n;++j){
			scanf("%d",&source[i][j]);
		}
	}
	int tmp=0;
	for (int i=m;i;--i){
		for (int j=1;j<=n;++j){
			high=max(source[i][j]*3+3+tmp,high);
		}
		tmp+=2;
	}
	wide=n*4+1+2*m;
	
	int startx=2*m,starty=2*m;
	for (int i=1;i<=m;++i) {
		startx-=2;starty-=2;
		Line(i,startx,starty);
	}

	Output();
	return 0;
}
