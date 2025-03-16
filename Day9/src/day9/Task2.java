/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package day9;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

/**
 *
 * @author timjl
 */
public class Task2 {

    private static final int GRID_DEPTH = 100;
    private static final int GRID_LENGTH = 100;

    int[][] grid = new int[GRID_DEPTH][GRID_LENGTH];

    public void doStuff(String path) {
        File in = new File(path);
        String line;
        int lineNum = 0;
        int tmpVal;
        String lows = "";
        int total = 0;
        int size = 0;
        int [] biggest = {0,0,0};

        Scanner myReader = null;
        try {
            myReader = new Scanner(in);

            while (myReader.hasNextLine()) {
                line = myReader.nextLine();

                for (int n = 0; n < line.length(); n++) {
                    char ch = line.charAt(n);
                    tmpVal = (int) ch - '0';

                    grid[lineNum][n] = tmpVal;
                }

                lineNum++;
            }

            for (int y = 0; y < GRID_DEPTH; y++) {
                for (int x = 0; x < GRID_LENGTH; x++) {
                    if (grid[y][x] != -1) {
                        if (y == 0 || grid[y - 1][x] > grid[y][x]) {
                            if (y == GRID_DEPTH - 1 || grid[y + 1][x] > grid[y][x]) {
                                if (x == 0 || grid[y][x - 1] > grid[y][x]) {
                                    if (x == GRID_LENGTH - 1 || grid[y][x + 1] > grid[y][x]) {
                                        size = countNeighbours(x, y);
                                        System.out.println("Size = " + size);
                                        
                                        int min = biggest[0];
                                        int minPos = 0;
                                        for (int n = 0; n < 3; n++){
                                            if (biggest[n] < min){
                                                min = biggest[n];
                                                minPos = n;
                                            }
                                        }
                                        
                                        if (size > min) {
                                            biggest[minPos] = size;
                                        }
                                        
                                        System.out.println ("biggest = " + biggest[0] + ", " + biggest[1] + ", " + biggest[2] );
                                    }
                                }
                            }
                        }
                    }
                }
            }

            total = biggest[0] * biggest[1] * biggest[2];
            System.out.println("Total = " + total);

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

    }

    //Recursive counting
    int countNeighbours(int x, int y) {
        int ret = 1;

        //flag this as counted
        grid[y][x] = -1;

        if (y > 0 && grid[y - 1][x] != -1 && grid[y - 1][x] != 9) {
            ret = ret + countNeighbours(x, y - 1);
        }

        if (y < GRID_DEPTH - 1 && grid[y + 1][x] != -1 && grid[y + 1][x] != 9) {
            ret = ret + countNeighbours(x, y + 1);
        }

        if (x > 0 && grid[y][x - 1] != -1 && grid[y][x - 1] != 9) {
            ret = ret + countNeighbours(x - 1, y);
        }
        
        if (x < GRID_LENGTH - 1 && grid[y][x + 1] != -1 && grid[y][x + 1] != 9) {
            ret = ret + countNeighbours(x + 1, y);
        }

        return ret;
    }

}
