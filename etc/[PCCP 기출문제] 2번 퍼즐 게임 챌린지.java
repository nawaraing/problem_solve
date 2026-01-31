class Solution {
    public int solution(int[] diffs, int[] times, long limit) {
        
        // 가장 높은 diff 찾기
        int maxDiff = 0;
        for (int i = 0; i < diffs.length; i++) {
            if (maxDiff < diffs[i]) {
                maxDiff = diffs[i];
            }
        }
        
        // 0 <= lvl <= maxDiff
        // s = 0
        // e = maxDiff
        int s = 1;
        int e = maxDiff;
        
        while(true) { // 300
            // if 찾으면 break;
            if (s >= e) {
                // System.out.println("finish lvl: " + lvl);
                return s;
            }
            
            
            // 중간 부터 서치
            int cur = (s + e) / 2;
            // System.out.format("s[%d] m[%d] e[%d]\n", s, cur, e);
            long sumTime = 0;
            for (int i = 0; i < diffs.length; i++) { // 300000
                if (cur < diffs[i]) {
                    int prev;
                    if (i == 0) {
                        prev = 0;
                    } else {
                        prev = times[i - 1];
                    }
                    sumTime += (diffs[i] - cur) * (times[i] + prev) + times[i];
                } else {
                    sumTime += times[i];
                }
            }
            
            if (sumTime <= limit) {
                // 성공하면 lvl - (e - lvl) / 2
                e = cur;
                // System.out.println("succ lvl: " + lvl);
            } else {
                // 실패하면 lvl + (e - lvl) / 2
                s = cur + 1;
                // System.out.println("fail lvl: " + lvl);
            }

        }
    }
}