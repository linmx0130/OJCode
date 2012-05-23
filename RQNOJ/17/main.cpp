#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 102
#define MAXL 20002
int stone[MAXN],Stone[MAXN];
int f[MAXL];
int isstone[MAXL];
int s,t,l,m;
inline int min(int a,int b){
	return a<b?a:b;
}
int main(){
	scanf("%d%d%d%d",&l,&s,&t,&m);
	int D=s*(s+1)+t+t;
	for (int i=1;i<=m;++i){
		scanf("%d",&stone[i]);
	}
	stone[++m]=l;
	std::sort(stone+1,stone+m+1);
	if (s==t){
		int ans=0;
		for (int i=1;i<=m;++i){
			if (stone[i]%s==0) ans++;
		}
		printf("%d\n",ans);
		return 0;
	}
	for (int i=1;i<=m;++i){
		if (stone[i]-stone[i-1]>D){
			Stone[i]=Stone[i-1]+D;
		}else Stone[i]=Stone[i-1]+stone[i]-stone[i-1];
		isstone[Stone[i]]=1;
	}
	l=Stone[m];
	memset(f,60,sizeof(f));
	f[0]=0;
	for (int i=1;i<=Stone[m];++i){
		for (int j=i-t;j<=i-s;++j){
			if (j<0) continue;
			f[i]=min(f[i],f[j]+isstone[i]);
		}
	}
	int ans=0x7fffffff;
	for (int i=l-t;i<=l;++i){
		ans=min(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}
