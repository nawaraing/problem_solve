package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class p2568 {
    static int[] left = new int[500000 + 1];
    static int[] right = new int[500000 + 1];
    static LinkedList<Integer> b_arr = new LinkedList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String[] inputs = br.readLine().split(" ");
            left[Integer.parseInt(inputs[0])] = Integer.parseInt(inputs[1]);
            right[Integer.parseInt(inputs[1])] = Integer.parseInt(inputs[0]);
        }

        int cnt = 0;
        Queue<Integer> ans = new LinkedList<Integer>();
        b_arr.add(0);
        for (int i = 1; i <= 500000; i++) {
            if (left[i] == 0) {
                continue;
            }
            // System.out.println(b_arr.toString());

            if (b_arr.getLast() < left[i]) {
                b_arr.add(left[i]);
            } else {
                int idx = lower_bound(0, b_arr.size() - 1, left[i]);
                ans.add(right[b_arr.get(idx)]);
                b_arr.set(idx, left[i]);
                cnt++;
            }
        }

        System.out.println(cnt);
        for (int i = 0; i < cnt; i++) {
            System.out.println(ans.poll());;
        }
    }

    public static int lower_bound(int start, int end, int find) {
        System.out.printf("start[%d] end[%d] find[%d]\n", start, end, find);
        // 1. 크거나 같으면 된다.
        // 2. 최좌측 값이어야 한다.

        int mid = (start + end) / 2;
        if (b_arr.get(mid) >= find) {
            if (mid > 0 && b_arr.get(mid - 1) >= find) {
                return lower_bound(start, mid - 1, find);
            }
            return mid;
        } else if (b_arr.get(mid) < find) {
            return lower_bound(mid + 1, end, find);
        }
        return 0;
    }
}