package baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;

public class p2568_3 {
    static int[] buff = new int[500001];
    static LinkedList<Integer> seq = new LinkedList<>();
    static LinkedList<Integer> aIdx = new LinkedList<>();
    static LinkedList<Integer> curLis = new LinkedList<>();
    static LinkedList<Integer> updateLis = new LinkedList<>();
    static LinkedList<Integer> ans = new LinkedList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String[] inputs = br.readLine().split(" ");
            buff[Integer.parseInt(inputs[0])] = Integer.parseInt(inputs[1]);
        }
        for (int i = 1; i <= 500000; i++) {
            if (buff[i] == 0) continue;
            seq.add(buff[i]);
            aIdx.add(i);
        }
        // System.out.println(seq.toString());
        
        updateLis.add(0);
        for (int cur : seq) {
            if (updateLis.getLast() < cur) {
                updateLis.add(cur);
                curLis = (LinkedList<Integer>)updateLis.clone();
                // System.out.println("curLis: " + curLis.toString());
            } else {
                int idx = lower_bound(0, updateLis.size(), cur);
                updateLis.set(idx, cur);
            }
        }

        curLis.pop();
        // System.out.println("seq: " + seq.toString());
        // System.out.println("curLis: " + curLis.toString());

        for (int i = 0; i < seq.size(); i++) {
            int seqElem = seq.get(i);
            int lisElem = -1;
            if (curLis.size() > 0) {
                lisElem = curLis.peek();
            }

            if (seqElem == lisElem) {
                curLis.pop();
            } else {
                ans.add(aIdx.get(i));
            }
        }
        bw.write(ans.size() + "\n");
        for (int cur : ans) {
            bw.write(cur + "\n");
        }
        bw.flush();
        bw.close();
    }

    /*
     * updateLis를 이진 탐색해서 가장 좌측에 있는 find보다 큰 값의 인덱스를 반환한다.
     * 탐색 범위: [start, end)
     */
    public static int lower_bound(int start, int end, int find) {
        // System.out.printf("start[%d] end[%d] find[%d]\n", start, end, find);
        if (start == end) {
            if (updateLis.get(start) > find) {
                return start;
            } else {
                return start + 1;
            }
        }

        int midIdx = (start + end) / 2;
        int midVal = updateLis.get(midIdx);
        if (midVal == find) { // 들어올 일 없음
            return midIdx;
        } else if (midVal > find) {
            return lower_bound(start, midIdx, find);
        } else {
            return lower_bound(midIdx + 1, end, find);
        }
    }
}