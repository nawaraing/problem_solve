import java.util.*;

class Solution {
    public int solution(int[] mats, String[][] park) {
        
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
            return a - b;
        });
        for (int i = 0; i < mats.length; i++)
            pq.add(mats[i]);
        
        
        int ans = -1;
        for (int i = 0; i < park.length; i++) {
            for (int j = 0; j < park[i].length; j++) {
                if (!park[i][j].equals("-1")) continue;

                
                if (tryMat(park, i, j, pq.peek())) {
                    ans = pq.poll();
                    if (pq.isEmpty()) return ans;
                }
            }
        }        
        
        return ans;
    }
    
    public boolean tryMat(String[][] park, int c, int r, int matSize) {
        for (int i = 0; i < matSize; i++) {
            if (c+i >= park.length) return false;
            
            for (int j = 0; j < matSize; j++) {
                if (r+j >= park[i].length) return false;
                
                if (!park[c+i][r+j].equals("-1")) {
                    return false;
                }
            }
        }
        return true;
    }
}