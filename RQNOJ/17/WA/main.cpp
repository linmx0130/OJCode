#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define MAXN 102
using namespace std;
int l,s,t,m;
int stone[MAXN];
map<int ,int> found;
struct Data_t{
	int pos,w;
}d[MAXN*200];
int dtot;
bool cmp(Data_t a,Data_t b){
	return a.pos<b.pos;
}
int f[MAXN*200];
int main(){
	scanf("%d%d%d%d",&l,&s,&t,&m);
	for (int i=1;i<=m;++i){
		scanf("%d",&stone[i]);
	}
	sort(stone+1,stone+m+1);
	int D=s*(s+1)+t+t;
	for (int i=1;i<=m;++i){
		for (int j=stone[i]-D;j<=stone[i]-s;++j){
			if (j<0) continue;
			if (!found[j]){
				d[++dtot].pos=j;
				d[dtot].w=0;
				found[j]=dtot;
			}
		}
		for (int j=stone[i]+s;j<=stone[i]+D;++j){
			if (j>l) continue;
			if (!found[j]){
				d[++dtot].pos=j;
				d[dtot].w=0;
				found[j]=dtot;
			}
		}
		if (!found[stone[i]]){
			d[++dtot].pos=stone[i];
			d[dtot].w=1;
			found[stone[i]]=dtot;
		}else d[found[stone[i]]].w=1;
	}
	sort(d+1,d+dtot+1,cmp);
	if (!found[0]){d[0].pos=0;d[0].w=0;}
	if (!found[l]){d[++dtot].pos=l;d[dtot].w=0;}
	memset(f,60,sizeof(f));
	f[0]=0;
	for (int i=1;i<=dtot;++i){
		for (int j=i-1;j>=0;--j){
			if (d[i].pos-d[j].pos>=D) {f[i]=f[j]+d[i].w;break;}
			if (d[j].w) break;
		}
		for (int j=i-1;j>=0;j--){
			if (d[i].pos-d[j].pos<s) continue;
			if (d[i].pos-d[j].pos>t) break;
			f[i]=min(f[i],f[j]+d[i].w);
		}
	}
	int ans=0x7fffffff;
	for (int i=dtot;i>=0;--i){
		if (d[dtot].pos-d[i].pos>=t) break;
		if (f[i]<ans) ans=f[i];
	}
	printf("%d\n",ans);
	return 0;
}
