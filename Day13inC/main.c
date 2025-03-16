#include <stdio.h>
#include <malloc.h>
#include <ctype.h>
#include <mem.h>

#define LINE_LEN 30

struct Dot {
    int xPos;
    struct Dot *next;
};

struct Line {
    int yPos;
    struct Line *next;
    struct Dot *dots;
};

struct Line *g_map = NULL;
int g_maxX = 0;
int g_maxY = 0;

char folds [12][LINE_LEN];

void printLine (int num){
    struct Line *curLine = g_map;
    struct Dot *curDot;
    int x = 0;

    while (curLine ->yPos < num){
        curLine = curLine ->next;
    }

    if (curLine ->yPos == num){
        x = 0;
        printf ("line %d:\n", num);
        curDot = curLine ->dots;
        while (curDot != NULL){
            if (x < curDot ->xPos){
                printf (" ");
            } else {
                printf("#");
                curDot = curDot ->next;
            }
            x++;
        }
        printf ("\nx = %d\n", x);

    } else {
        printf("line %d not found\n");
    }
}

void printMap (int printInstr){
    struct Line *curLine = g_map;
    struct Dot *curDot;
    int x;
    int y = 0;

    //while (y <= g_maxY && curLine != NULL) {
    while (curLine != NULL) {
        x = 0;

        if (curLine != NULL)
            curDot = curLine ->dots;
        else
            curDot = NULL;

        //while (x <= g_maxX && curDot != NULL){
        while (curDot != NULL){
            if (curDot == NULL || x < curDot ->xPos || curLine == NULL || y != curLine -> yPos){
                printf(" ");
            } else {
                printf ("#");
                curDot = curDot ->next;
            }
            x++;

        }
        printf("\n");

        if (curLine != NULL && y == curLine -> yPos) {
            curLine = curLine->next;
        }
        y++;
    }

    y = 0;

    if (printInstr) {
        while (strlen(folds[y]) > 0) {
            printf("%s", folds[y]);
            y++;
        }
    }
}

void addDot (int x, int y) {
    struct Line *curLine;
    struct Line *prevLine = NULL;
    struct Dot *curDot;
    struct Dot *prevDot = NULL;

    if (x > g_maxX){
        g_maxX = x;
    }

    if (y > g_maxY){
        g_maxY = y;
    }
    /*
     * If it's the first dot just add it.
     */
    if (g_map == NULL){
        g_map = malloc (sizeof(struct Line));
        g_map ->yPos = y;
        g_map ->next = NULL;

        g_map ->dots = malloc (sizeof(struct Dot));
        g_map ->dots -> xPos = x;
        g_map ->dots ->next = NULL;
    } else {
        curLine = g_map;

        /*
         * Otherwise step down the list until you get to
         * a bigger value or the end of the list
         */
        while (curLine != NULL && curLine ->yPos < y) {
            prevLine = curLine;
            curLine = curLine ->next;
        }

        /*
         * If you haven't found it add the line
         */
        if (curLine == NULL || curLine ->yPos != y){
            if (prevLine != NULL) {
                prevLine ->next = malloc(sizeof(struct Line));
                prevLine = prevLine -> next;

            } else {
                //special case, needs to go at the start
                prevLine= malloc(sizeof(struct Line));
                g_map = prevLine;
            }
            prevLine -> next = curLine;
            prevLine ->yPos = y;

            prevLine ->dots = malloc (sizeof(struct Dot));
            prevLine ->dots -> xPos = x;
            prevLine ->dots ->next = NULL;
        } else {
            //Found it so just need to add to the dots list
            curDot = curLine ->dots;
            while (curDot != NULL && curDot -> xPos < x) {
                prevDot = curDot;
                curDot = curDot ->next;
            }

            if (curDot == NULL || curDot ->xPos != x){
                if (prevDot != NULL){
                    prevDot -> next = malloc(sizeof(struct Dot));
                    prevDot = prevDot ->next;
                } else {
                    prevDot = malloc(sizeof(struct Dot));
                    curLine ->dots = prevDot;
                }

                prevDot ->next = curDot;
                prevDot ->xPos = x;
            }
        }
    }
}

