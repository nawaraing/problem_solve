import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p2775 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());

        int[][] apt = new int[15][15];

        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                if (i == 0) {
                    apt[i][j] = j;
                } else if (j == 0) {
                    continue;
                } else if (j == 1) {
                    apt[i][j] = 1;
                } else {
                    apt[i][j] = apt[i - 1][j] + apt[i][j - 1];
                }
            }
        }


        for (int i = 0; i < t; i++) {
            int k = Integer.parseInt(br.readLine());
            int n = Integer.parseInt(br.readLine());

            System.out.println(apt[k][n]);
        }
    }
}
