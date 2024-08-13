package akcija;

import java.io.*;
import java.util.*;

public class akcija {
    public static void main(String args[]) throws IOException {

        Kattio io = new Kattio(System.in, System.out);

        int count = io.getInt();
        int[] arr = new int[count];

        for (int i = 0; i < count; i++) {
            int num = io.getInt();
            arr[i] = num;

        }

        Arrays.sort(arr);

        int total = 0;

        for (int i = 1; i <= arr.length; i++) {
            if (i % 3 != 0) {
                total += arr[arr.length-i];
            }
        }

        io.println(total);

        

        io.flush();

        

        

        }
    
}