void readData (char *path){
    FILE *datafile;
    char line[LINE_LEN];
    int x;
    int y;
    int pos;
    int readingDots = -1;

    setbuf(stdout, NULL);

    datafile = fopen(path, "r");

    if (datafile != NULL) {
        //Read the numbers
        while (fgets(line, LINE_LEN, datafile) != NULL) {
            if (readingDots && !isdigit(line[0])){
                readingDots = 0;
                y = 0;
            } else {
                if (readingDots) {

                    x = atoi(line);
                    pos = 0;
                    while (isdigit(line[pos])) {
                        pos++;
                    }
                    pos++;
                    y = atoi(&line[pos]);

                    addDot(x, y);
                } else {
                    strcpy (folds[y++], line);
                }

            }

        }

        strcpy (folds[y++], "");

        fclose (datafile);
    }
}

char *trim (char *str){
    int pos = strlen(str) - 1;

    while (pos >= 0 && isblank(str[pos])){
        str[pos] = '\0';
        pos--;
    }

    return str;
}

void doFoldY (int pivot) {
    struct Line *curLine = g_map;
    struct Line *prevLine;
    struct Dot *curDot;
    struct Dot *prevDot;
    int y;

    //Find the line after the pivot
    while (curLine ->yPos <= pivot){
        prevLine = curLine;
        curLine = curLine ->next;
    }

    prevLine -> next = NULL;

    while (curLine != NULL){

        y = pivot - (curLine ->yPos - pivot);
        curDot = curLine ->dots;

        while (curDot != NULL){
            prevDot = curDot;

            addDot(curDot ->xPos, y);
            curDot = curDot ->next;
            free(prevDot);
        }

        prevLine = curLine;
        curLine = curLine ->next;
        free(prevLine);
    }

    g_maxY = pivot - 1;

}

void doFoldX (int pivot) {
    struct Line *curLine = g_map;
    struct Dot *curDot;
    struct Dot *prevDot;
    int x;

    while (curLine != NULL) {
        //printf("Folding line %d\n", curLine ->yPos);
        curDot = curLine ->dots;

        prevDot = curLine ->dots;
        while (curDot != NULL && curDot ->xPos <= pivot){
            prevDot = curDot;
            curDot = curDot ->next;
        }
/*
        //Special case
        if (curLine ->dots ->xPos > pivot){
            x = pivot - (curDot ->xPos - pivot);
            curLine ->dots ->xPos = x;
        }

        prevDot ->next = NULL;
*/
        while (curDot != NULL) {
            x = pivot - (curDot ->xPos - pivot);
            addDot(x, curLine ->yPos);
            prevDot = curDot;

            curDot = curDot ->next;
            //free(prevDot);

        }
        curDot = curLine ->dots;
        while (curDot != NULL && curDot ->xPos <= pivot){
            prevDot = curDot;
            curDot = curDot ->next;
        }

        prevDot ->next = NULL;
        while (curDot != NULL) {
            prevDot = curDot;

            curDot = curDot ->next;
            free(prevDot);
        }

        curLine = curLine ->next;
    }

    g_maxX = pivot - 1;
}


void doFold (char *instr) {
    int pos;
    int val;
    char direction;

    trim(instr);
    pos = strlen(instr) - 1;

    while (isdigit(instr[pos-1])){
        pos--;
    }

    val = atoi (&instr[pos]);
    pos -= 2;

    direction = instr[pos];

    if (direction == 'x') {
        doFoldX(val);
    } else {
        doFoldY(val);
    }
}

int countDots () {
    struct Line *row = g_map;
    struct Dot *dots = NULL;
    int count = 0;

    while (row != NULL) {
        dots = row->dots;

        while (dots != NULL) {
            count++;
            dots = dots ->next;
        }

        row = row ->next;
    }

    return count;
}

int main() {

    readData("Day13.txt");
    //printLine (2);

    printf ("max x = %d, max y = %d\n%s\n", g_maxX, g_maxY, folds[0]);

    int n = 0;
    while (strlen(trim(folds[n])) > 0) {
        printf ("%s", folds[n]);
        doFold(folds[n]);
        n++;
    }

    printf("\n");
    printMap(-1);
    printf("\n");

    printf("\nNumber of dots = %d\n", countDots ());

    return 0;
}
