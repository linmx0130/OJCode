#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
std::map<char, char> turnMap;
using std::string;
inline bool isSpace(char c){
	return (c==' ' || c=='\t' || c=='\n'|| c=='\r');
}
struct Quilt{
	int height, width;
	char *content;
	Quilt(int h,int w):height(h), width(w){
		content = new char[h*w];
	}
	~Quilt(){
		delete[] content;
	}
	char& c(int i, int j){
		return content[i*width+j];
	}
	void print(){
		for(int i=0;i<height;++i){
			for (int j=0;j<width;++j){
                std::cout << c(i,j);
			}
            std::cout<<std::endl;
		}
	}
};
Quilt A(2,2),B(2,2); 
void init(){
	A.content[0]='/';
	A.content[1]='/';
	A.content[2]='/';
	A.content[3]='+';
	for (int i=0;i<4;++i) B.content[i]='-';
	turnMap['/']='\\';
	turnMap['\\']='/';
	turnMap['+']='+';
	turnMap['-']='|';
	turnMap['|']='-';
}
Quilt* clone(Quilt* q){
	if (q==NULL) return NULL;
	Quilt* ret = new Quilt(q->height, q->width);
	memcpy(ret->content, q->content,sizeof(char)*q->height*q->width);
	return ret;
}
Quilt* turn(Quilt *q){
	if (q==NULL) return NULL;
	Quilt* ret = new Quilt(q->width, q->height);
	for (int i=0;i<q->height;++i){
		for (int j=0;j<q->width;++j){
			ret->c(j,q->height-i-1)=turnMap[q->c(i,j)];
		}
	}
	return ret;
}
Quilt* sew(Quilt *a, Quilt *b){
	if (a==NULL || b==NULL) return NULL;
	if (a->height!=b->height) return NULL;
	Quilt* ret = new Quilt(a->height,a->width+b->width);
	for (int i=0;i<ret->height;++i){
		for (int j=0;j<a->width;++j){
			ret->c(i,j) = a->c(i,j);
		}
		for (int j=0;j<b->width;++j){
			ret->c(i,j+a->width) = b->c(i,j);
		}
	}
	return ret;
} 
bool readCommand(string &buf){
	buf = "";
	char c;
	while ((c=getchar())!=EOF){ 
		if (isSpace(c)) continue;
        else break;
	}
    if (c==EOF) return false;
	buf+=c;
	while ((c=getchar())!=EOF){ 
		if (c==';'){
			return true;
		}
		buf +=c;
	}
	return buf.length()!=0;
}
#define SEW 1
#define TURN 2
#define QUILT_A 3
#define QUILT_B 4
#define ERROR 0
struct Command{
	int type;
	Command *ch1, *ch2;
	Command():ch1(NULL),ch2(NULL),type(0){};
	~Command(){
		if (ch1!=NULL) delete ch1;
		if (ch2!=NULL) delete ch2;
	}
};
string readToken(string& buf){
	while (isSpace(buf[0])){
		buf.erase(0,1);
	}
	//word token
	if ((buf[0]>='a' && buf[0]<='z') || (buf[0]>='A' && buf[0]<='Z')){
		string token = "";
		while ((buf[0]>='a' && buf[0]<='z') || (buf[0]>='A' && buf[0]<='Z')){
			token+=buf[0];
			buf.erase(0,1);
		}
		return token;
	}
	// parathesis and comma
	if (buf[0]=='(' || buf[0]==')' || buf[0]==','){
		string token;
		token+=buf[0];
		buf.erase(0,1);
		return token;
	}
	return "error";
}
int countPartByComma(string buf){
	int c = 0;
	int ret = 1;
	for (int i=0;i<buf.length();++i){
		if (buf[i]=='(') c++;
		if (buf[i]==')') c--;
		if (c==0 && buf[i]==','){
			ret++;
		}
	}
	return ret;
}
void splitByComma(string buf, string& p1, string &p2){
	int c = 0;
	for (int i=0;i<buf.length();++i){
		if (buf[i]=='(') c++;
		if (buf[i]==')') c--;
		if (c==0 && buf[i]==','){
			p1=buf.substr(0,i);
			p2 =buf.substr(i+1,buf.length());
			return;
		}
	}
}
Command* parseCommand(string &buf){
	string token = readToken(buf);
	if (token == "error") return NULL;
	Command* ret = new Command();
	if (token =="sew"){
		ret->type = SEW;
	}
	if (token=="turn"){
		ret->type=TURN;
	}
	if (token=="A"){
		ret->type=QUILT_A;
	}
	if (token=="B"){
		ret->type=QUILT_B;
	}
	if (ret->type == ERROR) return NULL;
	if (ret->type<QUILT_A){
		string p1= readToken(buf);
		if (p1!="(") return NULL;
		while (isSpace(*(buf.end()-1))) buf.erase(buf.end()-1);
		if (*(buf.end()-1) != ')') return NULL;
		buf.erase(buf.end()-1);
		if (ret->type==SEW){
			string part1, part2;
			if (countPartByComma(buf)!=2) return NULL;
			splitByComma(buf, part1, part2);
			ret->ch1 = parseCommand(part1);
			ret->ch2 = parseCommand(part2);
		}else {
			if (countPartByComma(buf)!=1) return NULL;
			ret->ch1 = parseCommand(buf);
		}
	}
    return ret;
}
Quilt * execute(Command* command){
	if (command == NULL) return NULL;
    Quilt *ret, *eax, *ebx;
	switch(command->type){
		case QUILT_A: return clone(&A);
		case QUILT_B: return clone(&B);
		case SEW: 
            eax = execute(command->ch1);
            ebx = execute(command->ch2);
            ret = sew(eax,ebx);
            delete eax;
            delete ebx;
            return ret;
		case TURN: 
            eax = execute(command->ch1);
            ret = turn(eax);
            delete eax;
            return ret;
	}
	return NULL;
}
Quilt* dealWith(string &command){
	Command *c = parseCommand(command);
	Quilt* t= execute(c);
    if (c!=NULL) delete c;
	return t;
}
int main(){
	init();
	Quilt *eax, *ebx;
	string buf;
	int quiltCount = 0;
	while(readCommand(buf)){
		++quiltCount;
        std::cout <<"Quilt "<<quiltCount <<":"<<std::endl;
		Quilt *ans = dealWith(buf); 
		if (ans == NULL) {
            std::cout <<"error"<<std::endl;
		}else{
			ans->print();
		}
        delete ans;
	}
    return 0;
}
