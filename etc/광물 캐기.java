import java.util.*;

class Solution {
    public int solution(int[] picks, String[] minerals) {
        // 광물 5개가 한 세트로 곡괭이를 소모함
        
        int pickNum = picks[0] + picks[1] + picks[2];
        int mineralNum = minerals.length;
        // 곡괭이 수 * 5 를 넘어가는 광물은 볼 필요없음
        if (pickNum * 5 < mineralNum) {
            String[] newMinerals = new String[pickNum * 5];
            for (int i = 0; i < pickNum * 5; i++) {
                newMinerals[i] = minerals[i];
            }
            minerals = newMinerals;
        }
        
        int div = minerals.length / 5;
        int mod = minerals.length % 5;
        if (mod != 0) {
            div++;
            // System.out.println("div: " + div);
            
            String[] tmpMinerals = new String[div * 5];
            for (int i = 0; i < minerals.length; i++) {
                tmpMinerals[i] = minerals[i];
            }
            minerals = tmpMinerals;
        }
        
        // 광물 수 / 5 (+1)을 넘어가는 숫자만큼 등급이 낮은 곡괭이를 버림
        // ! 이 작업은 안해도 될 듯
        // ! 대신 비싼 곡괭이부터 사용하는 쪽으로 구현
        
        // 아래와 같이 가중치를 매겨서 묶음 별로 점수를 매김.
        // 점수가 높은 묶음에게 우선적으로 좋은 등급의 곡괭이를 사용
        // diamond 25
        // iron 5
        // stone 1
        int[] mineralPoint = new int[minerals.length];
        for (int i = 0; i < minerals.length; i++) {
            if (minerals[i] == null) {
                mineralPoint[i] = 0;
            } else if (minerals[i].equals("diamond")) {
                mineralPoint[i] = 25;
            } else if (minerals[i].equals("iron")) {
                mineralPoint[i] = 5;
            } else {
                mineralPoint[i] = 1;
            }
        }
        // System.out.println("mineralPoint.length: " + mineralPoint.length);
        // System.out.println("div: " + div);
        
        // pq 점수
        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> {
            return b - a;
        });
        // mp[점수] = 시작 인덱스
        Map<Integer, Integer> mp = new HashMap<>();
        
        for (int i = 0; i < div; i++) {
            int sum = 0;
            int startIdx = i * 5;
            sum += mineralPoint[startIdx];
            sum += mineralPoint[startIdx + 1];
            sum += mineralPoint[startIdx + 2];
            sum += mineralPoint[startIdx + 3];
            sum += mineralPoint[startIdx + 4];
            
            pq.add(sum);
            mp.put(sum, startIdx);
        }
        
        int answer = 0;
        while (!pq.isEmpty()) {
            int sum = pq.poll();
            int idx = mp.get(sum);
            System.out.println("answer: " + answer);
            System.out.println("sum: " + sum);
            for (int i = 0; i < 5; i++) {
                int point = mineralPoint[idx + i];
                
                if (point == 0) break;
                
                if (picks[0] > 0) {
                    answer++;
                } else if (picks[1] > 0) {
                    if (point == 25) {
                        answer += 5;
                    } else {
                        answer++;
                    }
                } else if (picks[2] > 0) {
                    answer += point;
                }
            }
            if (picks[0] > 0) {
                picks[0]--;
            } else if (picks[1] > 0) {
                picks[1]--;
            } else {
                picks[2]--;
            }
        }
        
        return answer;
    }
}