import java.io.BufferedReader;
import java.io.InputStreamReader;

public class p30018 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String[] aSites = br.readLine().split(" ");
        String[] bSites = br.readLine().split(" ");
        int diff = 0;

        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(aSites[i]);
            int b = Integer.parseInt(bSites[i]);

            if (a > b) {
                diff += a - b;
            } else {
                diff += b - a;
            }
        }
        System.out.println(diff/2);
    }
}
