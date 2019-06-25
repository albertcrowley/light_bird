#include "light_bird.h"

t_field create_field(int player_pos, int gap) {
    t_field field;
    for (int y=0; y<8; y++){
        for (int x=0; x<8; x++) {
            field.f[x][y] = ' ';
        }
        field.f[0][y] = '*';
        field.f[7][y] = '*';
    }
    field.player_x = player_pos;
    field.gap = gap;
    field.shift = 1;
    return field;
}

t_field tick(t_field field) {
    t_field new;
    new.player_x = field.player_x;
    new.gap = field.gap;
    new.shift = field.shift;
    for (int y=1; y < 8; y++){
        for (int x=0; x<8; x++) {
            new.f[x][y-1] = field.f[x][y];
        }
    }

    for (int x=0; x< 8; x++) {
        new.f[x][7] = ' ';
    }

    return new;
}


//void set_gap(t_field* field, int gap, int row) {
//    int actual_gap = 0;
//    for (int x=0; x< 8; x++) {
//        if ((*field).f[x][row] == ' ') {
//            actual_gap++;
//        }
//    }
//
//
//    if (actual_gap > gap) {
//        for (int x =7; x> 0; x--) {
//            if ( (*field).f[x][row] == ' ') {
//                (*field).f[x][row] = '*';
//                // recurse to shrink larger gaps
//                set_gap(field,gap,row);
//                break;
//            }
//        }
//    }
//
//    if (actual_gap < gap) {
//        for (int x =1; x< 8; x++) {
//            if ( (*field).f[x][row] == '*') {
//                (*field).f[x][row] = ' ';
//                // recurse to grow larger gaps
//                set_gap(field,row,gap);
//                break;
//            }
//        }
//    }
//}

void add_row(t_field* field, int new_gap, int shift_delta) {
    unsigned char b[8];
    int TOPROW = 7;

    (*field).gap = new_gap;
    (*field).shift += shift_delta;

    for (int x=0; x<8; x++) (*field).f[x][TOPROW] = '*';

    for (int x=0; x<8; x++) {
        if (x < (*field).shift) continue;
        if (x < ((*field).shift + (*field).gap)){
            (*field).f[x][TOPROW] = ' ';
        }
    }

}



void field_to_bytes(t_field field, unsigned char* b) {

    for (int y=0; y < 8; y++){
        b[y] = 0;
        for (int x=0; x<8; x++) {
            b[y] = b[y] << 1;
            if (field.f[x][y] == '*') {
                b[y] = b[y] | 1;
            }
        }
    }


}
