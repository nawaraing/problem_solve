import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;

public class p11866 {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try {
            String[] input = br.readLine().split(" ");
            int n = Integer.parseInt(input[0]);
            int k = Integer.parseInt(input[1]);

            Queue<Integer> q = new LinkedList<>();
            for (int i = 0; i < n; i++) {
                q.add(i+1);
            }

            System.out.print("<");
            while (!q.isEmpty()) {
                for (int i = 0; i < k; i++) {
                    if (i == k - 1) {
                        System.out.print(q.poll());
                        if (!q.isEmpty()) {
                            System.out.print(", ");
                        }
                    } else {
                        q.add(q.poll());
                    }
                }
            }
            System.out.println(">");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
