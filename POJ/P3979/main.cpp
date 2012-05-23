#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a,int b){
  int m,n,r;
  m=a;n=b;
  do{
    r=m%n;
	m=n;
	n=r;
  } while(r);
  return m;
}
class fraction{
public:
	int c,p;
	int min;
	fraction(){min=0;};
	fraction(int a,int b){this->c=a;this->p=b;min=0;}
	void print(){
	  if (min) cout <<"-";
	  if (p==1) {
	    cout << c <<endl;
		return;
	  }
	  cout <<this->c << "/" << this->p << endl;
	}
	fraction operator + (fraction d){
	  fraction ret,x,y;
	  x.p=this->p*d.p;
	  x.c=this->c*d.p;
	  y.p=this->p*d.p;
	  y.c=this->p*d.c;
	  ret.c=x.c+y.c;
	  ret.p=x.p;
	  ret.simp();
	  return ret;
	}
	fraction operator - (fraction d){
	  fraction ret,x,y;
	  x.p=this->p*d.p;
	  x.c=this->c*d.p;
	  y.p=this->p*d.p;
	  y.c=this->p*d.c;
	  ret.c=x.c-y.c;
	  ret.p=x.p;
	  ret.simp();
	  return ret;
	}
	void simp(){
	  int x=gcd(this->c,this->p);
	  this->c/=x;
	  this->p/=x;
	  if (this->c<0) {
	    min=1;c=-c;
	  }
	  if (p<0){
	    min=1;
		p=-p;
	  }
	}
};
int main(){
  int a,b,c,d;
  char op;
  for (;~scanf("%d/%d%c%d/%d",&a,&b,&op,&c,&d);){
    fraction x(a,b);
    fraction y(c,d);
    if (op=='+') (x+y).print();
    if (op=='-') (x-y).print();
  }
}
