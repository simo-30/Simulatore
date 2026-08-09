#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "archivio.h"
#include "../Punto/punto.h"

static int tests_passed = 0;
static int tests_failed = 0;

#define TEST(name, expr) do { \
    printf("  %s: ", name); \
    if (expr) { printf("PASS\n"); tests_passed++; } \
    else { printf("FAIL\n"); tests_failed++; } \
} while(0)

int main(void) {
    const char *test_file = "test_creato.txt";

    TEST("esiste_file returns false for nonexistent", esiste_file(test_file) == false);

    int ret = crea_file_archivio(test_file);
    TEST("crea_file_archivio returns 0", ret == 0);
    TEST("esiste_file returns true after creation", esiste_file(test_file) == true);

    remove(test_file);

    Header_List_Punto h = init_header_list_punto();
    Punto p1 = crea_punto(10, 20, 30, &h);
    Item_List_Punto *item1 = init_item_list_punto(p1);
    append_item_punto(&h, item1);

    Punto p2 = crea_punto(40, 50, 60, &h);
    Item_List_Punto *item2 = init_item_list_punto(p2);
    append_item_punto(&h, item2);

    remove(PATH_ARCHIVIO_PUNTI);
    int wr = write_file_archivio_punti(h);
    TEST("write_file_archivio_punti returns 0", wr == 0);
    TEST("punti.txt exists after write", esiste_file(PATH_ARCHIVIO_PUNTI) == true);

    Header_List_Punto read_h = leggi_file_archivio_punti();
    TEST("leggi_file_archivio_punti returns header", read_h.count == 0);
    TEST("leggi_file_archivio_punti first_p NULL (stub)", read_h.first_p == NULL);

    printf("\n%d passed, %d failed\n", tests_passed, tests_failed);
    return tests_failed > 0 ? 1 : 0;
}
