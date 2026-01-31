class Solution {
    public int solution(int[] players, int m, int k) {
        
        // int[24] 시간별 증설된 서버의 수
        int[] servers = new int[24];
        // int 증설 횟수
        int ans = 0;
        
        for (int i = 0; i < players.length; i++) {
            // 현재 감당 가능한 이용자수 < 실제 이용자수 이면 증설
            int need = players[i] / m;
            if (servers[i] < need) {
                int add = need - servers[i];
                ans += add;
                for (int j = 0; j < k; j++) {
                    if (i + j >= servers.length) break;
                    servers[i + j] += add;
                }
            }
        }
        
        return ans;
    }
}