class Solution {
    public int[] solution(int[] seq, int k) {
        
        // 누적합 배열
        int[] sumSeq = new int[seq.length + 1];
        sumSeq[0] = 0;
        for (int i = 0; i < seq.length; i++) {
            sumSeq[i + 1] = sumSeq[i] + seq[i];
        }
        
        // for i는 seq 뒤에서 부터
        // 모든 index는 sumSeq기준
        for (int i = sumSeq.length - 1; i >= 0; i--) {
            // start = 0
            // end = 자기자신만 하는 경우 포함
            int start = 0;
            int end = i - 1;
            while (start <= end) {
                int mid = (start + end) / 2;
                int calcul = sumSeq[i] - sumSeq[mid];
                
                if (calcul == k) {
                    if (seq[mid] == seq[i - 1] && mid > 0) {
                        int j = mid - 1;
                        while (j >= 0) {
                            if (seq[j] != seq[i - 1]) {
                                int[] ans = {j + 1, i - mid + j};
                                return ans;
                            }
                            j--;
                        }
                        int[] ans = {0, i - 1 - mid};
                        return ans;
                    }
                    
                    int[] ans = {mid, i - 1};
                    return ans;
                } else if (calcul > k) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        // while (start <= end)
        // if (end - start)
        // 
        
        return null;
    }
}