#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using std::string;
int M;
int F[20];
int Fs[20];
string GetTree(int M)
{
	if (M==1) return string("X");
	int N=0;
	for (int i=0;i<18;++i)
	{
		if (M<F[i]) {break;}
		M-=F[i];
		N=i+1;
	}
	int Last=0;
	for (int j=0;j<N;++j)
	{
		Last=j;
		if (M-F[j]*F[N-j-1]<0)
		{
			break;
		}else
		{
			M-=F[j]*F[N-j-1];
		}
	}
	int Ln=Last,Rn=N-Ln-1;
	int Left=Fs[Ln-1]+M/F[Rn];
	int Right=Fs[Rn-1]+M%F[Rn];
	string ret;
	if (Left!=0)
	{
		ret="(";
		ret+=GetTree(Left);
		ret+=')';
	}
	ret+='X';
	if (Right!=0)
	{
		ret+='(';
		ret+=GetTree(Right);
		ret+=')';
	}
	return ret;
}
void Work()
{
	string s=GetTree(M);
	printf("%s\n",s.c_str());
}
void Init()
{
	F[0]=1;F[1]=1;
	Fs[1]=2;
	Fs[0]=1;
	for (int i=2;i<=18;++i)
	{
		for (int j=0;j<i;++j)
		{
			F[i]+=F[j]*F[i-j-1];
		}
		Fs[i]=Fs[i-1]+F[i];

	}
}
int main()
{
	Init();
	while (scanf("%d",&M),M)
	{
		Work();
	}		
	return 0;
}
