package com.company;

import java.util.Iterator;
import java.util.LinkedList;

public class Node {
    private String name;
    private String neighbours = "";
    private boolean major;

    public Node (String name) {
        this.name = name;

        if (Character.isUpperCase(name.charAt(0))) {
            major = true;
        } else {
            major = false;
        }
    }

    public boolean isMajor () {
        return major;
    }

    public void addNeighbour (String name) {
        if (neighbours.length() > 0) {
            neighbours += ",";
        }
        neighbours += name;
    }

    public String getNeighbours () {

        return (neighbours);
    }

}
