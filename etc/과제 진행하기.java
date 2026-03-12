import java.util.*;

class Solution {
    public String[] solution(String[][] plans) {
        
        
        // mp[start_time] = name;
        HashMap<Integer, String> nameMap = new HashMap<Integer, String>();
        HashMap<Integer, Integer> remainMap = new HashMap<Integer, Integer>();
        
        // pq 시간순 정렬
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        
        for (int i = 0; i < plans.length; i++) {
            String[] plan = plans[i];
            String strTime = plan[1];
            String[] splitTime = strTime.split(":");
            
            // 시작시간은 분으로 변환
            // time = hour * 60 + min;
            int startTime = Integer.parseInt(splitTime[0]) * 60 + Integer.parseInt(splitTime[1]);
            
            nameMap.put(startTime, plan[0]);
            remainMap.put(startTime, Integer.parseInt(plan[2]));
            pq.add(startTime);
        }
        
        // stack 못 끝낸 과제 저장
        Stack<Integer> st = new Stack<>();
        Queue<Integer> ansQ = new LinkedList<>();
        
        int cur = -1;
        while (!pq.isEmpty()) {
            // System.out.println("here~");
            
            // cur = pq에서 꺼낸 새로운 작업
            cur = pq.poll();
            // System.out.println("cur: " + nameMap.get(cur));
            int remain = remainMap.get(cur);
            
//             // cur 끝나는 시간과 다음 작업 시작 시간 비교
            if (pq.isEmpty()) {
                ansQ.add(cur);
                break;
            }
            int next = pq.peek();
            
            if (cur + remain == next) {
            // 1. cur_end == next_start -> cur을 answer
                ansQ.add(cur);
                cur = next;
            } else if (cur + remain > next) {
            // 2. cur_end > next_start -> 작업하다 남은 시간과 함께 stack에 저장
                int diff = cur + remain - next;
                st.push(cur);
                // System.out.println("st.push: " + nameMap.get(cur));
                remainMap.put(cur, diff);
                cur = next;                
            } else {
            // 3. cur_end < next_start
                
            // 3-1. cur을 answer
                ansQ.add(cur);
            // 3-2. 중간에 빈 시간만큼 stack에서 꺼내서 마저 작업
                int diff = next - cur - remain;
                while (!st.isEmpty()) {
                    int re = st.pop();
                    // System.out.println("re: " + nameMap.get(re));
                    int reRemain = remainMap.get(re);
                    if (reRemain == diff) {
                        ansQ.add(re);
                        remainMap.put(re, 0);
                        break;
                    } else if (reRemain > diff) {
                        st.push(re);
                        // System.out.println("st.push: " + nameMap.get(re));
                        remainMap.put(re, reRemain - diff);
                        break;
                    } else {
                        diff -= reRemain;
                        ansQ.add(re);
                        remainMap.put(re, 0);
                        continue;
                    }
                }
            // 3-3. 꺼낸 작업 마무리되면 answer

            }
            
        }
        
        while (!st.isEmpty()) {
            ansQ.add(st.pop());
        }
        
        // System.out.println("ansQ.size() == " + ansQ.size());
        String[] answer = new String[ansQ.size()];
        for (int i = 0; i < answer.length; i++) {
            int remain = ansQ.poll();
            String name = nameMap.get(remain);
            answer[i] = name;
        }
        return answer; 
    }
}