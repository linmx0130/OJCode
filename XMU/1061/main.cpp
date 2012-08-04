#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
class MM{
public:
  string name;
  int st,et;
}d[1002];
int n;
void qsort(int l,int r){
  int i=l,j=r,mid=d[(l+r)/2].et;
  class MM k;
  do{
    while (d[i].et<mid) i++;
    while (d[j].et>mid) j--;
    if (i<=j){
      k=d[i];
      d[i]=d[j];
      d[j]=k;
      i++;j--;
    }
  }while (i<=j);
  if (l<j) qsort(l,j);
  if (i<r) qsort(i,r);
}
int main(){
  cin >> n;
  int h,m;
  char tmp[100];
  for (int i=0;i<n;++i){
    cin >>d[i].name;
    scanf("%d:%d",&h,&m);
    d[i].st=h*60+m;
    scanf("%d:%d",&h,&m);
    d[i].et=h*60+m;
  }
  qsort(0,n-1);
  int last=d[0].et;
  int ans=1;
  string anss=d[0].name;
  for (int i=1;i<n;++i){
    if (d[i].st>=last){
      last=d[i].et;
      ans++;
      anss+=" ";
      anss+=d[i].name;
    }
  }
  cout <<ans <<endl;
  cout <<anss<<endl;
}
