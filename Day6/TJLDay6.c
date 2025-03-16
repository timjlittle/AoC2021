#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    setbuf(stdout, NULL);

    unsigned long long int days [10];
    FILE *datafile;
    char line [601];
    int offset = 0;
    int num;
    int counter, x;
    unsigned long long int total;

    //Initialise days array
    for (counter = 0; counter < 9; counter++) {
        days[counter] = 0;
    }

    datafile = fopen ("day6.txt", "r");

    if (datafile != NULL) {
        if (fgets(line, 601,datafile ) != NULL) {
            offset =0;

            while (line[offset] != '\0'){
                num = atoi (&line[offset]);
                days[num]++;

                //Move on to the next number
                while (isdigit(line[offset])) {
                    offset++;
                }

                while (line[offset] != '\0' && !isdigit(line[offset])) {
                    offset++;
                }
            }
        }
        fclose(datafile);
    }

    for (counter = 0; counter < 9; counter++){
        printf("days[%d] = %d\n", counter, days[counter]);
    }

    for (counter = 0; counter < 256; counter++) {
        days [9] = days[0];

        days[7] += days[0];

        for (x = 1; x < 10; x++){
            days[x-1] = days[x];
        }

        total = 0;
        for (x = 0; x < 9; x++){
            total += days[x];
        }
        printf("After day %d Number of lanternfish = %llu\n", counter, total);
    }

    total = 0;

    for (x = 0; x < 9; x++){
        total += days[x];
    }

    printf("Number of lanternfish = %llu", total);


    return 0;
}
