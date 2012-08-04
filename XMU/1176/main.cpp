#include <cstdio>
int n,m;
int map[20][20];
int ans;
const int dxy[8][2]={{1,1},{1,-1},{1,0},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};
void search(int x,int y){
	map[x][y]=0;
	for (int i=0;i<8;++i)
		if (map[x+dxy[i][0]][y+dxy[i][1]]) search(x+dxy[i][0],y+dxy[i][1]);
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			scanf("%d",&map[i][j]);
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;++j){
			if (map[i][j]){
				search(i,j);
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}
