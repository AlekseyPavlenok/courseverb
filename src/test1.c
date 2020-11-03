#include "test1.h"
#include "menu.h"

void testing_1(FILE* gl)
{
    srand(time(NULL));
    gl = fopen("file.bin", "rb");
    struct verb* glagol_1;
    struct verb* glagol;
    float procent = 0;
    int sv = 0;
    srand(time(NULL));
    int i = 0;
    int j = 0;
    char a = 0;
    int n = 0;
    glagol_1 = (struct verb*)malloc(30 * sizeof(struct verb));
    glagol = (struct verb*)malloc(30 * sizeof(struct verb));
    for (i = 0; i < 30; i++)
        fread(&glagol_1[i], sizeof(struct verb), 1, gl);
    printf("Enter the number of verbs you want to guess (up to 30)");
    scanf("%d", &n);
    scanf("%*c");
    if (check_number(n) == 1) {
        while (a < n) {
            j = rand() % 31;
            printf("%s\n", glagol_1[j].tran);
            printf("Infinitive:\n");
            scanf("%s", glagol[j].inf);
            printf("Past Simple:\n");
            scanf("%s", glagol[j].past);
            printf("Past Participle:\n");
            scanf("%s", glagol[j].pasp);
            scanf("%*c");
            if ((check_verb(glagol[j].inf, glagol_1[j].inf) != 1)
                || (check_verb(glagol[j].past, glagol_1[j].past) != 1)
                || (check_verb(glagol[j].pasp, glagol_1[j].pasp) != 1)) {
                printf("\nYou are mistaken, learn these verbs, please:\n");
                printf("Infinitive:\n");
                printf("%s\n", glagol_1[j].inf);
                printf("Past Simple:\n");
                printf("%s\n", glagol_1[j].past);
                printf("Past Participle:\n");
                printf("%s\n", glagol_1[j].pasp);
                printf("Translate:\n");
                printf("%s\n", glagol_1[j].tran);
                printf("\n");
            } else {
                sv++;
                printf("\nGREAT!\n\n");
            }
            a++;

            if (a == n) {
                procent = (sv * 100) / n;
                printf("procent: %.0f\n", procent);
                if (procent >= 80)
                    printf("Excellent work!");
                if ((procent >= 40) && (procent < 80))
                    printf("Good work");
                if (procent < 40)
                    printf("Badly.Try to take the test again");
                printf("\n Congratulate! Press '0'!");
            }
        }
    } else
        return;

    while (1) {
        char c = 1;
        scanf("%c%*c", &c);
        if (Exit(c) == 1) {
            free(glagol);
            free(glagol_1);
            fclose(gl);
            return;
        } else {
            printf("Error, repeat, please");
        }
    }
}
