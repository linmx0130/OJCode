import java.util.Scanner;
import java.util.Arrays;
public class Main
{
	private static int[] A;
	private static int N;
	private static void Work()
	{
		boolean[] T=new boolean[105];
		Arrays.fill(T,false);
		int Ans=0;
		Arrays.sort(A,0,N);
		for (int i=0;i<N;++i)
		{
			T[A[i]]=true;
			if ((A[i]%2==0) && (T[A[i]/2]))
			{
				Ans++;
			}
		}
		System.out.println(Ans);
	}
	public static void main(String[] args)
	{
		A=new int[20];
		N=0;
		Scanner cin=new Scanner(System.in);
		while (cin.hasNextInt())
		{
			A[N]=cin.nextInt();
			if (A[N]==-1) return ;
			if (A[N]==0)
			{
				Work();
				N=0;
				continue;
			}
			N++;
		}
	}
}
