import java.util.*;
public class Main
{
	static Scanner cin;
	static int N;
	static void work()
	{
		String a,b,ra,rb;
		a=cin.next();b=cin.next();
		ra="";rb="";
		int end=0;
		for (int i=0;i<a.length();++i)
		{
			if (a.charAt(i)=='0') end++;
			else break;
		}
		for (int i=a.length()-1;i>=end;--i)
		{
			ra=ra+a.charAt(i);
		}
		end=0;
		for (int i=0;i<b.length();++i)
		{
			if (b.charAt(i)=='0') end++;
			else break;
		}
		for (int i=b.length()-1;i>=end;--i)
		{
			rb=rb+b.charAt(i);
		}
		Scanner sin=new Scanner(ra);
		int ia=sin.nextInt();
		sin=new Scanner(rb);
		int ib=sin.nextInt();
		int sum=ia+ib;
		boolean mark=false;
		while (sum!=0)
		{
			if (sum%10 !=0 || mark)
			{
				System.out.print(sum%10);
				mark=true;
			}
			sum/=10;
		}
		System.out.println("");
	}
	public static void main(String[] args)
	{
		cin=new Scanner(System.in);
		N=cin.nextInt();
		for (int i=1;i<=N;++i) work();
	}
}
