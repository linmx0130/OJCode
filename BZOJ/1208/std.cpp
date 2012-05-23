
#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <time.h>

#define InputFileName "Data.in"
#define OutputFileName "Data.out"
#define Max(a, b) (a > b ? a : b)
#define Min(a, b) (a < b ? a : b)

using namespace std;

const int MaxN = 100000, oo = 1000000000;

int n, Count, Key[MaxN], Data[MaxN], Left[MaxN], Right[MaxN], Root, Ans, Total;

inline void LeftRotate(int &t)
{
int k = Right[t];
Right[t] = Left[k];
Left[k] = t;
t = k;
}

inline void RightRotate(int &t)
{
int k = Left[t];
Left[t] = Right[k];
Right[k] = t;
t = k;
}

int Insert(int &t, const int k)
{
if (! t)
{
Data[t = ++Total] = k;
return Key[t] = rand();
}
if (k < Data[t])
{
if (Insert(Left[t], k) < Key[t])
RightRotate(t);
}
else
if (Insert(Right[t], k) < Key[t])
LeftRotate(t);
return Key[t];
}

void Delete(int &t, const int k)
{
if (! Left[t] && ! Right[t])
{
t = Left[t] = Right[t] = Data[t] = Key[t] = 0;
return;
}
if (k < Data[t])
{
Delete(Left[t], k);
return;
}
if (k > Data[t])
{
Delete(Right[t], k);
return;
}
if (Key[Left[t]] > Key[Right[t]])
{
LeftRotate(t);
Delete(Left[t], k);
}
else
{
RightRotate(t);
Delete(Right[t], k);
}
}

inline int Prev(int t, const int k)
{
	int Res = -oo;
	while (1)
		if (Data[t] > k)
		{
			if (Left[t])
			t = Left[t];
			else
			break;
		}
		else
		{
			Res = Max(Res, Data[t]);
			if (Right[t])
				t = Right[t];
			else
				break;
		}
	return Res;
}

inline int Next(int t, const int k)
{
int Res = oo;
while (1)
if (Data[t] < k)
{
if (Right[t])
t = Right[t];
else
break;
}
else
{
Res = Min(Res, Data[t]);
if (Left[t])
t = Left[t];
else
break;
}
return Res;
}

int main()
{

srand(time(0));
Key[0] = oo;
int cmd, k, l, r, t, c;
for (scanf("%d", &n); n; --n)
{
	scanf("%d%d", &cmd, &k);
	cmd ? t = Count+1 : t = Count-1;
	if (abs(t) > abs(Count))
		Insert(Root, k);
	else
	{
		l = Prev(Root, k);
		r = Next(Root, k);
		if (k-l <= r-k)
		{
			c = k-l;
			Delete(Root, l);
		}
		else
		{
			c = r-k;
			Delete(Root, r);
		}
		Ans = (Ans+c) % 1000000;
	}
	Count = t;
}
cout << Ans << endl;
return 0;
} 
