#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#define MAXN 5843
using std::vector;
using std::priority_queue;
using std::greater;
using std::set;
priority_queue <long long ,vector<long long>,greater <long long > > Q;
set<long long> Vis;
long long F[MAXN];
void Print(int i)
{
	if (i==1) {printf("The 1st humble number is %lld.\n",F[i]);return ;}
	if (i==2) {printf("The 2nd humble number is %lld.\n",F[i]);return ;}
	if (i==3) {printf("The 3rd humble number is %lld.\n",F[i]);return ;}
	if (i%100==11) {printf("The %dth humble number is %lld.\n",i,F[i]);return ;}
	if (i%100==12) {printf("The %dth humble number is %lld.\n",i,F[i]);return ;}
	if (i%100==13) {printf("The %dth humble number is %lld.\n",i,F[i]);return ;}
	if (i%10==1){printf("The %dst humble number is %lld.\n",i,F[i]);return ;}
	if (i%10==2){printf("The %dnd humble number is %lld.\n",i,F[i]);return ;}
	if (i%10==3){printf("The %drd humble number is %lld.\n",i,F[i]);return ;}
	printf("The %dth humble number is %lld.\n",i,F[i]);

}
int main()
{
	Q.push(1);
	Vis.insert(1);
	for (int i=1;i<=5842;++i)
	{
		F[i]=Q.top();
		Q.pop();
		if (Vis.find(F[i]*2)==Vis.end()) Q.push(F[i]*2),Vis.insert(F[i]*2);
		if (Vis.find(F[i]*3)==Vis.end()) Q.push(F[i]*3),Vis.insert(F[i]*3);
		if (Vis.find(F[i]*5)==Vis.end()) Q.push(F[i]*5),Vis.insert(F[i]*5);
		if (Vis.find(F[i]*7)==Vis.end()) Q.push(F[i]*7),Vis.insert(F[i]*7);
	}
	int X;
	while (scanf("%d",&X),X!=0)
	{
		Print(X);
	}
	return 0;
}
