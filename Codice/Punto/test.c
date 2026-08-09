#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "punto.h"
#include "../Archivio/archivio.h"

static int tests_passed = 0;
static int tests_failed = 0;

#define TEST(name, expr) do { \
    printf("  %s: ", name); \
    if (expr) { printf("PASS\n"); tests_passed++; } \
    else { printf("FAIL\n"); tests_failed++; } \
} while(0)

int main(void) {
    srand(42);

    Header_List_Punto h = init_header_list_punto();
    TEST("init_header_list_punto count zero", h.count == 0);
    TEST("init_header_list_punto first_p NULL", h.first_p == NULL);

    Punto p1 = crea_punto(10, 20, 30, &h);
    TEST("crea_punto id", p1.id == 1);
    TEST("crea_punto x", p1.x == 10);
    TEST("crea_punto y", p1.y == 20);
    TEST("crea_punto z", p1.z == 30);

    Punto p_rand = crea_punto_random(&h);
    TEST("crea_punto_random id is positive", p_rand.id > 0);

    printf("  stampa_punto (manual check):\n");
    stampa_punto(p1);

    Header_List_Punto h2 = init_header_list_punto();
    Item_List_Punto *item1 = init_item_list_punto(p1);
    TEST("init_item_list_punto not null", item1 != NULL);
    TEST("init_item_list_punto p matches", item1->p.id == p1.id);
    TEST("init_item_list_punto next_p NULL", item1->next_p == NULL);

    append_item_punto(&h2, item1);
    TEST("append_item_punto count = 1", h2.count == 1);
    TEST("append_item_punto first_p set", h2.first_p != NULL);
    TEST("append_item_punto first_p id matches", h2.first_p->p.id == p1.id);

    Punto p2 = crea_punto(5, 5, 5, &h2);
    Item_List_Punto *item2 = init_item_list_punto(p2);
    append_item_punto(&h2, item2);
    TEST("append_item_punto count = 2", h2.count == 2);
    TEST("append_item_punto second item reachable", h2.first_p->next_p != NULL);
    TEST("append_item_punto second item id matches", h2.first_p->next_p->p.id == p2.id);

    Punto sum = somma_punti(p1, p2);
    TEST("somma_punti x (10+5 mod 1000)", sum.x == 15);
    TEST("somma_punti y (20+5 mod 1000)", sum.y == 25);
    TEST("somma_punti z (30+5 mod 1000)", sum.z == 35);
    TEST("somma_punti id is max", sum.id == (p1.id > p2.id ? p1.id : p2.id));

    Header_List_Punto h3 = init_header_list_punto();
    init_first_item(&h3);
    TEST("init_first_item allocates first_p", h3.first_p != NULL);

    Punto p3 = crea_punto(99, 99, 99, &h3);
    Item_List_Punto *item3 = init_item_list_punto(p3);
    add_first_punto(&h3, item3);
    TEST("add_first_punto count = 1", h3.count == 1);
    TEST("add_first_punto first_p matches", h3.first_p->p.id == p3.id);

    Header_List_Punto h4 = init_header_list_punto();
    int id1 = get_id_punto(&h4);
    TEST("get_id_punto empty list returns 1", id1 == 1);

    Punto dummy = crea_punto(0, 0, 0, &h4);
    Item_List_Punto *dummy_item = init_item_list_punto(dummy);
    append_item_punto(&h4, dummy_item);
    int id2 = get_id_punto(&h4);
    TEST("get_id_punto after one append returns 2", id2 == 2);

    int id_null = get_id_punto(NULL);
    TEST("get_id_punto NULL header returns 0", id_null == 0);

    append_item_punto(NULL, NULL);
    TEST("append_item_punto NULL args does not crash", 1);

    add_first_punto(NULL, NULL);
    TEST("add_first_punto NULL args does not crash", 1);

    printf("\n%d passed, %d failed\n", tests_passed, tests_failed);
    return tests_failed > 0 ? 1 : 0;
}
