package classy;

import java.io.*;
import java.util.*;

public class classy {
    public static void main(String args[]) throws IOException {


        Scanner sc = new Scanner(System.in);

        int count = Integer.parseInt(sc.nextLine());

        
        
        for (int i = 1; i <= count; i++) {
            int num = Integer.parseInt(sc.nextLine());

            Person[] persons = new Person[num];

            for (int j = 1; j <= num;j++) {
                String s = sc.nextLine();

                persons[j-1] = new Person(s);

                
            }

            System.out.println(new Person("mom: upper-upper-lower-middle class").compareTo(new Person("upper-upper-upper class")));

            Arrays.sort(persons);




            for (int j = 0; j < persons.length; j++) {
                System.out.println(persons[j].name);
            }
        }

        

        

        sc.close();

        

        

        }
}

class Person implements Comparable<Person> {

    String name;
    String title;

    Person(String s) {
        name = s.split(": ")[0];
        title = s.split(": ")[1];
        this.name = name.substring(0, name.length());

        this.title = title.substring(0, title.length() - 6);
    }

    public int compareTo(Person p) {
        String[] thisarr = this.title.split("-");
        String[] parr = p.title.split("-");

        String[] thisone = new String[10];
        String[] thatone = new String[10];

        int counter = 0;
        for (int i = thisarr.length - 1; i >= 0; i--) {
            thisone[counter] = thisarr[i];
            counter++;
        }

        int ctp = 0;
        for (int i = parr.length - 1; i >= 0; i--) {
            thatone[ctp] = parr[i];
            ctp++;
        }



        int ans = compara(thisone, thatone);

        if (ans == 0) {
            if (this.name.compareTo(p.name) == -1) {
                return 1;
            } else if (this.name.compareTo(p.name) == 1) {
                return -1;
            } else {
                return 0;
            }
        }

        return ans;
        




    }

    private int compara(String[] a, String[] b) {
        for (int i = 0; i < 10; i++) {
            if (a[i] == null) {
                a[i] = "middle";
            }
            if (b[i] == null) {
                b[i] = "middle";
            }
            if (a[i].compareTo(b[i]) == 1) {
                return -1;
            } else if (a[i].compareTo(b[i]) == -1) {
                return 1;
            }
        }

        return 0;
    }

}
