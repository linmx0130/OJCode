#include <cstdio>
#define K(a) (a+502)
const int dxy[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
struct Q_t{
	int x,y;
}queue[500002];
int map[K(502)][K(502)];
bool g[K(502)][K(502)];
int qh,qt,x,y,n;

int main(){
	scanf("%d %d %d",&x,&y,&n);
	for (int i=1;i<=n;++i){
		int a,b;
		scanf("%d %d",&a,&b);
		g[K(a)][K(b)]=1;
	}
	queue[1].x=0;
	queue[1].y=0;
	g[K(0)][K(0)]=1;
	qt=1;
	while (qh<qt){
		int nx=queue[++qh].x;
		int ny=queue[qh].y;
		for (int i=0;i<4;++i){
			int wx=nx+dxy[i][0];
			int wy=ny+dxy[i][1];
			if ((wx==-501)||(wy==-501)||(wx==500)||(wy==500)) continue;
			if (!g[K(wx)][K(wy)]){
				g[K(wx)][K(wy)]=1;
				queue[++qt].x=wx;
				queue[qt].y=wy;
				map[K(wx)][K(wy)]=map[K(nx)][K(ny)]+1;
				if ((wx==x)&&(wy==y)){
					printf("%d\n",map[K(x)][K(y)]);
					return 0;
				}
			}
		}
	}
	return 0;
}
