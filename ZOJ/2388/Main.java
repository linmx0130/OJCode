import java.util.*;
class Main
{
	public static void main (String args[])
		{
			Scanner cin=new Scanner(System.in);
			int N=cin.nextInt();
			for (;N>0;N--)
			{
				int S=cin.nextInt(),D=cin.nextInt();
				if ((S<D)||((S%2)!=(D%2)))
				{
					System.out.println("impossible");
				}
				else
				{
					int A=(S-D)/2;
					System.out.printf("%d %d\n",S-A,A);
				}
			}
			return ;
		}
};
