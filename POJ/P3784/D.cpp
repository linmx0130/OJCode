#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;
int Output_Point;
void Output(int d)
{
	Output_Point++;
	if (Output_Point==10)
	{
		printf("%d\n",d);
		Output_Point=0;
	}else
	{
		printf("%d ",d);
	}
}
void Output_end()
{
	Output_Point=0;
	printf("\n");
}
void Main()
{
	priority_queue <int,vector<int>, greater<int> > Big;
	priority_queue <int> Small;
	int N;
	scanf("%d",&N);
	printf("%d ",N);
	scanf("%d",&N);
	printf("%d\n",(N>>1)+1);
	Output_Point=0;
	int tmp;
	scanf("%d",&tmp);
	Small.push(tmp);
	Output(tmp);
	for (int i=2;i<=N;++i)
	{
		scanf("%d",&tmp);
		if (i&1==1)
		{
			if (tmp>=Small.top())
			{
				Big.push(tmp);
				Small.push(Big.top());
				Big.pop();
			}
			else
			{
				Small.push(tmp);
			}
			Output(Small.top());
		}
		else
		{
			if (tmp>=Small.top())
			{
				Big.push(tmp);
			}
			else
			{
				Small.push(tmp);
			}
			if (Big.size()>Small.size())
			{
				Small.push(Big.top());
				Big.pop();
			}
			if (Small.size()>Big.size())
			{
				Big.push(Small.top());
				Small.pop();
			}
		}
	}
	Output_end();
}
int main()
{
	int P;
	scanf("%d",&P);
	for (;P;P--) Main();
	return 0;
}
