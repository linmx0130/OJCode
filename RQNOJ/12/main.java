import java.util.*;
class main{
	public static void main(String args[]){
		int a[]=new int[10];
		int w=0;
		Scanner cin=new Scanner(System.in);
		for (int i=0;i<10;++i){
			a[i]=cin.nextInt();
		}
		int ans=0;
		w=cin.nextInt()+30;
		for (int i=0;i<10;++i){
			if (w>=a[i]) ans++;
		}
		System.out.println(ans);
	}
}
