#include <cstdio>
int d[10];
char s[20];
int unknow;
int main(){
	gets(s);
	for (int i=0;i<10;++i){
		if (s[i]=='X') d[i]=10;
		else if (s[i]=='?') unknow=i;
		else d[i]=s[i]-'0';
	}
	int will;
	if (unknow!=9) will=9;
	else will=10;
	for (int i=0;i<=will;++i){
		d[unknow]=i;
		int tmp=0;
		for (int j=0;j<10;++j){
			tmp+=d[j]*(10-j);
		}
		if (!(tmp%11)){
			if (i<10) printf("%d\n",i);
			else puts("X");
			return 0;
		}
	}
	puts("-1");
	return 0;
}

