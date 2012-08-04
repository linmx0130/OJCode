#include <cstdio>
#include <cstring>
#define MAXN 1002
#define MAXQ 1000002
const int dxy[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m;
char c[MAXN][MAXN];
int ans,xx,yy;
int xqueue[MAXQ],yqueue[MAXQ],qt,qh;
bool done[MAXN][MAXN];
inline int strfind(char *s){
	for (int i=0;s[i];++i){
		if (s[i]=='X')return i;
	}
	return -1;
}
inline void input(){
	char s[MAXN];int xxx;
	for (int i=0;i<n;++i){
		scanf("%s",s);
		if (xxx=strfind(s),~xxx){
			xx=i;yy=xxx;
		}
		memcpy(c[i],s,sizeof(c[i]));
	}
}
inline void work(int startx,int starty){
	memset(done,0,sizeof(done));
	qh=0;qt=1;
	ans=0;
	xqueue[1]=startx;
	yqueue[1]=starty;
	done[startx][starty]=1;
	while (qh<qt){
		qh++;if (qh>MAXQ) qh-=MAXQ;
		int x=xqueue[qh];
		int y=yqueue[qh];
		for (int i=0;i<4;++i){
			int nx=x+dxy[i][0],ny=y+dxy[i][1];
			if ((nx<0)||(ny<0)||(nx==n)||(ny==m)) continue;
			if (c[nx][ny]=='#') continue;
			if (done[nx][ny]) continue;
			if (c[nx][ny]=='*') ans++;
			done[nx][ny]=1;
			qt++;if (qt>MAXQ) qt-=MAXQ;
			xqueue[qt]=nx;
			yqueue[qt]=ny;
		}
	}
	printf("%d\n",ans);
}
int main(){
	for (;~scanf("%d %d",&n,&m);){
		input();
		work(xx,yy);
	}
	return 0;
}
