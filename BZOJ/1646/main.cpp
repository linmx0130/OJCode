#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 100000
int n,k;
int q[MAXN*20+2],qh,qt;
int dis[MAXN*20+2];
bool found[MAXN+2];
int main()
{
	scanf("%d%d",&n,&k);
	qt=1;
	q[1]=n;
	dis[1]=0;
	if (n==k)
	{
		puts("0");
		return 0;
	}
	while (qh<qt)
	{
		int now=q[++qh];
		if (now*2<=MAXN) if (!found[now*2]) {q[++qt]=now*2;dis[qt]=dis[qh]+1;found[now*2]=1;}
		if (q[qt]==k) {printf("%d\n",dis[qt]);return 0;}

		if (now+1<=MAXN) if (!found[now+1]) {q[++qt]=now+1;dis[qt]=dis[qh]+1;found[now+1]=1;}
		if (q[qt]==k) {printf("%d\n",dis[qt]);return 0;}
		
		if (now-1<=MAXN) if (now-1>=0) if (!found[now-1]) {q[++qt]=now-1;dis[qt]=dis[qh]+1;found[now-1]=1;}
		if (q[qt]==k) {printf("%d\n",dis[qt]);return 0;}
	}

}
