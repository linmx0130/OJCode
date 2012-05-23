#include <cstdio>
#include <cctype>
char s[102];
int ctot[26];
bool zhi(int x){
	if (x==1)return 0;
	if (!x)return 0;
	for (int i=2;i<=x-1;++i){
		if (x%i==0) return 0;
	}
	return 1;
}
int main(){
	gets(s);
	int max=0,min=0x7fffffff;
	for (char *c=s;*c;c++){
		if (isupper(*c)) *c=*c-'A'+'a';
		ctot[*c-'a']++;
	}
	for (int i=0;i<26;++i){
		if (ctot[i]){
			if (ctot[i]>max) max=ctot[i];
			if (ctot[i]<min) min=ctot[i];
		}
	}
	if (zhi(max-min)){
		printf("Lucky Word\n%d\n",max-min);
	}else {
		printf("No Answer\n0\n");
	}
	return 0;
}

