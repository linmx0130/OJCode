#include <cstdio>
#include <cstring>
#define MAXN 80002
#define oo 0x7fffffff
int randt=1,seed;
inline int rand(){
	return randt*=seed;
}
inline int abs(int a){
	return a>0?a:-a;
}
inline int min(int a,int b){
	return a<b?a:b;
}
inline int max(int a,int b){
	return a>b?a:b;
}
class Treap{
public:
	int tot,Root,data[MAXN],key[MAXN],left[MAXN],right[MAXN];
	void init(){
		tot=0;
		seed=131;
		key[0]=oo;
		memset(left,0,sizeof(left));
		memset(right,0,sizeof(right));
	}
	void Left_Ratote(int &x){
		int k=right[x];
		right[x]=left[k];
		left[k]=x;
		x=k;
	}
	void Right_Ratote(int &x){
		int k=left[x];
		left[x]=right[k];
		right[k]=x;
		x=k;
	}
	int Insert(int &t,const int k){
		if (!t){
			data[t=++tot]=k;
			return key[t]=rand();
		}
		if (k<data[t]){
			if (Insert(left[t],k)<key[t]){
				Right_Ratote(t);
			}
		}
		else {
			if (Insert(right[t],k)<key[t]){
				Left_Ratote(t);
			}
		}
		return key[t];
	}
	void Delete(int &t,const int k)
	{
		if(!left[t]&&!right[t]){
			if (k==data[t]) t=left[t]=right[t]=key[t]=0;
			tot--;
			return ;
		}
		if (k<data[t]){
			Delete(left[t],k);
			return ;
		}
		if (k>data[t]){
			Delete(right[t],k);
			return ;
		}
		if (key[left[t]]>key[right[t]]){
			Left_Ratote(t);
			Delete(left[t],k);
		}
		else{
			Right_Ratote(t);
			Delete(right[t],k);
		}
	}
	int Next(int t,int k){
		int ret=oo;
		while (1){
			if(data[t]<k){
				if (right[t]) t=right[t];
				else break;
			}
			else {
				ret=min(ret,data[t]);
				if (left[t]){
					t=left[t];
				} else break;
			}
		}
		return ret;
	}
	int Prev(int t,int k){
		int ret=-oo;	
		while (1){
			if (data[t]>k){
				if (left[t]) t=left[t];	
				else break;
			}
			else {
				ret=max(ret,data[t]);
				if (right[t]){
					t=right[t];
				}else break;
			}
			
		}
		return ret;
	}
}t;
void Print(int now){
	if (t.left[now]) Print(t.left[now]);
	printf("%d\n",t.data[now]);
	if (t.right[now]) Print(t.right[now]);
}
int ans;
int main(){
	int left=0;
	int n,o,a,t1,t2,t3,t4,T=0,count=0;
	for (;~scanf("%d",&n);){
		ans=0;
		t.init();
		for (int i=1;i<=n;++i){
			scanf("%d%d",&o,&a);
			if(!o){
				T=count+1;
			}else T=count-1;
			if (abs(T)>abs(count)) {
				t.Insert(t.Root,a);
				count=T;
			}
			else {
				int t1=t.Prev(t.Root,a);
				int t2=t.Next(t.Root,a);
				if (a-t1<=t2-a){
					t.Delete(t.Root,t1);
					ans+=a-t1;
				}
				else {
					t.Delete(t.Root,t2);
					ans+=t2-a;
				}
				count=T;
				if (ans>=1000000) ans-=1000000;
			}
		}
		printf("%d\n",ans);
	}
	return 0;

}
