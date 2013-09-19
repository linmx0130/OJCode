import java.util.*;
class Main
{
	private static Scanner cin;
	private static void Main()
		{
			int N=cin.nextInt();
			if (N==0) return ;
			HashMap<String ,Integer> Count=new HashMap <String, Integer>();
			for (int i=1;i<=N;++i)
			{
				String s=cin.next();
				if (Count.containsKey(s))
				{
					Count.put(s,Count.get(s)+1);
				}else
				{
					Count.put(s,1);
				}
			}
			String MaxS="";int Maxint=0;
			for (String s:Count.keySet())
			{
				
				if (Count.containsKey(s))
				{
					if (Count.get(s)>Maxint)
					{
						Maxint=Count.get(s);
						MaxS=s;
					}
				}
			}
			System.out.println(MaxS);
		}
	public static void main(String args[])
		{
			cin=new Scanner(System.in);
			while (cin.hasNextInt())
			{
				Main();
			}
		}
};
