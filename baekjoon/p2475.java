package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p2475 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] inputs = br.readLine().split(" ");
        int ans = 0;

        for (int i = 0; i < inputs.length; i++) {
            ans += Math.pow(Integer.parseInt(inputs[i]), 2);
        }
        System.out.println(ans % 10);
    }
}