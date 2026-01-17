package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p27866 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String s = br.readLine();
        int idx = Integer.parseInt(br.readLine());

        System.out.println(s.charAt(idx - 1));
    }
}