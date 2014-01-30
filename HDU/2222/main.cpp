/* HDU 2222 by Province Third Prize Dog 
 * Jan 30, 2014
 * WTF the data! 
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <utility>
#include <set>
using std::string;
using std::vector;
using std::pair;
using std::set;
using std::make_pair;
#define CHAR_SET_SIZE 26
#define PATTERN_SIZE 52
#define QUERY_SIZE 1000002
#define QSIZE 5000000
#define MAXN 10002
struct node
{
	node *fail;
	node *child[CHAR_SET_SIZE];
	int point,count;
	node(){
		fail=NULL;
		for (int i=0;i<CHAR_SET_SIZE;++i) child[i]=NULL;
		point=-1;
		count=0;
	}
};
node *Q[QSIZE];
node *Root;
void Delete(node *t)
{
	if (t==NULL) return ;
	for (int i=0;i<CHAR_SET_SIZE;++i)
	{
		if (t->child[i]!=NULL) Delete(t->child[i]);
	}
	delete t;
}
void Init()
{
	Delete(Root);
	Root=new node;
}
void Insert(char *s,int num)
{
	node *p=Root;
	for (char *c=s;*c!='\0';++c)
	{
		int t=(*c)-'a';
		if (p->child[t]==NULL)
		{
			p->child[t]=new node;
		}
		p=p->child[t];
		if ((*(c+1))=='\0') p->point=num,p->count++; 
	}
}
void InputPattern()
{
	int N;
	scanf("%d",&N);
	char s[PATTERN_SIZE];
	for (int i=1;i<=N;++i)
	{
		scanf("%s",s);
		Insert(s,i-1);
	}
}
void BuildFailPoint()
{
	int Qh=0,Qt=1;
	Q[1]=Root;
	while (Qh<Qt)
	{
		node *now=Q[++Qh];
		for (int i=0;i<CHAR_SET_SIZE;++i)
		{
			if (now->child[i]!=NULL)
			{
				if (now==Root) now->child[i]->fail=Root;
				else
				{
					node *p=now->fail;
					while (p!=NULL)
					{
						if (p->child[i]!=NULL)
						{
							now->child[i]->fail=p->child[i];
							break;
						}
						p=p->fail;
					}
					if (p==NULL) now->child[i]->fail=Root;
				}
				Q[++Qt]=now->child[i];
			}
		}
	}
}
char QueryString[QUERY_SIZE];
bool Found[MAXN];
int Query()
{
	memset(Found,0,sizeof(Found));
	int Ans=0;
	int Len=strlen(QueryString);
	node *p=Root;
	for (int i=0;i!=Len;++i)
	{
		int index=QueryString[i]-'a';
		while (p->child[index]==NULL && p!=Root) p=p->fail;
		if (p->child[index]==NULL) continue;
		p=p->child[index];
		node *t=p;
		while (t!=Root)
		{
			if (t->point!=-1) 
			if (!Found[t->point])
			{
				Found[t->point]=1;
				Ans+=t->count;
			}
			t=t->fail;
		}
	}
	return Ans;
}
void InputQuery()
{
	scanf("%s",QueryString);
	printf("%d\n",Query());
}
int main()
{
	int T;
	for (scanf("%d",&T);T;T--)
	{
		Init();
		InputPattern();
		BuildFailPoint();
		InputQuery();
	}
	return 0;
}
