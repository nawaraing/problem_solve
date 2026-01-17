package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p9252 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[][] lcs = new int[1001][1001];

        String s1 = br.readLine();
        String s2 = br.readLine();
        
        for (int i = 0; i <= s1.length(); i++) {
            lcs[i][0] = 0;
        }
        for (int j = 0; j <= s2.length(); j++) {
            lcs[0][j] = 0;
        }
        
        int maxI = 0;
        int maxJ = 0;
        int maxVal = 0;
        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                if (s1.charAt(i) == s2.charAt(j)) {
                    lcs[i + 1][j + 1] = lcs[i][j] + 1;
                } else {
                    if (lcs[i][j + 1] < lcs[i + 1][j]) {
                        lcs[i + 1][j + 1] = lcs[i + 1][j];
                    } else {
                        lcs[i + 1][j + 1] = lcs[i][j + 1];
                    }
                }
                
                if (maxVal < lcs[i + 1][j + 1]) {
                    maxVal = lcs[i + 1][j + 1];
                    maxI = i + 1;
                    maxJ = j + 1;
                }
            }
        }

        int curI = maxI;
        int curJ = maxJ;
        String ans = "";
        while (lcs[curI][curJ] > 0) {
            if (lcs[curI][curJ] == lcs[curI - 1][curJ]) {
                curI--;
            } else if (lcs[curI][curJ] == lcs[curI][curJ - 1]) {
                curJ--;
            } else if (lcs[curI][curJ] == lcs[curI - 1][curJ - 1] + 1) {
                ans = s2.charAt(curJ - 1) + ans;
                curI--;
                curJ--;
            }
        }
        System.out.println(maxVal);
        if (maxVal > 0) {
            System.out.println(ans);
        }
    }
}