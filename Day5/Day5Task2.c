#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LINE_LEN 20

typedef struct  point {
    int x;
    int y;
    int count;
    struct point *next;
};

struct point *g_map = NULL;
void updateNode (int x, int y );

int main() {
    setbuf (stdout, NULL);

    FILE *datafile;
    int startX, startY, endX, endY;
    char line [LINE_LEN];
    int offset;
    int x,y;
    int tmp;
    int counter = 0;
    struct point *p;

    datafile = fopen ("day5.txt", "r");

    if (datafile != NULL) {
        while (fgets(line, LINE_LEN, datafile) != NULL) {
            startX = atoi(line);

            //Move past the current number
            offset = 0;
            while (isdigit(line[offset])) {
                offset++;
            }

            //And then to the next
            while (!isdigit(line[offset])) {
                offset++;
            }
            startY = atoi(&line[offset]);

            //Move past the current number
            while (isdigit(line[offset])) {
                offset++;
            }

            //And then to the next
            while (!isdigit(line[offset])) {
                offset++;
            }
            endX = atoi(&line[offset]);

            //Move past the current number
            while (isdigit(line[offset])) {
                offset++;
            }

            //And then to the next
            while (!isdigit(line[offset])) {
                offset++;
            }
            endY = atoi(&line[offset]);

            printf ("start X = %d, start Y = %d, end X = %d, end Y = %d\n", startX, startY, endX, endY);

                x = startX;
                y = startY;

                while (x != endX || y != endY) {
                    updateNode(x,y);

                    if (x != endX) {
                        if (endX >= startX) {
                            x++;
                        }else {
                            x--;
                        }

                    }

                    if (y != endY) {
                        if (endY >= startY) {
                            y++;
                        } else {
                            y--;
                        }
                    }
                }
                updateNode(x,y);

            }


        p = g_map;

        counter = 0;
        while (p != NULL){
            if (p -> count > 1) {
                counter++;
                printf("x = %d, y = %d, total = %d\n", p->x, p->y, p->count);
            }

            p = p -> next;
        }

        printf ("Result = %d\n", counter);
    }


    return 0;
}

void updateNode (int x, int y ) {
    struct point *p = g_map;
    int found = 0;

    while (p != NULL && !found) {
        if (p->x == x && p->y == y) {
            found = -1;
            p-> count++;
        }
        p = p -> next;
    }

    if (!found) {
        p = malloc (sizeof(struct point));
        p -> x = x;
        p -> y = y;
        p ->count = 1;

        //Add to the start of the list
        p ->next = g_map;
        g_map = p;
    }
}
