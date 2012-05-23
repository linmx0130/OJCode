import java.util.*;

public class main{
	public static void main(String s[]){
		int ans=0,anst=0,a,b;
		Scanner cin=new Scanner(System.in);
		for (int i=1;i<=7;++i){
			a=cin.nextInt();
			b=cin.nextInt();
			if (a+b>8){
				if (a+b>ans){
					ans=a+b;
					anst=i;
				}
			}
		}
		System.out.println(anst);
	}
}
