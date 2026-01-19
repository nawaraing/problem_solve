import java.util.Map;
import java.util.TreeMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

class Solution {
    public int[] solution(int[][] edges) {
        // 1. 스타트맵, 엔드맵에 저장
        Map<Integer, List<Integer> > startMap = new TreeMap<>();
        Map<Integer, List<Integer> > endMap = new TreeMap<>();
        
        for (int i = 0; i < edges.length; i++) {
            int start = edges[i][0];
            int end = edges[i][1];
            
            if (startMap.get(start) == null) {
                startMap.put(start, new ArrayList<>());
            }
            if (startMap.get(end) == null) {
                startMap.put(end, new ArrayList<>());
            }
            if (endMap.get(end) == null) {
                endMap.put(end, new ArrayList<>());
            }
            
            List<Integer> startList = startMap.get(start);
            List<Integer> endList = endMap.get(end);
            
            // System.out.println("startList: " + startList);
            // System.out.println("endList: " + endList);
            startList.add(end);
            endList.add(start);
        }
        
        // 1번 테스트
        // for (Integer key : startMap.keySet()) {
        //     System.out.println("key: [" + key + "]");
        //     System.out.println("val: " + startMap.get(key));
        // }
        // for (Integer key : endMap.keySet()) {
        //     System.out.println("key: [" + key + "]");
        //     System.out.println("val: " + endMap.get(key));
        // }
        
        // 2. 생성한 정점 찾기 : 스타트맵 O(n) * 엔드맵 O(log(n))
        // 나가는 간선 2개 이상, 들어오는 간선 0개 -> 생성한 정점
        int makeDot = 0;
        for (Integer start : startMap.keySet()) {
            if (startMap.get(start).size() >= 2 && endMap.get(start) == null) {
                makeDot = start;
                break;
            }
        }
        
        // 3. 각 그래프 형태 찾기 : 스타트맵 O(n)
        //   1) 사용한 간선 표시하면서 순회
        //   2) 나가는 간선이 2개 이상인 정점을 발견하면 8자 모양++
        //   3) 시작점으로 돌아오면 도넛 모양++
        //   4) 시작점으로 안 돌아오면 막대 모야++
        //   5) 시작점이 아니면서 사용한 간선이면 스킵
        int stickCnt = 0;
        int eightCnt = 0;
        int donutCnt = 0;
        
        Set<Integer> used = new HashSet<>();
        used.add(makeDot);
        
        
        for (Integer start : startMap.keySet()) {
            // System.out.println("start: " + start);
            // System.out.println("used: " + used);
            if (used.contains(start)) continue;
            // System.out.println("start: " + start);
            
            // System.out.println();
            
            Integer begin = 0;
            Boolean isBegin = true;

            int curr = start;
            
            int execCnt = 0;
            while (true) {
                // System.out.println("curr: " + curr);
                if (used.contains(curr)) break;
                else used.add(curr);

                if (startMap.get(curr) == null) {
                    startMap.put(curr, new ArrayList<>());
                }
                int endSize = startMap.get(curr).size();
                
                if (endSize == 2) {
                    // System.out.println("eightCnt++");
                    eightCnt++;
                    break;
                } else if (endSize == 1) {
                    int next = startMap.get(curr).get(0);
                    if (next == begin || curr == next) {
                        // System.out.println("donutCnt++");
                        donutCnt++;
                        break;
                    }
                    
                    // 위치 생각좀
                    if (isBegin) {
                        begin = start;
                        isBegin = false;
                    }
                    curr = next;
                    continue;
                } else if (endSize == 0) {
                    // System.out.println("stickCnt++");
                    stickCnt++;
                    break;
                } else {
                    // System.out.println("error: endSize[" + endSize + "]");
                    break;
                }
                
                
            }
            
            
            
        }
        
        int[] answer = {makeDot, donutCnt, stickCnt, eightCnt};
        return answer;
    }
}

// 나가는 간선이 2개 이상인 정점이 있음 -> 8자 모양 그래프
// 나가는 간선이 무조건 1개이고 시작점으로 돌아옴 -> 도넛 모양 그래프
// 나가는 간선이 무조건 1개이고 시작점으로 안 돌아옴 -> 막대 모양 그래프

// 모두 트리맵 read: log(n)
// 자료구조 : 스타트맵
// {간선이 출발하는 정점} : {간선이 도착하는 정점}의 배열

// 자료구조 : 엔드맵
// {간선이 도착하는 정점} : {간선이 출발하는 정점}의 배열

// 자료구조 : 배열
// 이미 사용한 간선 표시