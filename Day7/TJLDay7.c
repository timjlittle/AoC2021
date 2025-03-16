#include <stdio.h>
#include <malloc.h>
#include <mem.h>
#include <ctype.h>

struct crabpos {
    int pos;
    int count;
    struct crabpos *next;
};

struct crabpos *g_listHead = NULL;

void addCrab (int newPos);
int getNextNum (char* numLine);
int calcFuel (int diff);


int main() {
    setbuf (stdout, NULL);

    char line[4000];
    FILE *datafile;
    unsigned long total = 0;
    int count = 0;
    long min =203740650;
    int minval = -1;
    int error = 0;
    int num;
    int target = 65;
    unsigned long fuel = 0;
    int diff;
    struct crabpos *ptr;
    //struct crabpos *cur;


    datafile = fopen ("day7.txt", "r");
    if (datafile != NULL) {
        if (fgets(line, 4000, datafile) == NULL) {
            error = errno;
        }
    } else {
        error = errno;
    }

    if (error == 0) {
        fclose (datafile);

        num = 0;
        while (num > -1) {
            num = getNextNum(line);
            if (num != -1){
                addCrab(num);
                printf("%d\n", num);

            }
        }

        //Loop calculating the fuel to each position
        //cur = g_listHead;
        for (int cur = 0; cur <= 1971; cur++){
            fuel = 0;
            ptr = g_listHead;
            while (ptr != NULL && fuel < min) {
                diff = abs(cur - ptr ->pos);
                diff = calcFuel(diff);
                fuel += diff * ptr ->count;
                ptr = ptr -> next;
            }
            if (fuel < min){
                min = fuel;
                minval = cur;
            }
            //cur = cur ->next;
        }

        printf("fuel to %d is %d\n", minval, min);


    } else {
        printf ("Error %d occurred\n", error);
    }

    return error;
}

int getNextNum (char* numLine) {
    int ret = -1;
    int offset = 0;

    //If the number list is empty return -1
    if (strlen (numLine) > 0) {

        //Otherwise get the next number
        ret = atoi(numLine);

        //And move on
        while (isdigit(numLine[offset])) {
            offset++;
        }

        while (!isdigit(numLine[offset]) && numLine[offset] != '\0') {
            offset++;
        }
        strcpy (numLine, &numLine[offset]);
    }

    return ret;
}

void addCrab (int newPos) {
    struct crabpos *p = g_listHead;

    while (p != NULL && p->pos != newPos) {
        p = p-> next;
    }

    if (p != NULL ) {
        p -> count++;
    } else {
        p = malloc (sizeof(struct crabpos));
        p -> pos = newPos;
        p ->count = 1;

        p -> next = g_listHead;
        g_listHead = p;
    }
}

int calcFuel (int diff) {
    int ret = 0;
    int x;

    for (x = 1; x<= diff; x++) {
        ret += x;
    }

    return ret;
}