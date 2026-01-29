import java.util.PriorityQueue;
import java.util.Queue;
import java.util.ArrayDeque;


class Solution {
    public int solution(int[][] info, int n, int m) {
        // 1. A 흔적 많이 남는 거, B 흔적 적게 남는 거 먼저 정렬
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            if (a[0] / a[1] != b[0] / b[1]) {
                return (b[0] / b[1]) - (a[0] / a[1]);
            }
            if (a[0] != b[0]) {
                return b[0] - a[0];
            }
            return a[1] - b[1];
        });
        for (int i = 0; i < info.length; i++) {
            pq.add(info[i]);
        }
        
        // 2. A에게 흔적이 많이 남는 순으로 B가 훔치기
        int a = 0;
        int b = 0;
        Queue<int[]> q = new ArrayDeque<>();
        
        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            
            if (m <= b + cur[1]) {
                q.add(cur);
                continue;
            }
            b += cur[1];
        }
        
        while (!q.isEmpty()) {
            a += q.poll()[0];
        }
        if (a >= n) return -1;
        return a;
        // 3. 만약 B에게 흔적이 많이 남아 훔칠 수 없다면, 그래도 훔칠 거 있는 지 정렬 완전 탐색
        // 4. 남은 거 A가 훔치기
        // 5. 그런데 n보다 남은 거 더한 게 크면 -1

        
    }
}