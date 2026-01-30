import java.util.*;

class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        
        int maxHeal = bandage[0];
        int secHeal = bandage[1];
        int fullHeal = bandage[2];
        
        Queue<int[]> q = new LinkedList<>();
        for (int i = 0; i < attacks.length; i++) {
            q.add(attacks[i]);
        }
        
        // attacks의 마지막 시간 구하기
        int lastTime = attacks[attacks.length - 1][0];
        
        int maxHp = health;
        int curHp = health;
        
        int healCnt = 0;
        
        // for attacks의 마지막 시간까지
        for (int i = 1; i <= lastTime; i++) {
            
            // System.out.println("sec: " + i + "  curHp: " + curHp + "  next: " + q.peek()[0] + "  dmg: " + q.peek()[1]);
            // 공격을 안 당했으면 체력 회복
            if (i != q.peek()[0]) {
                // 연속 회복 카운트
                curHp += secHeal;
                
                healCnt++;
                if (healCnt >= maxHeal) {
                    // 카운트가 풀이면 추가 회복
                    curHp += fullHeal;
                    healCnt = 0;
                }
                // 초과 회복했으면 만땅 체력으로 리셋
                if (curHp > maxHp)
                    curHp = maxHp;
            } else {
                // 공격을 당했으면 체력 감소
                curHp -= q.peek()[1];
                // 체력이 0 이하이면 죽음
                if (curHp <= 0) return -1;

                // 연속 회복 카운트 초기화
                healCnt = 0;
                
                q.poll();
            }
            
        }
        
        return curHp;
    }
}