import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class p1927 {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try {
            int n = Integer.parseInt(br.readLine());
            PriorityQueue<Integer> pq = new PriorityQueue<>();

            for (int i = 0; i < n; i++) {
                int num = Integer.parseInt(br.readLine());
                if (num == 0) {
                    System.out.println(pq.isEmpty() ? 0 : pq.poll());
                } else {
                    pq.add(num);
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
