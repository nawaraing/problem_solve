import java.util.*;

class Solution {
    public String[] solution(String[] players, String[] callings) {

        TreeMap<String, Integer> mp = new TreeMap<>();
        for (int i = 0; i < players.length; i++) {
            mp.put(players[i], i);
        }
        
        String tmp = "";
        for (int i = 0; i < callings.length; i++) {
            int idx = mp.get(callings[i]);
            tmp = players[idx];
            players[idx] = players[idx - 1];
            players[idx - 1] = tmp;
            
            mp.put(players[idx], idx);
            mp.put(players[idx - 1], idx - 1);
        }
        
        
        return players;
    }
}