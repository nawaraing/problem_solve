import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class p17608 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        Stack<Integer> st = new Stack<>();
        int max = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            st.push(Integer.parseInt(br.readLine()));
        }
        while (!st.isEmpty()) {
            int cur = st.pop();
            if (cur > max) {
                cnt++;
                max = cur;
            }
        }
        System.out.println(cnt);
    }
}
