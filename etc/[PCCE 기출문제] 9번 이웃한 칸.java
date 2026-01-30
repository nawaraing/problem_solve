class Solution {
    public int solution(String[][] board, int h, int w) {
        
        int[][] dd = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            
            int nextH = h + dd[i][0];
            int nextW = w + dd[i][1];

            if (nextH < 0 || nextH >= board.length) continue;
            if (nextW < 0 || nextW >= board.length) continue;

            if (board[nextH][nextW].equals(board[h][w])) {
                ans++;
                // System.out.println("nextH: " + nextH + "  nextW: " + nextW);
            }
        }
        
        return ans;
    }
}