#include <cstdio>
char c;
bool Sh;
int main(){
	Sh=1;
	for (;~scanf("%c",&c);){
		if (Sh){
			if ((c>='A')&&(c<='Z')){
				Sh=0;
			}
		}else{
			if ((c>='A')&&(c<='Z')){
				c+=32;
			}
			if ((c=='!')||(c=='?')||(c=='.')){
				Sh=1;
			}
		}
		printf("%c",c);
	}
	return 0;
}
