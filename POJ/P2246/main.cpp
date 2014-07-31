#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
struct Matrix
{
	int x,y;
	int Ans;
	Matrix operator* (const Matrix &t)
	{
		Matrix ret;
		if ((y!=t.x) || (t.Ans==-1) || (Ans==-1))
		{
			ret.x=ret.y=ret.Ans=-1;
			return ret;
		}
		ret.x=x;
		ret.y=t.y;
		ret.Ans=Ans+t.Ans+x*y*t.y;
		return ret;
	}
}M[30];
int N;
char Buf[1000];
Matrix DealExp(int L,int R)
{
	if (L==R) return M[Buf[L]-'A'];
	if (Buf[L]=='(') L++; 
	if (Buf[R]==')') R--; 
	if (R-L==1)
	{
		return M[Buf[L]-'A']*M[Buf[R]-'A'];
	}else
	{
		int mid=0;
		if (Buf[L]=='(')
		{
			int Stack=1;
			for (int i=L+1;i<=R;++i) 
			{
				if (Buf[i]=='(') Stack++;
				if (Buf[i]==')')
				{
					if (--Stack==0) {mid=i;break;}
				}
			}
		}
		else mid=L;
		return DealExp(L,mid)*DealExp(mid+1,R);
	}
}
int main()
{
	scanf("%d",&N);
	char Letter[5];
	for (int i=1;i<=N;++i)
	{
		scanf("%s",Letter);
		int d=Letter[0]-'A';
		scanf("%d%d",&M[d].x,&M[d].y);
		M[d].Ans=0;
	}
	for (;scanf("%s",Buf)!=EOF;) 
	{
		Matrix t=DealExp(0,strlen(Buf)-1);
		if (t.Ans!=-1) printf("%d\n",t.Ans);
		else puts("error");
	}
	return 0;
}
