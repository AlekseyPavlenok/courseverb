#include "ctest.h"
#include "menu.h"

CTEST(translate, first_word)
{
    FILE* fp = fopen("file1", "rb");
    fread(&t1, sizeof(t1), 1, fp);
    fclose(fp);
    struct verb expected = {"be", "was,were", "been", "быть"};
    ASSERT_EQUAL(1, check_verb(expected.tran, t1.tran));
}

CTEST(translate, last_word)
{
    FILE* fp = fopen("file1", "rb");
    while (!feof(fp)) {
        fread(&t1, sizeof(t1), 1, fp);
    }
    fclose(fp);
    struct verb expected = {"learn", "learnt", "learnt", "учить"};
    ASSERT_EQUAL(1, check_verb(expected.tran, t1.tran));
}

CTEST(translate, border)
{
    FILE* fp = fopen("file1", "rb");
    fread(&t1, sizeof(t1), 1, fp);
    fclose(fp);
    struct verb expected = {"learn", "learnt", "learnt", "учить"};
    ASSERT_EQUAL(0, check_verb(expected.tran, t1.tran));
}

CTEST(enter, check_verb_equal)
{
    char* a = "be";
    char* b = "be";
    int real = check_verb(a, b);
    unsigned int exp = 1;
    ASSERT_EQUAL(real, exp);
}

CTEST(enter, check_verb_diff)
{
    char* a = "be";
    char* b = "hear";
    int real = check_verb(a, b);
    unsigned int exp = 0;
    ASSERT_EQUAL(real, exp);
}

CTEST(enter, check_verb_empty)
{
    char* a = "";
    char* b = "";
    int real = check_verb(a, b);
    unsigned int exp = 1;
    ASSERT_EQUAL(real, exp);
}