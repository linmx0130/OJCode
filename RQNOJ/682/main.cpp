#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#define MAXN 500002
//it control the size of treap
#define oo 0x7fffffff
typedef int Data_t;
//key type, you can choose any type if it support operator<() and operator>()
typedef struct
{
	int l,r,fix,size;
	Data_t key; 
}Node;
inline int max(int a,int b)
{
	return a>b?a:b;
}
class Treap{
public:
	Node p[MAXN];
	int size,root;
	Treap()
	{
		srand(time(0));
		size=root=-1;
	}
	Treap(int rand_seed)
	{
		//if the judge system didn't support time(), you can use this function to initialize the tree.
		srand(rand_seed);
		size=root=-1;
		p[0].fix=-oo;
	}
	void left_rotate(int &x)
	{
		int k=p[x].r;
		p[x].r=p[k].l;
		p[k].l=x;
		p[k].size=p[x].size;
		p[x].size=p[p[x].l].size+p[p[x].r].size+1;
		x=k;
	}
	void right_rotate(int &x)
	{
		int k=p[x].l;
		p[x].l=p[k].r;
		p[k].r=x;
		p[k].size=p[x].size;
		p[x].size=p[p[x].l].size+p[p[x].r].size+1;
		x=k;
	}
	int insert(Data_t d,int &pos)
	{
		if (pos==-1)
		{
			pos=++size;
			p[pos].l=p[pos].r=-1;
			p[pos].key=d;
			p[pos].fix=rand();
			p[pos].size=1;
		}
		else 
		{
			p[pos].size++;
			if (d<p[pos].key)
			{
				if (insert(d,p[pos].l)>p[pos].fix)
				{
					right_rotate(pos);
				}
			}
			else 
			{
				if (insert(d,p[pos].r)>p[pos].fix)
				{
					left_rotate(pos);
				}
			}
		}
		return p[pos].fix;
	}
	void remove(int d,int &pos)
	{
		if ((p[pos].l==p[pos].r)&&(p[pos].l==-1))
		{
			pos=p[pos].l=p[pos].r=p[pos].key=p[pos].fix=p[pos].size=-1;
			return ;
		}
		if (d<p[pos].key) remove(d,p[pos].l),p[pos].size--;
		else if (d>p[pos].key) remove(d,p[pos].r),p[pos].size--;
		else 
		{
			if (p[pos].l==-1) pos=p[pos].r;
			else if(p[pos].r==-1) pos=p[pos].l;
			else if (p[p[pos].l].fix<p[p[pos].r].fix)
			{
				left_rotate(pos);
				remove(d,p[pos].l);
				p[pos].size--;
			}
			else 
			{
				right_rotate(pos);
				remove(d,p[pos].r);
				p[pos].size--;
			}
		}
	}
	int find(int k,int pos)
	{
		if (k==p[p[pos].l].size+1) return p[pos].key;
		if (p[p[pos].l].size>=k) return find(k,p[pos].l);
		return find(k-p[p[pos].l].size-1,p[pos].r);
	}
	void print(int pos)
	{
		//for debug : it will print the sorted data, while the data is int.
		if (p[pos].l!=-1) print(p[pos].l);
		printf("%d:%d\n",p[pos].key,p[pos].fix);
		if (p[pos].r!=-1) print(p[pos].r);
	}
	int depth(int pos)
	{
		//for debug: return the depth of the tree.
		if (pos==-1) return 0;
		return max(depth(p[pos].l),depth(p[pos].r))+1;		
	}
}T;
int now_emp=0,min,left=0,level=0;
int main()
{
	char s[50];
	int x,n;
	for (scanf("%d%d",&n,&min);n;n--)
	{
		scanf("%s",s);
		if (s[0]=='I') 
		{
			scanf("%d",&x);
			if (x<min)
			{
				//left++;
				continue;
			}
			T.insert(x-level,T.root);
			now_emp++;
		}
		if (s[0]=='F')
		{
			scanf("%d",&x);
			if (x>now_emp) puts("-1");
			else printf("%d\n",T.find(now_emp-x+1,T.root)+level);
		}
		if (s[0]=='A')
		{
			scanf("%d",&x);
			level+=x;
		}
		if (s[0]=='S')
		{
			scanf("%d",&x);
			level-=x;
			while (now_emp)
			{
				int tmp=T.find(1,T.root);
				if (tmp+level<min) 
				{
					T.remove(tmp,T.root);
					left++;
					now_emp--;
				}
				else break;
			}
		}
	}
	printf("%d\n",left);
	return 0;
}
