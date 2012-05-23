#include <cstdio>
#include <cstring>
char To[256];
char s[100];
int main(){
	gets(To);
	gets(s);
	for (char *c=s;*c;c++){
		if ((*c<='z')&&(*c>='a')){
			putchar(To[*c-'a']);
			continue;
		}
		if ((*c<='Z')&&(*c>='A')){
			putchar(To[*c-'A']-'a'+'A');
			continue;
		}
		putchar(*c);
	}
	return 0;
}


