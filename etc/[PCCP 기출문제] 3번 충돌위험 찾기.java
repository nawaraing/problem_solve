import java.util.*;

class Solution {
    public int solution(int[][] points, int[][] routes) {
        
        // Queue[로봇번호] qs route 별로 저장
        Queue<Integer>[] qs = new LinkedList[routes.length];
        for (int i = 0; i < routes.length; i++) {
            qs[i] = new LinkedList<Integer>();
            for (int j = 0; j < routes[i].length; j++) {
                qs[i].add(routes[i][j]);
            }
        }
        
        // String[로봇번호] robots = "2 3"
        String[] robots = new String[routes.length];
        for (int i = 0; i < robots.length; i++) {
            int point = qs[i].peek();
            robots[i] = points[point - 1][0] + " " + points[point - 1][1];
        }
        
        int ans = 0;
        while (true) {
            // 현재 겹치는 갯수 ans += cnt
            Set<String> exist = new HashSet<String>();
            Set<String> warn = new HashSet<String>();
            
            for (int i = 0; i < robots.length; i++) {
                if (robots[i].equals("-1 -1")) continue;
                
                if (exist.contains(robots[i])) {
                    warn.add(robots[i]);
                } else {
                    exist.add(robots[i]);
                }
            }
            ans += warn.size();
            
            // if 모든 qs 가 empty -> break;
            boolean isAllEmpty = true;
            for (int i = 0; i < qs.length; i++) {
                if (!qs[i].isEmpty()) {
                    isAllEmpty = false;
                    break;
                }
            }
            if (isAllEmpty) break;
            
            // cur -> q.peek()로 이동
            for (int i = 0; i < robots.length; i++) {
                if (qs[i].isEmpty()) continue;
                
                String[] robot = robots[i].split("[ ]");
                int curx = Integer.parseInt(robot[0]);
                int cury = Integer.parseInt(robot[1]);
                
                int destPoint = qs[i].peek();
                int destx = points[destPoint - 1][0];
                int desty = points[destPoint - 1][1];
                
                // 이미 도착해있으면 q.poll()하고 다음 경로
                if (destx == curx && desty == cury) {
                    qs[i].poll();
                    if (qs[i].isEmpty()) {
                        robots[i] = "-1 -1";
                        continue;
                    }
                    destPoint = qs[i].peek();
                    destx = points[destPoint - 1][0];
                    desty = points[destPoint - 1][1];
                }
                
                if (destx > curx) {
                    curx++;
                } else if (destx < curx) {
                    curx--;
                } else if (desty > cury) {
                    cury++;
                } else if (desty < cury) {
                    cury--;
                }
                robots[i] = curx + " " + cury;
            }
            
            // 모든 경로가 끝났으면 좌표 -1 -1
        }
        
        return ans;
    }
}