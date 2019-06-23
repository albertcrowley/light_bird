#include <stdio.h>

#include "light-bird-sketch/light_bird.h"

int fail = 0;

void assert(int b, char * msg) {
    if (!b) {
        printf("*****************\n");
        printf(msg);
        printf("\n*****************\n");
        fail++;
    }
}



void test_byes() {
    unsigned char b[8];
    t_field field = create_field(3);
//    print_field(field);
    field_to_bytes(field, b);
//    print_bits(b[1]);
    assert(b[1] == 129, "byte transform failed");
}

void test_scroll() {
    unsigned char b[8];

    t_field field = create_field(3);
//    field = tick(field);
//    add_row(&field, 6, 0);
////    field_to_bytes(field, b); print_bits(b[7]);
//
//    assert(field.f[0][7] == '*', "byte transform failed 1");
//    assert(field.f[1][7] == ' ', "byte transform failed 2");
//    assert(field.f[6][7] == ' ', "byte transform failed 3");
//    assert(field.f[7][7] == '*', "byte transform failed 4");
//
//    field = create_field(3);
//    field = tick(field);
////    field_to_bytes(field, b); print_bits(b[7]);
//    add_row(&field, 6, 1);
////    field_to_bytes(field, b); print_bits(b[7]);
//    assert(field.f[0][7] == '*', "shift byte transform failed 1");
//    assert(field.f[1][7] == '*', "shift byte transform failed 2");
//    assert(field.f[2][7] == ' ', "shift byte transform failed 3");
//    assert(field.f[6][7] == ' ', "shift byte transform failed 4");
//    assert(field.f[7][7] == ' ', "shift byte transform failed 5");
//
//
//    field = create_field(3);
//    field = tick(field);
////    field_to_bytes(field, b); print_bits(b[7]);
//    add_row(&field, 5, 1);
////    field_to_bytes(field, b); print_bits(b[7]);
//    assert(field.f[0][7] == '*', "2 shift byte transform failed 1");
//    assert(field.f[1][7] == '*', "2 shift byte transform failed 2");
//    assert(field.f[2][7] == ' ', "2 shift byte transform failed 3");
//    assert(field.f[3][7] == ' ', "2 shift byte transform failed 4");
//    assert(field.f[4][7] == ' ', "2 shift byte transform failed 5");
//    assert(field.f[5][7] == ' ', "2 shift byte transform failed 6");
//    assert(field.f[6][7] == ' ', "2 shift byte transform failed 7");
//    assert(field.f[7][7] == '*', "2 shift byte transform failed 8");

    field = create_field(3);
    field = tick(field);
//    field_to_bytes(field, b); print_bits(b[7]);
    add_row(&field, 3,-1);
//    field_to_bytes(field, b); print_bits(b[7]);
    assert(field.f[0][7] == ' ', "2 shift byte transform failed 1");
    assert(field.f[1][7] == ' ', "2 shift byte transform failed 2");
    assert(field.f[2][7] == ' ', "2 shift byte transform failed 3");
    assert(field.f[3][7] == '*', "2 shift byte transform failed 4");
    assert(field.f[4][7] == '*', "2 shift byte transform failed 5");
    assert(field.f[5][7] == '*', "2 shift byte transform failed 6");
    assert(field.f[6][7] == '*', "2 shift byte transform failed 7");
    assert(field.f[7][7] == '*', "2 shift byte transform failed 8");

    field_to_bytes(field, b); print_bits(b[7]);
    field = tick(field);
    add_row(&field, 3,1);
    field_to_bytes(field, b); print_bits(b[7]);
    assert(field.f[0][7] == '*', "3 shift byte transform failed 1");
    assert(field.f[1][7] == ' ', "3 shift byte transform failed 2");
    assert(field.f[2][7] == ' ', "3 shift byte transform failed 3");
    assert(field.f[3][7] == ' ', "3 shift byte transform failed 4");
    assert(field.f[4][7] == '*', "3 shift byte transform failed 5");
    assert(field.f[5][7] == '*', "3 shift byte transform failed 6");
    assert(field.f[6][7] == '*', "3 shift byte transform failed 7");
    assert(field.f[7][7] == '*', "3 shift byte transform failed 8");


    field = tick(field);
    add_row(&field, 4,0);
    field_to_bytes(field, b); print_bits(b[7]);
    assert(field.f[0][7] == '*', "4 shift byte transform failed 1");
    assert(field.f[1][7] == ' ', "4 shift byte transform failed 2");
    assert(field.f[2][7] == ' ', "4 shift byte transform failed 3");
    assert(field.f[3][7] == ' ', "4 shift byte transform failed 4");
    assert(field.f[4][7] == ' ', "4 shift byte transform failed 5");
    assert(field.f[5][7] == '*', "4 shift byte transform failed 6");
    assert(field.f[6][7] == '*', "4 shift byte transform failed 7");
    assert(field.f[7][7] == '*', "4 shift byte transform failed 8");

}

int main() {

    t_field field = create_field(3);

    assert(field.f[2][7] == ' ', "not empty spot in field");
    assert(field.f[3][0] == ' ', "not empty spot in field");
    assert(field.f[7][5] == '*', "expected * on edge");
    assert(field.player_x == 3, "player not in right spot!");


    field = create_field(3);
    field.f[5][5] = '*';
    t_field field_prime = tick(field);
    assert(field_prime.player_x == 3, "player not in right spot!");
    assert(field_prime.f[5][5] == ' ', "not empty spot in field");
    assert(field_prime.f[0][0] == '*', "expected * on edge");
    assert(field_prime.f[7][7] == ' ', "not empty spot in field");
    assert(field_prime.f[5][4] == '*', "expected * to move down");

    test_byes();
    test_scroll();

    if (fail > 0) {
        printf ("%i test failures\n", fail);
    } else {
        printf("All tests pass\n");
    }




    return 0;
}