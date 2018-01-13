import java.math.BigInteger;
import java.util.Scanner;
 
/**
 *
 * @author mhhrakib
 */
public class Main {
    /*static int GCD(int a, int b) {
        if (b==0)
            return a;
        return GCD(b, a%b);
    }*/
   
    static BigInteger lcm(int arr[], int n) {
        int ans = arr[0];
        BigInteger res = new BigInteger(String.valueOf(ans));
       
        for(int i = 1; i<n; i++) {
            BigInteger x = new BigInteger(String.valueOf(arr[i]));
            BigInteger tmp1 = res.multiply(x);
            BigInteger tmp2 = x.gcd(res);
            res = tmp1.divide(tmp2);
        }
       
        return res;
       
       
    }
   
    public static void main (String []args) {
        Scanner sc = new Scanner(System.in);
        int t,i = 0,j;
        t = sc.nextInt();
        while(i<t) {
            int n;
            n = sc.nextInt();
            int [] arr = new int[n];
            for(j = 0; j<n; j++) {
                arr[j] = sc.nextInt();
            }
            System.out.println("Case "+(i+1)+": "+lcm(arr, n));
            i++;
            System.gc();
        }
    }
}
 
