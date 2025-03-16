package com.company;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Task2 {
    private Dictionary<String, Node> map = new Hashtable<String, Node>();
    private LinkedList<String> paths = new LinkedList<>();

    public void act (String path){
        buildMap (path);

        generatePaths("", "start");

        System.out.println("Paths = " + paths.size());
    }

    private void buildMap (String path) {
        File in = new File(path);
        Scanner myReader = null;
        String line;

        try {
            myReader = new Scanner(in);

            while (myReader.hasNextLine()) {
                line = myReader.nextLine();

                String [] pair = line.split("-");

                Node n = map.get(pair[0]);
                if (n == null) {
                    n = new Node (pair[0]);
                    map.put(pair[0], n);
                }
                n.addNeighbour(pair[1]);

                n = map.get(pair[1]);
                if (n == null) {
                    n = new Node (pair[1]);
                    map.put(pair[1], n);
                }
                n.addNeighbour(pair[0]);
            }

            myReader.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void generatePaths (String curPath, String curNodeName) {


        if (curNodeName.equalsIgnoreCase("End")){
            curPath += ", " + curNodeName;
            paths.add(curPath);
            System.out.println("*" + curPath);
            return;
        }


        Node n = map.get(curNodeName);
        String pos = n.getNeighbours();
        String [] neighbours = pos.split(",");
        for (int x = 0; x<neighbours.length; x++){
            String next = neighbours[x];
            if (!curPath.contains(next) || map.get(next).isMajor()) {
                if (curPath.length() > 0 && !curPath.endsWith(curNodeName)){
                    curPath = curPath + ", ";
                }

                if (!curPath.endsWith(curNodeName))
                    curPath = curPath + curNodeName;

                generatePaths(curPath, next);
            }

        }

        return;
    }
}
