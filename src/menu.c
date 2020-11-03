#include "menu.h"
#include "develop.h"
#include "table.h"
#include "test1.h"
#include "test2.h"

int check_verb(char* a, char* b)
{
    if (strcmp(a, b) != 0)
        return 0;
    else
        return 1;
}

int Exit(char s)
{
    if (s == '0')
        return 1;
    else
        return 0;
}

int check_number(int s)
{
    if (s > 0 && s < 31)
        return 1;
    else
        return 0;
}

int print()
{
    system("clear");
    printf("----------------------------");
    printf("\n");
    printf("|  1 - Verb table          |");
    printf("\n");
    printf("----------------------------");
    printf("\n");
    printf("|  2 - Guess the forms     |");
    printf("\n");
    printf("----------------------------");
    printf("\n");
    printf("|  3 - Write a translation |");
    printf("\n");
    printf("----------------------------");
    printf("\n");
    printf("|  4 - Developers          |");
    printf("\n");
    printf("----------------------------");
    printf("\n");
    printf("|  0 - Exit                |");
    printf("\n");
    printf("----------------------------");
    printf("\n");
    printf("Please, select an item from the menu ");
    printf("\n");
    return 0;
}

int men()
{
    char c = 1;
    FILE* fp;
    fp = fopen("file1", "rb");
    fseek(fp, 0, SEEK_SET);
    while (1) {
        print();
        scanf("%c%*c", &c);
        switch (c) {
        case '0':
            system("clear");
            printf("THANK YOU!\n");
            return 0;
        case '1':
            system("clear");
            printf("Read the spreadsheet carefully before testing!\n");
            printf("To return to the menu, press \"0\"\n\n");
            print_table(fp);
            break;
        case '2':
            system("clear");
            printf("In this test, you must enter the correct forms of the "
                   "verb\n");
            testing_1(fp);
            break;
        case '3':
            system("clear");
            printf("In this test,you are given three forms of the verb.You "
                   "have to "
                   "write the translation\n");
            printf("To return to the menu, press \"0\"\n\n");
            testing_2(fp);
            break;
        case '4':
            dev();
            break;
        default:
            break;
        }
    }

    fclose(fp);
    return 0;
}