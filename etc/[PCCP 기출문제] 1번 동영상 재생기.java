class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        
        String[] videoSp = video_len.split("[:]");
        int videoSec = Integer.parseInt(videoSp[0]) * 60 + Integer.parseInt(videoSp[1]);
        String[] posSp = pos.split("[:]");
        int posSec = Integer.parseInt(posSp[0]) * 60 + Integer.parseInt(posSp[1]);
        String[] startSp = op_start.split("[:]");
        int startSec = Integer.parseInt(startSp[0]) * 60 + Integer.parseInt(startSp[1]);
        String[] endSp = op_end.split("[:]");
        int endSec = Integer.parseInt(endSp[0]) * 60 + Integer.parseInt(endSp[1]);

        // if pos가 op 사이이면 -> op_end
        if (startSec <= posSec && posSec <= endSec) {
            posSec = endSec;
        }
        
        System.out.println("posSec: " + posSec);
        for (int i = 0; i < commands.length; i++) {
            // 커맨드 작업
            if (commands[i].equals("next")) {
                posSec += 10;
            } else {
                posSec -= 10;
            }
            System.out.println("posSec: " + posSec);
            
            // 위치 조정
            //  1. 영상의 시작점이거나 끝점이거나
            //  2. op 사이에 있거나
            if (posSec < 0) posSec = 0;
            else if (posSec >= videoSec) posSec = videoSec;
            
            if (startSec <= posSec && posSec <= endSec) posSec = endSec;
        }
        
        // String posHour = (posSec / 60) + "";
        // if ((posSec / 60) < 10) posHour = "0" + posHour;
        // String posMin = (posSec % 60) + "";
        // if ((posSec % 60) < 10) posMin = "0" + posMin;
        // return posHour + ":" + posMin;
        
        return String.format("%02d:%02d", (posSec / 60), (posSec % 60));
        
    }
}