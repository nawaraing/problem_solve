import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p2501 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = br.readLine().split(" ");
        int n = Integer.parseInt(inputs[0]);
        int k = Integer.parseInt(inputs[1]);

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                k--;
                if (k == 0) {
                    System.out.println(i);
                    return;
                }
            }
        }
        System.out.println(0);
    }
 }
