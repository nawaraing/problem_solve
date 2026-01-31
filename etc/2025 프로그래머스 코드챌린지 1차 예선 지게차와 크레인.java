import java.util.*;

class Solution {
    public int solution(String[] storage, String[] requests) {
        
        int n = storage.length;
        int m = storage[0].length();
        
        // String[][] cons 컨테이너들 저장
        // 컨테이너 빼면 ' '
        Character[][] cons = new Character[n][m];
        for (int i = 0; i < storage.length; i++) {
            for (int j = 0; j < storage[0].length(); j++) {
                cons[i][j] = storage[i].charAt(j);
            } 
        }        
        
        
        // for requests
        for (int i = 0 ; i < requests.length; i++) {
            
            // length() == 1이면
            if (requests[i].length() == 1) {
                
                // bfs로 탐색
                // Set s 지울 예정
                Set<int[]> s = new HashSet();
                // Queue q 탐색 예정
                Queue<int[]> q = new LinkedList();
                
                // 컨테이너 외관 중에 빈 것 q.add
                // visit 체크
                boolean[][] visit = new boolean[cons.length][cons[0].length];                
                
                for (int j = 0; j < cons.length; j++) {
                    // 뺄 거 있으면 s.add
                    Character aSide = cons[j][0];
                    Character bSide = cons[j][cons[0].length - 1];
                    if (requests[i].charAt(0) == aSide) {
                        int[] tmp = {j, 0};
                        s.add(tmp);
                    }
                    if (requests[i].charAt(0) == bSide) {
                        int[] tmp = {j, cons[0].length - 1};
                        s.add(tmp);
                    }
                    // 빈 공간 있으면 q.add
                    if (aSide == ' ') {
                        int[] tmp = {j, 0};
                        q.add(tmp);
                    }
                    if (bSide == ' ') {
                        int[] tmp = {j, cons[0].length - 1};
                        q.add(tmp);
                    }
                    visit[j][0] = true;
                    visit[j][cons[0].length - 1] = true;
                }
                for (int j = 0; j < cons[0].length; j++) {
                    // 뺄 거 있으면 s.add
                    Character aSide = cons[0][j];
                    Character bSide = cons[cons.length - 1][j];
                    if (requests[i].charAt(0) == aSide) {
                        int[] tmp = {0, j};
                        s.add(tmp);
                    }
                    if (requests[i].charAt(0) == bSide) {
                        int[] tmp = {cons.length - 1, j};
                        s.add(tmp);
                    }
                    // 빈 공간 있으면 q.add
                    if (aSide == ' ') {
                        int[] tmp = {0, j};
                        q.add(tmp);
                    }
                    if (bSide == ' ') {
                        int[] tmp = {cons.length - 1, j};
                        q.add(tmp);
                    }
                    visit[0][j] = true;
                    visit[cons.length - 1][j] = true;
                }
                
                // while (q)
                while (!q.isEmpty()) {
                    int[] cur = q.poll();
                    int[][] dd = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                    
                    for (int j = 0; j < dd.length; j++) {
                        int nextx = cur[0] + dd[j][0];
                        int nexty = cur[1] + dd[j][1];
                        if (nextx < 0 || nextx >= cons.length) continue;
                        if (nexty < 0 || nexty >= cons[0].length) continue;
                        
                        // 4 사이드 중에 visit 안한것 중에
                        if (visit[nextx][nexty]) continue;
                        visit[nextx][nexty] = true;
                            
                        // 컨테이너가 ' '이면 q.add
                        if (cons[nextx][nexty] == ' ') {
                            int[] tmp = {nextx, nexty};
                            q.add(tmp);
                            continue;
                        }
                        
                        // 지금 찾는게 있으면 s.add
                        if (requests[i].charAt(0) == cons[nextx][nexty]) {
                            int[] tmp = {nextx, nexty};
                            s.add(tmp);
                        }
                    }
                }
                // bfs 끝나고 s에서 꺼내서 cons에 ' ' 저장
                for (int[] xy : s) {
                    cons[xy[0]][xy[1]] = ' ';
                }
            } else {
                // length() == 2이면
                // 2중 for문으로 탐색
                for (int j = 0; j < cons.length; j++) {
                    for (int k = 0; k < cons[0].length; k++) {
                        if (cons[j][k] == requests[i].charAt(0)) {
                            cons[j][k] = ' ';
                        }
                    }
                }                
            }
                
        }
        
        int ans = 0;
        for (int i = 0; i < cons.length; i++) {
            for (int j = 0; j < cons[0].length; j++) {
                if (cons[i][j] != ' ') {
                    ans++;
                }
            }
        }
        
        return ans;
    }
}