import java.time.LocalDate;
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        
        String[] sp = today.split("[.]");
        LocalDate todayDate = LocalDate.of(Integer.parseInt(sp[0]), Integer.parseInt(sp[1]), Integer.parseInt(sp[2]));
        // System.out.println("todayDate: " + todayDate);
        
        Map<String, Integer> termMap = new HashMap<String, Integer>();
        for (int i = 0; i < terms.length; i++) {
            String[] spTerm = terms[i].split(" ");
            termMap.put(spTerm[0], Integer.parseInt(spTerm[1]));
        }

        List<Integer> result = new ArrayList<Integer>();
        
        for (int i = 0; i < privacies.length; i++) {
            String[] spPri = privacies[i].split("[. ]");
            LocalDate curDate = LocalDate.of(Integer.parseInt(spPri[0]), Integer.parseInt(spPri[1]), Integer.parseInt(spPri[2]));
            LocalDate delDate = curDate.plusMonths(termMap.get(spPri[3]));
            // System.out.println("delDate: " + delDate);
            if (delDate.isBefore(todayDate) || delDate.isEqual(todayDate)) {
                result.add(i+1);
            }
        }

        int[] answer = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            answer[i] = result.get(i);
        }
        
        return answer;
    }
}