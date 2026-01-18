import java.util.HashMap;
import java.util.Map;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        // int answer = 0;
        
        Map<String, Map<String, Integer> > giveCntMap = new HashMap<>();
        Map<String, Integer> giveScore = new HashMap<>();
        
        // 초기화
        for (int i = 0; i < friends.length; i++) {
            String f1 = new String(friends[i]);
            
            Map<String, Integer> mp = new HashMap<>();
            for (int j = 0; j < friends.length; j++) {
                String f2 = new String(friends[j]);
                // System.out.println("f1[" + f1 + "] f2[" + f2 + "]");
                
                mp.put(f2, 0);
            }
            
            giveCntMap.put(f1, mp);
            giveScore.put(f1, 0);
        }
        
        // 초기화 확인
        // for (Map.Entry<String, Map<String, Integer> > entry : giveCntMap.entrySet()) {
        //     System.out.println(entry.getKey() + " " + entry.getValue());
        //     // System.out.println("value size: " + entry.getValue().size());
        // }        
        
        for (int i = 0; i < gifts.length; i++) {
            String gift = gifts[i];
            String[] giftSplit = gift.split(" ");
            String giver = giftSplit[0];
            String taker = giftSplit[1];
            // System.out.println("giver[" + giver + "] taker[" + taker + "]");
            
            // 서로 주고 받은 선물 수 계산
            // System.out.println("giver[" + giver + "] " + giveCntMap.get(giver));
            int cnt = giveCntMap.get(giver).get(taker);
            giveCntMap.get(giver).put(taker, cnt + 1);
            
            // 점수표 계산
            int gScore = giveScore.get(giver);
            int tScore = giveScore.get(taker);
            
            giveScore.put(giver, gScore + 1);
            giveScore.put(taker, tScore - 1);
        }
        
        
        int maxi = 0;
        for (int i = 0; i < friends.length; i++) {
        
            // 한명씩 받은 선물 수 계산
            int cnt = 0;
            String friend = friends[i];
            for (int j = 0; j < friends.length; j++) {
                String target = friends[j];
                
                int giveCnt = giveCntMap.get(friend).get(target);
                int takeCnt = giveCntMap.get(target).get(friend);
                // System.out.println("friend[" + friend + "] target[" + target + "]");
                // System.out.println("giveCnt[" + giveCnt + "] takeCnt[" + takeCnt + "]");
                
                if (giveCnt == takeCnt) {
                    // giveScore 비교
                    if (giveScore.get(friend) > giveScore.get(target)) {
                        // System.out.println("friend[" + friend + "] target[" + target + "]");
                        cnt++;
                    }
                } else if (giveCnt > takeCnt) {
                    // System.out.println("friend[" + friend + "] target[" + target + "]");
                    cnt++;
                // } else {
                //     System.out.println("friend[" + friend + "] Score[" + giveScore.get(friend) + "]");
                //     System.out.println("target[" + friend + "] Score[" + giveScore.get(target) + "]");
                //     System.out.println();
                }
            }
            
            if (cnt > maxi) {
                maxi = cnt;
            }
        }
        
        return maxi;
    }
}