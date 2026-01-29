class Solution {
    public long solution(int cap, int n, int[] del, int[] pic) {
        
        int delIdx = n - 1;
        int picIdx = n - 1;
        long ans = 0;
        
        
        // System.out.println("keep");
        while (delIdx >= 0 || picIdx >= 0) {
            // 1. idx를 각 배열에 0이 아닌 가장 끝 값에 가져다두기
            while (delIdx >= 0) {
                if (del[delIdx] > 0) break;
                delIdx--;
            }
            while (picIdx >= 0) {
                if (pic[picIdx] > 0) break;
                picIdx--;
            }

            // 2. 두 idx 중 멀리 있는 것 2배해서 ans에 넣기
            if (delIdx > picIdx) ans += (delIdx + 1) * 2;
            else ans += (picIdx + 1) * 2;
            
            // System.out.println("ans: " + ans);
            // System.out.println("delIdx: " + delIdx);
            // System.out.print("del: ");
            // for (int i = 0; i < n; i ++) {
            //     System.out.print(del[i] + " ");
            // }
            // System.out.println("\npicIdx: " + picIdx);
            // System.out.print("pic: ");
            // for (int i = 0; i < n; i ++) {
            //     System.out.print(pic[i] + " ");
            // }
            // System.out.println();
            
            
            // 3. cap 만큼 빼기, 부족하다면 idx 당겨서 부족한만큼 더 빼기
            int capCp = cap;
            while (capCp > 0 && delIdx >= 0) {
                if (del[delIdx] > 0) {
                    del[delIdx]--;
                    capCp--;
                } else {
                    delIdx--;
                }
            }
            capCp = cap;
            while (capCp > 0 && picIdx >= 0) {
                if (pic[picIdx] > 0) {
                    pic[picIdx]--;
                    capCp--;
                } else {
                    picIdx--;
                }
            }
        }
        
        return ans;
    }
}