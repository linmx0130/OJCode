#include <cstdio>
#include <cstring>
const int dxy[][2]={{1,0},{0,1},{-1,0},{0,-1}};
char map[6][6];
int n;
bool done[6][6];
char want[20];
int wantlen;
bool search(int x,int y,int now){
	int will=now+1;
	if (will==wantlen) return 1;
	done[x][y]=1;
	for (int i=0;i<4;++i){
		int wx=x+dxy[i][0],wy=y+dxy[i][1];
		if ((wx==0)||(wy==0)||(wx==5)||(wy==5)||done[wx][wy]) {
			continue;
		}
		if (map[wx][wy]==want[will]){
			if (search(wx,wy,will)) {
				return 1;
			}
		}

	}
	done[x][y]=0;
	return 0;
}
int main(){
	for (int i=1;i<=4;++i) scanf("%s",map[i]+1);
	scanf("%d",&n);
	int i,j;
	bool ok;
	for (;n;n--){
		memset(done,0,sizeof(done));
		scanf("%s",want);
		wantlen=strlen(want);
		ok=0;
		for (i=1;i<=4;++i){
			for (j=1;j<=4;++j){
				if (map[i][j]==want[0]) 
					if (search(i,j,0)){
						ok=1;
					}
				if (ok) break;
			}
			if (ok) break;
		}
		printf("%s: ",want);
		if (ok) puts("YES"); else puts("NO");
	}
	return 0;
}
