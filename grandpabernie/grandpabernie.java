package grandpabernie;

import java.io.*;
import java.util.*;

public class grandpabernie {

    public static void main(String args[]) throws IOException {

        Scanner sc = new Scanner(System.in);

        int count = Integer.parseInt(sc.nextLine());
        HashMap<String, ArrayList<String>> hm = new HashMap<>();

        for (int i = 0; i < count; i++) {
            String s = sc.nextLine();
            String[] strarr = s.split(" ");
            String country = strarr[0];
            String year = strarr[1];
            if (hm.containsKey(country)) {
                hm.get(country).add(year);
            } else {
                hm.put(country, new ArrayList<>());
                hm.get(country).add(year);
            }

        }

        for (String country: hm.keySet()) {
            Collections.sort(hm.get(country));
        }

        int query = Integer.parseInt(sc.nextLine());

        for (int j = 1; j <= query; j++) {
            String s = sc.nextLine();
            String[] strarr = s.split(" ");
            String country = strarr[0];
            int k = Integer.parseInt(strarr[1]);

            ArrayList<String> l = hm.get(country);
            System.out.println(l.get(k-1));
        }
        

        sc.close();
        

        

        }
    
}
