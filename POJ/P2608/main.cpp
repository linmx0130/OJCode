#include <iostream>
#include <string>
using namespace std;
int m[256];
int main(){
  m['B']=1;
  m['F']=1;
  m['P']=1;
  m['V']=1;
  m['C']=2;
  m['G']=2;
  m['J']=2;
  m['K']=2;
  m['Q']=2;
  m['S']=2;
  m['X']=2;
  m['Z']=2;
  m['D']=3;
  m['T']=3;
  m['L']=4;
  m['M']=5;
  m['N']=5;
  m['R']=6;
  string str;
  int last=0;
  while (cin >> str){
    last=0;
    for (int i=0;i<str.size();++i){
	  if (!m[str[i]]){
	    last=0;continue;
	  }
	  if (m[str[i]]==last){
	    continue;
	  }
	  last=m[str[i]];
	  cout <<last;
	}
	cout <<endl;
  }
  return 0;
}
