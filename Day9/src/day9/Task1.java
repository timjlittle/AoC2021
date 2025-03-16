package day9;
import java.io.File;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Task1 {
    private static final int GRID_DEPTH = 5;
    private static final int GRID_LENGTH = 10;

    int [][] grid = new int [GRID_DEPTH][GRID_LENGTH];

    public void doStuff (String path) {
        File in = new File(path);
        String line;
        int lineNum = 0;
        int tmpVal;
        String lows = "";
        int total = 0;

        Scanner myReader = null;
        try {
            myReader = new Scanner(in);

            while (myReader.hasNextLine()) {
                line = myReader.nextLine();

                for (int n = 0; n < line.length(); n++){
                    char ch = line.charAt(n);
                    tmpVal = (int)ch - '0';

                    grid[lineNum][n] = tmpVal;
                }

                lineNum++;
            }

            for (int y = 0; y < GRID_DEPTH; y++){
                for (int x = 0; x < GRID_LENGTH; x++){
                    if (y ==0 || grid[y-1][x] > grid[y][x]) {
                        if (y == GRID_DEPTH -1 || grid[y+1][x] > grid[y][x]){
                            if (x == 0 || grid[y][x-1] > grid[y][x]) {
                                if (x == GRID_LENGTH -1 || grid[y][x+1] > grid[y][x]){
                                    total += grid[y][x] + 1;
                                }
                            }
                        }
                    }
                }
            }

            System.out.println ("Total = " + total);

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }


    }

}
