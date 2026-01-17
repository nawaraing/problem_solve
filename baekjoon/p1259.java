package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p1259 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input;
        while (true) {
            input = br.readLine();
            if (input.equals("0")) {
                break;
            }

            boolean isPalin = true;
            for (int i = 0; i < input.length() / 2; i++) {
                if (input.charAt(i) != input.charAt(input.length() - 1 - i)) {
                    isPalin = false;
                    break;
                }
            }
            if (isPalin) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
    }
}