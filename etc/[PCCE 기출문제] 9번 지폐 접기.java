class Solution {
    public int solution(int[] wallet, int[] bill) {
        
        int ans = 0;
        while (true) {
            
            // wallet에 bill이 들어가는지 체크
            if (bill[0] <= wallet[0] && bill[1] <= wallet[1]) break;
            if (bill[0] <= wallet[1] && bill[1] <= wallet[0]) break;
            
            // 아니면 긴 쪽 접기
            if (bill[0] < bill[1]) {
                bill[1] /= 2;
            } else {
                bill[0] /= 2;
            }
            ans++;
        }
        
        return ans;
    }
}