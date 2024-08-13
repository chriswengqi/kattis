package brexit;
import java.io.*;
import java.util.*;

public class brexit {

    public static void main(String args[]) throws IOException {
        
        Kattio io = new Kattio(System.in, System.out);

        Integer C = io.getInt();
        Integer P = io.getInt();
        Integer X = io.getInt();
        Integer L = io.getInt();

        int[] neighbours = new int[C + 1];
        int[] curr = new int[C + 1];
        boolean[] out = new boolean[C + 1];
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();

        for (int i = 0; i < C + 1; i++) {
            adjList.add(new ArrayList<>());
        }

        for (Integer i = 0; i < P; i++) {
            Integer u = io.getInt();
            Integer v = io.getInt();

            adjList.get(u).add(v);
            adjList.get(v).add(u);

            neighbours[v]++; neighbours[u]++;
            curr[v]++; curr[u]++;

        }


        Queue<Integer> queue = new LinkedList<>();

        queue.add(L);

        while (!queue.isEmpty() && !out[X]) {

            Integer current = queue.poll();

            curr[current]--;
            out[current] = true;

            for (Integer u: adjList.get(current)) {
                if (!out[u]) {
                    curr[u]--;
                    if (curr[u] <= neighbours[u] / 2) {
                        out[u] = true;
                        queue.add(u);
                    }

                }
                
            }


        }

/* 
        for (int i = 0; i < C + 1; i++) {
            io.print(out[i]);
        }

        for (int i = 0; i < C + 1; i++) {
            io.print(neighbours[i]);
        }

        for (int i = 0; i < C + 1; i++) {
            io.print(curr[i]);
        }

        */


        

        if (out[X]) {
            io.println("leave");
        } else {
            io.println("stay");
        }

        io.flush();



    }



    
}
