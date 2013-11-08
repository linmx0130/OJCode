/* UVa 102
   By Sweetdumplings
*/
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
struct BinType
{
	int B,G,C;
}Bin[3];
int main()
{
	while (scanf("%d%d%d",&Bin[0].B,&Bin[0].G,&Bin[0].C)!=EOF)
	{
		scanf("%d%d%d",&Bin[1].B,&Bin[1].G,&Bin[1].C)!=EOF;
		scanf("%d%d%d",&Bin[2].B,&Bin[2].G,&Bin[2].C)!=EOF;
		string Ans="";
		int AnsB=0x7fffffff;
		//BCG;
		int Tmp=0;
		Tmp=Bin[1].B+Bin[2].B+Bin[0].C+Bin[2].C+Bin[0].G+Bin[1].G;
		if (Tmp<AnsB)
		{
			AnsB=Tmp;
			Ans="BCG";
		}
		//BGC;
		Tmp=0;
		Tmp=Bin[1].B+Bin[2].B+Bin[0].C+Bin[1].C+Bin[0].G+Bin[2].G;
		if (Tmp<AnsB)
		{
			AnsB=Tmp;
			Ans="BGC";
		}
		//CBG;
		Tmp=0;
		Tmp=Bin[0].B+Bin[2].B+Bin[1].C+Bin[2].C+Bin[0].G+Bin[1].G;
		if (Tmp<AnsB)
		{
			AnsB=Tmp;
			Ans="CBG";
		}
		//CGB;
		Tmp=0;
		Tmp=Bin[1].B+Bin[0].B+Bin[1].C+Bin[2].C+Bin[0].G+Bin[2].G;
		if (Tmp<AnsB)
		{
			AnsB=Tmp;
			Ans="CGB";
		}
		//GBC;
		Tmp=0;
		Tmp=Bin[0].B+Bin[2].B+Bin[0].C+Bin[1].C+Bin[2].G+Bin[1].G;
		if (Tmp<AnsB)
		{
			AnsB=Tmp;
			Ans="GBC";
		}
		//GCB;
		Tmp=0;
		Tmp=Bin[1].B+Bin[0].B+Bin[0].C+Bin[2].C+Bin[2].G+Bin[1].G;
		if (Tmp<AnsB)
		{
			AnsB=Tmp;
			Ans="GCB";
		}
		printf("%s %d\n",Ans.c_str(),AnsB);
	};
	return 0;
}
