#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#define MAXN 60005
#define MAXK 5
struct node
{
	int l,r,fix,d;
};
struct Treap
{
	node p[MAXN];
	int size,root;
	void init(){
		size=root=-1;
	}
	void rot_l(int &x){
		int y=p[x].r;
		p[x].r=p[y].l;
		p[y].l=x;
		x=y;
	}
	void rot_r(int &x){
		int y=p[x].l;
		p[x].l=p[y].r;
		p[y].r=x;
		x=y;
	}
	void insert(int &k,int d){
		if (k==-1)
		{
			k=++size;
			p[k].l=p[k].r=-1;
			p[k].d=d;
			p[k].fix=rand();
			return;
		}
		if (d<p[k].d)
		{
			insert(p[k].l,d);
			if (p[p[k].l].fix>p[k].fix)
			{
				rot_r(k);
			}
		}else{
			insert(p[k].r,d);
			if (p[p[k].r].fix>p[k].fix)
			{
				rot_l(k);
			}
		}
	}
	void remove(int &k,int d){
		if (k==-1) return ;
		if (d<p[k].d) remove(p[k].l,d);
		else if (d>p[k].d) remove(p[k].r,d);
		else
		{
			if (p[k].l==-1 && p[k].r==-1)
			{
				k=-1;
			}else{
				if (p[k].l==-1) k=p[k].r;
				else if (p[k].r==-1) k=p[k].l;
				else
				{
					if (p[p[k].l].fix<p[p[k].r].fix)
					{
						rot_l(k);
						remove(p[k].l,d);
					}else{
						rot_r(k);
						remove(p[k].r,d);
					}
				}
			}
		}
	}
	int min(){
		int k=root;
		while (p[k].l!=-1)
		{
			k=p[k].l;
		}
		return p[k].d;
	}
	int max(){
		int k=root;
		while (p[k].r!=-1)
		{
			k=p[k].r;
		}
		return p[k].d;
	}
}T[1<<5];
int N,K;
int P[MAXN][MAXK];
int main()
{
	while (~scanf("%d%d",&N,&K))
	{
		for (int i=0;i<(1<<K);++i)
		{
			T[i].init();
		}
		memset(P,0,sizeof(P));
		for (int i=0;i<N;++i)
		{
			int Od;
			scanf("%d",&Od);
			if (Od==0)
			{
				for (int j=0;j<K;++j)
				{
					scanf("%d",&P[i][j]);
				}
				for (int Sta=0;Sta<(1<<K);++Sta)
				{
					int Tmp=0;
					for (int j=0;j<K;++j)
					{
						if (Sta&(1<<j))
						{
							Tmp-=P[i][j];
						}else Tmp+=P[i][j];
					}
					T[Sta].insert(T[Sta].root,Tmp);
				}
			}else{
				int p;scanf("%d",&p);p--;
				for (int Sta=0;Sta<(1<<K);++Sta)
				{
					int Tmp=0;
					for (int j=0;j<K;++j)
					{
						if (Sta&(1<<j))
						{
							Tmp-=P[p][j];
						}else Tmp+=P[p][j];
					}
					T[Sta].remove(T[Sta].root,Tmp);
				}
			}
			int Ans=0;
			for (int Sta=0;Sta<=(1<<(K-1));++Sta)
			{
				int Tmp=T[Sta].max()-T[Sta].min();
				if (Tmp>Ans) Ans=Tmp;
			}
			printf("%d\n",Ans);
		}
	}
	return 0;
}
