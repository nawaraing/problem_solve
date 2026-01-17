package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p11050 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = br.readLine().split(" ");
        int n = Integer.parseInt(inputs[0]);
        int k = Integer.parseInt(inputs[1]);

        int val = 1;
        for (int i = 1; i <= n; i++) {
            val *= i;
        }
        for (int i = 1; i <= k; i++) {
            val /= i;
        }
        for (int i = 1; i <= n - k; i++) {
            val /= i;
        }

        System.out.println(val);
    }
}