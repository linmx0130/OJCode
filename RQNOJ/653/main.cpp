#include <cstdio>
#include <cstring>
char map[55][55];
int n,m;
int ans;
inline int max(int a,int b){
       return a>b?a:b;
}
int search(int x,int y){
    int queuex[2505],queuey[2505];
    queuex[1]=x;queuey[1]=y;
    int qt=1,qh=0;
    int ret=0;
    if (map[x][y]=='R')ret++;
    map[x][y]='#';
    while(qh<qt)
    {
        ++qh;
        int nowx=queuex[qh];
        int nowy=queuey[qh];
        
        int willx=nowx+1;
        int willy=nowy;
        if ((willx!=0)&&(willy!=0)&&(willx<=n)&&(willy<=m))
        if (map[willx][willy]!='#'){
                                    if (map[willx][willy]=='R')ret++;
                                    ++qt;
                                    queuex[qt]=willx;
                                    queuey[qt]=willy; 
                                    map[willx][willy]='#';   
                                    }
        willx=nowx;
        willy=nowy+1;
        if ((willx!=0)&&(willy!=0)&&(willx<=n)&&(willy<=m))
        if (map[willx][willy]!='#'){
                                    if (map[willx][willy]=='R')ret++;
                                    ++qt;
                                    queuex[qt]=willx;
                                    queuey[qt]=willy;   
                                    map[willx][willy]='#';  
                                    }
        willx=nowx-1;
        willy=nowy;
        if ((willx!=0)&&(willy!=0)&&(willx<=n)&&(willy<=m))
        if (map[willx][willy]!='#'){
                                    if (map[willx][willy]=='R')ret++;
                                    ++qt;
                                    queuex[qt]=willx;
                                    queuey[qt]=willy;  
                                    map[willx][willy]='#';   
                                    }
        willx=nowx;
        willy=nowy-1;
        if ((willx!=0)&&(willy!=0)&&(willx<=n)&&(willy<=m))
        if (map[willx][willy]!='#'){
                                    if (map[willx][willy]=='R')ret++;
                                    ++qt;
                                    queuex[qt]=willx;
                                    queuey[qt]=willy;   
                                    map[willx][willy]='#';  
                                    }
    }
    return ret;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;++i){
        scanf("\n");
        for (int j=1;j<=m;++j){
            scanf("%c",&map[i][j]);
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if(map[i][j]!='#');
            ans=max(ans,search(i,j));
        }
    }
    printf("%d\n",ans);
    while(1);
    return 0;
}
