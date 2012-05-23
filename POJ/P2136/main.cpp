#include<cstdio>
char s[80];
int tot[27];
int main(){
	int max=0;
	while (~scanf("%s",s)){
		for (char *c=s;*c;c++){
			tot[*c-'A']++;
		}
	}
	for (int i=0;i<26;++i) max=max<tot[i]?tot[i]:max;
	for (int i=max;i;i--){
		for (int j=0;j<26;++j){
			if (i==tot[j]){
				printf("* ");
				tot[j]--;
			}else {
				printf("  ");
			}
		}
		puts("");
	}
	for (char i='A';i<='Z';++i){
		printf("%c ",i);
	}
	puts("");
	return 0;
}
