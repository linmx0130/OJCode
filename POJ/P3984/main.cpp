#include <cstdio>
const int N=5;
const int dxy[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int maze[N][N];
int queue[10000];
int done[25];
int pre[10000];
void print(int k){
  if (k==1) printf("(0, 0)\n");
	else {
	  print(pre[k]);
		int x=queue[k];
		printf("(%d, %d)\n",x/5,x%5);
	}
}
int main(){
  for (int i=0;i<5;++i){
	  for (int j=0;j<5;++j){
		  scanf("%d",&maze[i][j]);
		}
	}
  queue[1]=0;
	done[0]=1;
	int h=0,t=1;
	while (h<t){
	  ++h;
		int x=queue[h]/5;
		int y=queue[h]%5;
		for (int i=0;i<4;++i){
		  int dx=x+dxy[i][0];
		  int dy=y+dxy[i][1];
			if ((dx==-1)||(dy==-1)||(dx==5)||(dy==5)) continue;
			if (done[dx*5+dy]) continue;
			if (maze[dx][dy]) continue;
			int xx=dx*5+dy;
			queue[++t]=xx;
			done[xx]=1;
			pre[t]=h;
			if (xx==24) {
			  print(t);
			  return 0;
			}
		}
	}
	return 0;
}
