#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "id.h"

static int tests_passed = 0;
static int tests_failed = 0;

#define TEST(name, expr) do { \
    printf("  %s: ", name); \
    if (expr) { printf("PASS\n"); tests_passed++; } \
    else { printf("FAIL\n"); tests_failed++; } \
} while(0)

int main(void) {
    ID id1 = {100, {'A', 'A', 'B', 'C', '\0'}};
    ID id2 = {100, {'A', 'A', 'B', 'C', '\0'}};
    ID id3 = {200, {'X', 'Y', 'Z', 'W', '\0'}};

    int cmp_same = compara_id(id1, id2);
    TEST("compara_id same returns 0", cmp_same == 0);

    int cmp_diff = compara_id(id1, id3);
    TEST("compara_id different returns 1", cmp_diff == 1);

    ID id_same_letters = {999, {'A', 'A', 'B', 'C', '\0'}};
    int cmp_diff_num = compara_id(id1, id_same_letters);
    TEST("compara_id different number returns 1", cmp_diff_num == 1);

    ID id_same_num = {100, {'Z', 'Z', 'Z', 'Z', '\0'}};
    int cmp_diff_lett = compara_id(id1, id_same_num);
    TEST("compara_id different letters returns 1", cmp_diff_lett == 1);

    char buffer[30];
    memset(buffer, 0, sizeof(buffer));
    stampa_id(id1, buffer, sizeof(buffer));
    TEST("stampa_id formats correctly", strcmp(buffer, "AABC100") == 0);

    stampa_id(id1, NULL, 0);
    TEST("stampa_id NULL buffer with zero size does not crash", 1);

    List_Used_ID *list = malloc(sizeof(List_Used_ID));
    list->count = 0;
    list->first_id_used = NULL;

    int check1 = id_in_uso(id1, list);
    TEST("id_in_uso empty list returns 3", check1 == 3);

    ID_Usato *used1 = malloc(sizeof(ID_Usato));
    used1->id_used = id1;
    used1->next_id = NULL;
    list->count = 1;
    list->first_id_used = used1;

    int check2 = id_in_uso(id1, list);
    TEST("id_in_uso finds existing id", check2 == 0);

    int check3 = id_in_uso(id3, list);
    TEST("id_in_uso does not find absent id", check3 == 1);

    int check_null = id_in_uso(id1, NULL);
    TEST("id_in_uso NULL list returns 2", check_null == 2);

    free(used1);
    free(list);

    printf("\n%d passed, %d failed\n", tests_passed, tests_failed);
    return tests_failed > 0 ? 1 : 0;
}
