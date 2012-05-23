#include <cstdio>
#include <set>
#define oo (~0U>>2)
using namespace std;
set <int>s;
int n,ans,left,a,b;
int main(){
	s.insert(oo);
	s.insert(-oo);
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d%d",&a,&b);
		if (a){
			left--;
			if (left<0) {s.insert(b);continue;}
			set<int>::iterator k=s.lower_bound(b);
			int r=*k-b,l=b-*(--k);//Orz 神丽洁！！！
			if (l<=r) {
				ans+=l;s.erase(k);
			}
			else {
				ans+=r;
				s.erase(++k);
				}
			}
		else {
			left++;
			if (left>0) {s.insert(b);continue;}
			set<int>::iterator k=s.lower_bound(b);
			int r=*k-b,l=b-*(--k);//Orz 神丽洁！！！
			if (l<=r) {
				ans+=l;s.erase(k);
			}
			else {
				ans+=r;
				s.erase(++k);
				}
			}
		ans%=1000000;
	}
	printf("%d\n",ans);
	return 0;
}
