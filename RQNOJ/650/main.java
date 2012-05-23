import java.util.*;

public class main{
	public static void main(String ss[]){
		Scanner cin=new Scanner(System.in);
		int n=cin.nextInt();
		int t=0,time=0;
		while (n!=0){
			++t;
			if (((1+t)*t)/2>n){
				n-=t*(t-1)/2;
				time+=t-1;
				t=0;
			}
		}
		System.out.println(time);
	}
}
