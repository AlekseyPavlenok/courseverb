#include "table.h"
#include "menu.h"

void print_table(FILE* tf)
{
    tf = fopen("file1", "rb");
    int i = 1;
    fread(&t1, sizeof(t1), 1, tf);
    printf("|    Inf:   |   Past:   |  PastPac: |   Trans:  | \n");
    while (!feof(tf)) {
        printf("| %9s | %9s | %9s | %9s |\n",
               t1.inf,
               t1.past,
               t1.pasp,
               t1.tran);
        fread(&t1, sizeof(t1), 1, tf);
        i++;
    }

    while (1) {
        char c = 1;
        scanf("%c%*c", &c);
        if (Exit(c) == 1) {
            fclose(tf);
            return;
        } else {
            printf("Error, repeat, please");
        }
    }
}