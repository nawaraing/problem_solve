import java.util.*;

class Solution {
    public int[][] solution(int[][] data, String ext, int val_ext, String sort_by) {
        
        // ext 조건에 따라 idx 매치
        HashMap<String, Integer> mp = new HashMap<>();
        mp.put("code", 0);
        mp.put("date", 1);
        mp.put("maximum", 2);
        mp.put("remain", 3);
        
        // pq 준비 sortby 기준으로 정렬 하도록
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
            return a[mp.get(sort_by)] - b[mp.get(sort_by)];
        });

        for (int i = 0; i < data.length; i++) {
            // 해당 값 아래면 pq에 넣기
            if (data[i][mp.get(ext)] < val_ext) {
                pq.add(data[i]);
            }
        }
        
        // pq를 반환할 수 있게 만들기
        int[][] ans = new int[pq.size()][4];
        int idx = 0;
        while (!pq.isEmpty()) {
            ans[idx] = pq.poll();
            idx++;
        }
        
        return ans;
    }
}