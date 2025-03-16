#include <stdio.h>

#define LINE_LEN 300

int main() {
    FILE *datafile;
    char line[LINE_LEN];

    setbuf(stdout, NULL);

    datafile = fopen("day.txt", "r");

    if (datafile != NULL) {
        //Read the numbers
        while (fgets(line, LINE_LEN, datafile) != NULL) {

        }

        fclose (datafile);
    }
    return 0;
}
