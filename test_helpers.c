//
// Created by al on 6/23/2019.
//

#include "test_helpers.h"


void print_field (t_field field) {
    for (int y = 0; y < 8; y++) {
        printf("|");
        for (int x=0; x<8; x++) {
            printf("%c", field.f[x][y]);
        }
        printf("|\n");
    }
    printf("\n");
}


void print_bits (unsigned char a) {
    int i;
    for (i = 0; i < 8; i++) {
        printf("%d", !!((a << i) & 0x80));
    }
    printf("\n");
}

