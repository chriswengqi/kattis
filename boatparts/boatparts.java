package boatparts;

import java.io.*;
import java.util.*;

public class boatparts {

    public static void main(String args[]) throws IOException {

        Kattio io = new Kattio(System.in, System.out);

        int parts = io.getInt();
        int count = io.getInt();
        int total = 0;
        boolean flag = false;
        HashMap<String, Integer> hm = new HashMap<>();

        for (int i = 1; i <= count; i++) {
            String part = io.getWord();
            if (!flag) {
                if (!hm.containsKey(part)) {
                    total += 1;
                }
    
                hm.put(part, i);
    
                if (total == parts) {
                    io.println(i);
                    flag = true;
                }

            }
            

        }


        if (!flag) {
            io.println("paradox avoided");
        }

        io.flush();

        

        

        }
    
}
