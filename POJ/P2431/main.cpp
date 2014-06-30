#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <utility>
#include <vector>
using std::priority_queue;
using std::make_pair;
using std::pair;
using std::vector;
vector < pair<int,int> >D;
int N,P,L;
priority_queue <int> Q;
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;++i)
	{
		int a,b;scanf("%d%d",&a,&b);
		D.push_back(make_pair(a,b));
	}
	sort(D.begin(),D.end());
	scanf("%d%d",&P,&L);
	int now=P,point=N-1;
	int Ans=0;
	while (now>0)
	{
		now-=L;
		if(now<=0) break;
		for (;D[point].first>=now;point--)
		{
			Q.push(D[point].second);
		}
		if (now>0 && Q.size()==0) 
		{
			puts("-1");
			return 0;
		}
		L=Q.top();
		Q.pop();
		Ans++;
	}
	printf("%d\n",Ans);
	return 0;
}
