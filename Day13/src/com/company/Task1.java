package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Task1 {
    ArrayList<ArrayList<Integer>> map = new ArrayList<>();
    ArrayList <String> instructions = new ArrayList<>();

    public void act (String path) {
        readData (path);

        //doFolds ();

    }

    /**
     * Reads the data for task 13
     * Assumes a correctly formatted file
     *
     * @param path Location of the data file
     */
    private void readData (String path){
        File in = new File(path);
        Scanner myReader = null;
        String line;
        boolean readingPoints = true;

        try {
            myReader = new Scanner(in);

            while (myReader.hasNextLine()) {
                line = myReader.nextLine();

                if (line.length() != 0) {
                    if (readingPoints) {
                        String [] pos = line.split(",");
                        int x = Integer.parseInt(pos[0]);
                        int y = Integer.parseInt(pos[1]);


                        ArrayList<Integer> row;
                        if (map.contains(y)) {
                            row = new ArrayList<Integer> ();
                            map.add(y, row);
                        } else {
                            row = map.get(y);
                        }

                        row.add(x, 1);

                    } else {
                        String instr = line.substring(11, line.length() - 11);
                        instructions.add(instr);
                    }


                } else {
                    //Blank line marks the line between the dots and the folds
                    //Skip it
                    readingPoints = false;
                }

            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
