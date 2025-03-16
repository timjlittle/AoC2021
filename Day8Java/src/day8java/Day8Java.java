/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package day8java;

import java.io.File;
import java.io.FileNotFoundException;
//import java.io.FileReader;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author timjl
 */
public class Day8Java {

    private static char[] letterMap = {'\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0'};
    private static int[] numberMap = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    private static String[] originals = {"abcefg", //0
        "cf", //1
        "acdeg", //2
        "acdfg", //3
        "bcdf", //4
        "abdfg", //5
        "abdefg", //6
        "acf", //7
        "abcdefg", //8
        "abcdfg" }; //9

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //int uniqueCounter = 0;
        //int unqLens [] = {2,4, 3, 7};
        String[] halves;
        String[] outputs;
        String[] inputs;
        int[] letterCount = {0, 0, 0, 0, 0, 0, 0};
        int total = 0;

        try {
            File in = new File("day8.txt");
            String line = "";
            Scanner myReader = new Scanner(in);
            while (myReader.hasNextLine()) {
                //Initialise maps

                for (int n = 0; n < 10; n++) {
                    numberMap[n] = -1;
                    letterMap[n % 7] = ' ';
                    letterCount[n % 7] = 0;
                }

                line = myReader.nextLine();
                halves = line.split("\\|");
                outputs = halves[1].split(" ");
                inputs = halves[0].split(" ");

                for (int x = 0; x < inputs.length; x++) {
                    int len = inputs[x].length();

                    if (len == 2) {
                        numberMap[1] = x;
                    }

                    if (len == 4) {
                        numberMap[4] = x;
                    }

                    if (len == 3) {
                        numberMap[7] = x;
                    }
                    if (len == 7) {
                        numberMap[8] = x;
                    }

                    //Add the count of each letter to the total
                    for (int n = 0; n < len; n++) {
                        char ch = inputs[x].charAt(n);

                        int offset = ch - 'a';
                        letterCount[offset]++;
                    }

                }

                //find the mappings for e, f and b as they are have unique counts
                for (int n = 0; n < 7; n++) {
                    //only b occurrs 6 times in all 10 numbers
                    if (letterCount[n] == 6) {
                        letterMap[1] = (char) ('a' + n);
                    }

                    //only e occurrs 5 times in all 10 numbers
                    if (letterCount[n] == 4) {
                        letterMap[4] = (char) ('a' + n);
                    }

                    //only f occurrs 9 times in all 10 numbers
                    if (letterCount[n] == 9) {
                        letterMap[5] = (char) ('a' + n);
                    }
                }

                //Use the one difference between 1 and 7 to identify which input char corresponds to a
                if (!inputs[numberMap[1]].contains("" + inputs[numberMap[7]].charAt(0))) {
                    letterMap[0] = inputs[numberMap[7]].charAt(0);
                } else if (!inputs[numberMap[1]].contains("" + inputs[numberMap[7]].charAt(1))) {
                    letterMap[0] = inputs[numberMap[7]].charAt(1);
                } else {
                    letterMap[0] = inputs[numberMap[7]].charAt(2);
                }

                //Remaining unmapped letter from 7 must be c
                int n = 0;
                int x = 0;
                boolean found = true;
                char ch = '\0';
                while (found && n < 3) {
                    ch = inputs[numberMap[7]].charAt(n);
                    x = 0;
                    found = false;
                    while (!found && x < 7) {
                        if (ch == letterMap[x]) {
                            found = true;
                        }
                        x++;
                    }
                    if (found) {
                        n++;
                    }
                }

                letterMap[2] = ch;

                //At this point there should only be 2 letters left to map - d and g.
                //The only number that has only one missing is 0, the letter that is left unmapped
                //must be g
                n = 0;
                x = 0;
                while (n < 10 && x != 1) {
                    x = countUmappeds(inputs[n]);
                    if (x != 1) {
                        n++;
                    }
                }

                String mappedLetters = String.valueOf(letterMap);
                if (x == 1) {
                    x = 0;
                    while (x < inputs[n].length() && mappedLetters.contains("" + inputs[n].charAt(x))) {
                        x++;
                    }

                    if (inputs[n].length() == 6) {
                        letterMap[6] = inputs[n].charAt(x);
                    } else {
                        letterMap[3] = inputs[n].charAt(x);
                    }
                }

                //And the last remaining unmapped 
                ch = 'a';
               
                do {
                    found = false;
                    n = 0;
                    while (n < 7 && !found) {
                        if (letterMap[n] == ch) {
                            found = true;
                        } else {
                            n++;
                        }
                    }

                    if (found) {
                        ch++;
                    }
                } while (found);

                if (letterMap[3] == ' ') {
                    letterMap[3] = ch;
                } else {
                    letterMap[6] = ch;
                }

                mappedLetters = String.valueOf(letterMap);
                System.out.println("Map = " + mappedLetters);

                //All the letters are mapped by now
                //So compare each of the outputs with the inputs, then map to get
                //a number. Build the number up
                int dispTotal = 0;
                for (n = 0; n < 4; n++) {
                    int digit = 0;

                    System.out.print(outputs[n] + " ");

                    digit = getValue(mapVal(outputs[n]));
                    dispTotal += digit;

                    if (n < 3) {
                        dispTotal *= 10;
                    }
                }

                System.out.println("" + dispTotal);
                total += dispTotal;

            }

            System.out.println("Total = " + total);

            myReader.close();

            //System.out.println("Unique = " + uniqueCounter);
        } catch (FileNotFoundException ex) {
            System.out.println("Error opening file");
            Logger.getLogger(Day8Java.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    static private int countUmappeds(String in) {
        //Start by assuming nine are mapped
        int ret = in.length();

        for (int n = 0; n < in.length(); n++) {
            char ch = in.charAt(n);

            int x = 0;
            while (letterMap[x] != ch && x < 7) {
                x++;
            }

            //if you found it reduce ret by one
            if (letterMap[x] == ch) {
                ret--;
            }
        }

        return ret;
    }

    static private String sortString(String line) {
        char[] list = line.toCharArray();
        for (int x = 1; x < line.length(); x++) {
            char ch = list[x];

            int y = x - 1;
            while (y >= 0 && list[y] > ch) {
                list[y + 1] = list[y];
                y--;
            }

            list[y + 1] = ch;

        }

        return String.valueOf(list);
    }

    static private int getValue(String val) {
        int ret = 0;

        String local = sortString(val);

        while (!local.contentEquals(originals[ret])) {
            ret++;
        }
        return ret;
    }

    private static String mapVal(String inVal) {
        char[] vals = inVal.toCharArray();

        for (int n = 0; n < vals.length; n++) {
            int x = 0;
            while (letterMap[x] != vals[n]) {
                x++;
            }

            vals[n] = (char) ('a' + x);
        }
        return String.copyValueOf(vals);
    }
}
