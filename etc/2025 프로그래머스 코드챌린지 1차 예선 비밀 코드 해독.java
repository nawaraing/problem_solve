import java.util.*;

// 18:14
class Solution {
    // Set s 이번에 체크할 정수
    Set<Integer> s = new HashSet<>();
    int[][] q;
    int[] a;
    int maxiNum;
    int ansCnt;
    
    public int solution(int n, int[][] question, int[] answer) {

        a = answer;
        q = question;
        maxiNum = n;
        dfs(0, 1);
        
        return ansCnt;
    }
    
    public void dfs(int depth, int num) {
        // if 끝이면 cnt 후에 ans랑 비교
        if (depth == 5) {
            // System.out.println("s.size: " + s.size());
            // for (int e: s) {
            //     System.out.format("%d ", e);
            // }
            // System.out.println();

            boolean isSucc = true;
            for (int i = 0; i < q.length; i++) {
                
                int sameCnt = 0;
                for (int j = 0; j < 5; j++) {
                    if (s.contains(q[i][j])) {
                        sameCnt++;
                    }
                }
                if (sameCnt != a[i]) {
                    isSucc = false;
                    break;
                }
            }
            if (isSucc) {
                // System.out.println("ansCnt++");
                ansCnt++;
            }
            return ;
        }
        
        // for i = num ~ n - (5 - depth)
        for (int i = num; i <= maxiNum - (5 - depth) + 1; i++) {
            s.add(i);
            dfs(depth + 1, i + 1);
            s.remove(i);
        }
    }
}