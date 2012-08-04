#include <string>
#include <cstring>
#include <iostream>
using namespace std;
string sa,sb;
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
class BigNum{
public:
  int len;
  int num[1002];
  inline void setlen(int x){
    this->len=1000-x;
  }
  inline int getpos(){
    return this->len;
  }
  BigNum(string s){
    this->len=1000;
	memset(this->num,0,sizeof(this->num));
	for (int i=s.size()-1;i>=0;--i){
	  this->num[this->len]=s[i]-'0';
	  this->len--;
	}
  }
  BigNum(){
    this->len=1000;
	memset(this->num,0,sizeof(this->num));
  }
  inline int size(){
    return (1000-this->len);
  }
  void print(){
    for (int i=this->len+1;i<=1000;++i) cout << num[i];
    cout << endl;
  }
  BigNum operator +(BigNum x){
    BigNum ret;
	ret.setlen(MAX(x.size(),this->size()));
	for (int i=1000;i>ret.getpos();--i){
	  ret.num[i]=this->num[i]+x.num[i];
	  if (ret.num[i+1]>=10){
	    ret.num[i+1]-=10;
	    ret.num[i]++;
      }
	}
	if (ret.num[ret.len]>=10) {
	  ret.len--;
	  ret.num[ret.len]=ret.num[ret.len+1]-10;
	  ret.num[ret.len+1]-=10;
	}
    return ret;
  }
};
int main(){
  cin >> sa >> sb;
  BigNum a(sa),b(sb);
  BigNum c;
  c=a+b;
  c.print();
  return 0;
}
