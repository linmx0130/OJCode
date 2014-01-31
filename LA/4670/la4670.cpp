#include <cstdio>
#include <cstring>
#include <cstdlib>
#define CHAR_SET_SIZE 26
#define MAXN 155
#define MAXL 1000006
int N;
struct Node
{
	Node *fail;
	Node *child[CHAR_SET_SIZE];
	int point;
	Node(){
		fail=NULL;
		for (int i=0;i<CHAR_SET_SIZE;++i) child[i]=NULL;
		point=-1;
	};
	~Node(){
		for (int i=0;i<CHAR_SET_SIZE;++i)
		{
			if (child[i]!=NULL) delete child[i];
		}
	};
};
Node *Q[MAXN*CHAR_SET_SIZE*30];
Node *Root;
char S[MAXL];
int Count[MAXN];
char Pattern[MAXN][75];
void Init()
{
	if (Root!=NULL) delete Root;
	Root=new Node;
	memset(Count,0,sizeof(Count));
};
void Insert(char *s,int num)
{
	Node* p=Root;
	for (char *c=s;*c!='\0';++c)
	{
		int t=(*c)-'a';
		if (p->child[t]==NULL) p->child[t]=new Node();
		p=p->child[t];
	}
	p->point=num;
};
void Build_AC()
{
	Node *p;
	int Qh=0,Qt=1;
	Q[1]=Root;
	while (Qh<Qt)
	{
		p=Q[++Qh];
		for (int i=0;i<CHAR_SET_SIZE;++i)
		{
			if (p->child[i]!=NULL)
			{
				Q[++Qt]=p->child[i];
				Node *t=p->fail;
				while (t!=NULL)
				{
					if (t->child[i]!=NULL)
					{
						p->child[i]->fail=t->child[i];
						break;
					}
					t=t->fail;
				}
				if (t==NULL) p->child[i]->fail=Root;
			}
		}
	}
}
void Match()
{
	Node *p=Root;
	for (char *c=S;(*c)!='\0';++c)
	{
		int k=(*c)-'a';
		while (p->child[k]==NULL && p!=Root) p=p->fail;
		if (p->child[k]==NULL) continue;
		p=p->child[k];
		Node *t=p;
		while (t!=Root)
		{
			if (t->point!=-1) Count[t->point]++;
			t=t->fail;
		}
	}
}

void Main()
{
	Init();
	for (int i=0;i<N;++i)
	{
		scanf("%s",Pattern[i]);
		Insert(Pattern[i],i);
	}
	Build_AC();
	scanf("%s",S);
	Match();
	int maxt=0;
	for (int i=1;i<N;++i)
	{
		if (Count[i]>Count[maxt]) maxt=i;
	}
	printf("%d\n",Count[maxt]);
	for (int i=0;i<N;++i)
	{
		if (Count[i]==Count[maxt])
		{
			puts(Pattern[i]);
		}
	}
}
int main()
{
	while (scanf("%d",&N),N)
	{
		Main();
	}
	return 0;
}
