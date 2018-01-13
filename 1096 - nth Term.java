import java.util.Scanner;
 
public class Main {
 
    static int mod = 10007;
 
    static void init(int mat[][], int a, int b) {
        mat[0][0] = a;
        mat[0][2] = b;
        mat[1][0] = 1;
        mat[0][3] = 1;
        mat[2][1] = 1;
        mat[3][3] = 1;
    }
 
    static int[][] multiply_square(int m[][], int n[][]) {
        int res[][] = new int[4][4];
        int i, j, k;
        long sum = 0;
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                for (k = 0; k < 4; k++) {
                     sum += ((m[i][k]) * (n[k][j])) % mod;
                }
                res[i][j] = (int) (sum % mod);
                sum = 0;
            }
        }
        return res;
    }
 
    static int[][] fast_exp(int n, int m[][]) {
        int res[][] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
        while (n > 0) {
            if (n % 2 == 1) {
                res = multiply_square(res, m);
            }
            m = multiply_square(m, m);
            n >>= 1;
        }
        return res;
    }
 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t, i;
        int n, a, b, c;
        t = sc.nextInt();
        for (i = 1; i <= t; i++) {
            n = sc.nextInt();
            a = sc.nextInt();
            b = sc.nextInt();
            c = sc.nextInt();
            if (n <= 2) {
                System.out.println("Case " + i + ": " + 0);
            } else {
                int mat[][] = new int[4][4];
                init(mat, a, b);
                int temp[][] = new int[4][4];
                temp = fast_exp(n - 2, mat);
                int ans = (temp[0][3] * c) % mod;
                System.out.println("Case " + i + ": " + ans);
            }
            System.gc();
        }
    }
}
 
