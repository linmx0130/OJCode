#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define MAXHash 2000002
#define MAXQ 5000000
unsigned int BKDR(const char *s){
	unsigned int seed=131;
	unsigned int hash=0;
	while (*s){
		hash=hash*seed+(*s++);
	}
	return hash%MAXHash;
}
int hash[MAXHash],pos[MAXHash],Pre[MAXHash],htot;
string queue[MAXQ],rule[6][2];
int ans[MAXQ];
int qt,qh;
bool check(string s,int key){
	int ht=BKDR(s.c_str());
	if (!hash[ht]){
		hash[ht]=++htot;
		pos[htot]=key;
		return 0;
	}
	if (hash[ht]){
		for (int p=hash[ht];p;p=Pre[p]){
			if (queue[p]==s) return 1;
		}
		pos[++htot]=key;
		Pre[htot]=hash[ht];
		hash[ht]=htot;
		return 0;
	}
}
int main(){
//	cout <<(sizeof(queue)+sizeof(hash)+sizeof(ans)+sizeof(rule)+sizeof(pos)+sizeof(Pre))/1024/1024<<endl;

	string source,object;
	cin >>source>>object;
	int rtot=0;
	string tmp;
	while (cin>>tmp){
		rule[rtot][0]=tmp;
		cin >>tmp;
		rule[rtot][1]=tmp;
		++rtot;
	}
	qt=1;
	queue[1]=source;
	if (source==object) {
		cout << 0 <<endl;
		return 0;
	}
	string now;
	while ((qt!=qh)&&(ans[qt]<=10)){
		now=queue[++qh];
		for (int i=0;i<rtot;++i){
			int last=0;
			do{
				int repos=now.find(rule[i][0],last);
				if (~repos){
					queue[++qt]=now;
					queue[qt].replace(repos,rule[i][0].size(),rule[i][1]);
					ans[qt]=ans[qh]+1;
					if (queue[qt]==object){
						cout <<ans[qt]<<endl;
						return 0;
					}
					if (check(queue[qt],qt)){
						--qt;
					}
					last++;
				}
				if (!(~repos)){break;}
			}while(last<now.size());
		}
	}
	cout <<"NO ANSWER!"<<endl;
	return 0;
}
