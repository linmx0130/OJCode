#include <cstring>
#include <cstdio>
#define MAXHASH 300000
char name[35];
int n,m;
int score[10002];
int Head[MAXHASH],Htot,V[10002],Pre[10002];
char Name[10002][35];
inline int hash(char *s){
	unsigned int seed=131;
	unsigned int hash=0;
	while (*s){
		hash=hash*seed+(*s++);
	}
	return hash%MAXHASH;
}
int Hash(char *s){
	int k=hash(s);
	if (!Head[k]){
		Head[k]=++Htot;
		strcpy(Name[Htot],s);
		return Htot;
	}
	for (int p=Head[k];p;p=Pre[p]){
		if (!(strcmp(s,Name[p]))){
			return p;
		}
	}
	++Htot;
	strcpy(Name[Htot],s);
	Pre[Htot]=Head[k];
	Head[k]=Htot;
	return Htot;
}
int LiMing;
int main(){
	scanf("%d\n",&n);
	for (int i=1;i<=n;++i){
		gets(name);
		int k=Hash(name);
		if (!strcmp(name,"Li Ming")){
			LiMing=i;
		}
	}
	scanf("%d",&m);
	for (int i=1;i<=m;++i){
		for (int j=1;j<=n;++j){
			int k,t;
			scanf("%d",&t);
			gets(name);
			score[Hash(name+1)]+=t;
		}
		int ans=0;
		for (int j=1;j<=n;++j){
			if (score[j]>score[LiMing]) ans++;
		}
		printf("%d\n",ans+1);
	}
	return 0;
}
