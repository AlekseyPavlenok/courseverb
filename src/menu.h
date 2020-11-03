#ifndef MENU_H
#define MENU_H

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <termios.h>
#include <time.h>

struct verb {
    char inf[15];
    char past[15];
    char pasp[15];
    char tran[100];
} t1;

int check_verb(char* a, char* b);
int Exit(char s);
int check_number(int s);
int print();
int men();

#endif