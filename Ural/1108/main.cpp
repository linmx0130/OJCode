#include <cstdio>
#include <cstring>
#define BUF 100002
class BigNum{
public:
	int d[BUF+2],len;
	BigNum(){
		len=BUF;
		memset(d,0,sizeof(d));
	}
	void init(){
		len=BUF;
		memset(d,0,sizeof(d));
	}
	void print1(){
		for (int i=len;i<=BUF;++i){
			printf("%d",d[i]);
		}
		puts("");
	}
	BigNum operator+(int );
	BigNum operator*(const BigNum&);
} k,ret;
BigNum BigNum::operator+(int t){
		ret=*this;
		ret.d[BUF]+=t;
		int i=BUF;
		while (ret.d[i]>=10){
			ret.d[i]-=10;
			ret.d[i-1]++;
			i--;
		}
		if (i<len) len=i;
		return ret;
	}
BigNum BigNum::operator* (const BigNum& b){
		ret.init();
		for (int i=BUF;i>=b.len;i--){
			for (int j=BUF;j>=len;j--){
				ret.d[i-(BUF-j)]+=d[j]*b.d[i];
			}
		}
		for (int i=BUF;i;i--){
			if (ret.d[i]>=10){
				ret.d[i-1]+=ret.d[i]/10;
				ret.d[i]%=10;
			}
		}
		for (int i=0;i<=BUF;++i){
			if (ret.d[i]!=0) {
				ret.len=i;
				break;
			}
		}
		return ret;
	}

int main(){
	int n;
	k.d[BUF]=1;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		(k+1).print1();
		if (i!=n)k=k*(k+1);
	}
	return 0;
}
