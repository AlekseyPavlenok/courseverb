#include "test2.h"
#include "menu.h"

void testing_2(FILE* gl)
{
    srand(time(NULL));
    gl = fopen("file1", "rb");
    struct verb* glagol_1;
    struct verb* glagol;
    srand(time(NULL));
    int i = 0;
    int j = 0;
    char a = 0;
    float procent = 0;
    int sv = 0;
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
            j = rand() % 30;
            printf("Infinitive: %s \n", glagol_1[j].inf);
            printf("Past Simple: %s \n", glagol_1[j].past);
            printf("Past Participle: %s \n", glagol_1[j].pasp);
            printf("Enter the translation: \n");
            scanf("%s", glagol[j].tran);
            scanf("%*c");
            if (check_verb(glagol[j].tran, glagol_1[j].tran) != 1) {
                printf("\n You are mistaken, learn these verbs, please: \n");
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
