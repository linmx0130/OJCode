#include <cstdio>
int f[25][25][25];
int main(){
    for (int a=0;a<=20;++a){
        for (int b=0;b<=20;++b){
            for (int c=0;c<=20;++c){
                if ((!a)||(!b)||(!c)) {f[a][b][c]=1;continue;}
                if ((a<b)&&(b<c)) {f[a][b][c]=f[a][b][c-1]+f[a][b-1][c-1]-f[a][b-1][c];continue;}
                f[a][b][c]=f[a-1][b][c]+f[a-1][b-1][c]+f[a-1][b][c-1]-f[a-1][b-1][c-1];
            }
        }
    }
    while (1){
          int a,b,c;
          scanf("%d%d%d",&a,&b,&c);
          if ((a==-1)&&(b==-1)&&(c==-1)) return 0;
          printf("w(%d, %d, %d) = ",a,b,c);
          if ((a<=0)||(b<=0)||(c<=0)) {printf("%d\n",f[0][0][0]);continue;}
          if ((a>20)||(b>20)||(c>20)) {printf("%d\n",f[20][20][20]);continue;}
          printf("%d\n",f[a][b][c]);
    }
}
