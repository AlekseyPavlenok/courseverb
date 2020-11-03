#include "develop.h"
#include "menu.h"

void dev()
{
    system("clear");
    printf("Irregular Verbs\n");
    printf("Creators:\n");
    printf("Sandyk Mikhail\n");
    printf("Pavlenok Alexey\n");
    printf("To return to the menu, press \"0\"\n");
    while (1) {
        char c = 1;
        scanf("%c%*c", &c);
        if (Exit(c) == 1) {
            return;
        } else {
            printf("Error, repeat, please");
        }
    }
}
