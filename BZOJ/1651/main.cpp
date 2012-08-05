#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define FA(t) (t>>1)
#define L(t) (t<<1)
#define R(t) ((t<<1)+1)
#define MAXN 50002
int n;
struct DType
{
	int a,b;
}d[MAXN];
class Heap
{
public:
	int d[MAXN],tot;
	void rise(int t)
	{
		while (t>1)
		{
			if (d[t]<d[FA(t)])
			{
				int k=d[t];
				d[t]=d[FA(t)];
				d[FA(t)]=k;
				t=FA(t);
			}else break;
		}
	}
	void sink(int t)
	{
		while (t<=tot)
		{
			int mint=t;
			if (L(t)<=tot) if (d[L(t)]<d[mint]) mint=L(t);
			if (R(t)<=tot) if (d[R(t)]<d[mint]) mint=R(t);
			if (mint==t) break;
			int k=d[t];
			d[t]=d[mint];
			d[mint]=k;
			t=mint;
		}
	}
	void push(int t)
	{
		d[++tot]=t;
		rise(tot);
	}
	void pop()
	{
		d[1]=d[tot--];
		sink(1);
	}
}h;
bool cmp(DType a,DType b)
{return (a.a==b.a)?a.b<b.b:a.a<b.a;}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d",&d[i].a,&d[i].b);
	}
	std::sort(d+1,d+n+1,cmp);
	for (int i=1;i<=n;++i)
	{
		if (h.tot)
		{
			if (h.d[1]>=d[i].a)
			{
				h.push(d[i].b);
			}
			else 
			{
				h.pop();
				h.push(d[i].b);
			}
		}
		else 
		{
			h.push(d[i].b);
		}
	}
	printf("%d\n",h.tot);
	return 0;
}
