#include <stdio.h>
#include <mem.h>
#include <malloc.h>

struct Rule {
    char pair[3];
    char insert;
    struct Rule *next;
};

int main() {
    FILE *datafile;
    char line[20];
    char *template;
    char *next = NULL;
    char ch;
    int n;
    int nPos;
    int tPos;
    struct Rule *newRule;
    struct Rule *rules = NULL;

    setbuf(stdout, NULL);

    datafile = fopen("test.txt", "r");

    if (datafile != NULL) {
        //Read the original template;
        fgets(line, 20, datafile);

        template = malloc (strlen(line) +1);
        strcpy (template, line);

        //Skip the blank line
        fgets(line, 20, datafile);

        while (fgets(line, 20, datafile) != NULL) {
            newRule = malloc (sizeof(struct Rule));

            strncpy (newRule ->pair, line, 2);
            newRule ->insert = line[6];

            newRule ->next = rules;
            rules = newRule;
        }
        fclose(datafile);

        for (n = 0; n < 10; n++){
            if (next != NULL){
                free (next);
            }

            next = malloc (strlen(template) * 2);

            nPos = 0;
            tPos = 0;

            while (nPos < strlen(template) -1){
                next[nPos] = template[tPos];
                nPos++;
            }


        }
    }

    return 0;
}
