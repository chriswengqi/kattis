package integerlists;

import java.io.*;
import java.util.*;

public class integerlists {
    public static void main(String args[]) throws IOException {

        Kattio io = new Kattio(System.in, System.out);

        int num = io.getInt();

        for (int i = 0; i < num; i++) {
            String s = io.getWord();
            int len = io.getInt();
            String arr = io.getWord();
            String[] strarr = arr.substring(1, arr.length() - 1).split(",");
            
            int start = 0;
            int end = len - 1;
            int front = 0;
            boolean flag = true;

            for (int j = 0; j < s.length(); j++) {
                
                if (s.charAt(j) == 'R') {
                    front = 1 - front;
                } else if (s.charAt(j) == 'D') {
                    if (start > end) {
                        io.println("error");
                        flag = false;
                        break;
                    }
                    if (front == 0) {
                        start++;
                    } else {
                        end --;
                    }
                }

            }


            if (flag) {
                StringBuilder sb = new StringBuilder();
                sb.append("[");
                if (front == 0) {
                    for (int k = start; k <= end; k++) {
                        sb.append(strarr[k]);
                        if (k != end) {
                            sb.append(",");
                        }
                        
                    }
                } else {
                    for (int k = end; k >= start; k--) {
                        sb.append(strarr[k]);
                        if (k != start) {
                            sb.append(",");
                        }
                        
                    }
                }
                sb.append("]");
                io.println(sb.toString());

            }


        }

        io.flush();

        

        

        }






        

}