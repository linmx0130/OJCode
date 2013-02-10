import java.util.*;
public class Main
{
	public static void main(String args[])
		{
			char To[]={'V','W','X','Y','Z','A',
					   'B','C','D','E','F','G',
					   'H','I','J','K','L','M',
					   'N','O','P','Q','R','S',
					   'T','U'};
			Scanner cin=new Scanner(System.in);
			String Buf;
			Buf=cin.nextLine();
			while (!Buf.equals("ENDOFINPUT"))
			{
				Buf=cin.nextLine();
				for (int i=0;i<Buf.length();++i){
					if (Buf.charAt(i)>='A'&&Buf.charAt(i)<='Z'){
						
						System.out.print(To[(int)(Buf.charAt(i)-'A')]);
					}
					else System.out.print(Buf.charAt(i));
				}
				System.out.println("");
				Buf=cin.nextLine();
				Buf=cin.nextLine();
				
			}
		}
	
			
};
