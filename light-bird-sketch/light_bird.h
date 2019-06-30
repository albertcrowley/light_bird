#ifndef LIGHT_BIRD_H
#define LIGHT_BIRD_H


#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char f[8][8];
    int player_x;
    int gap;
    int shift;
} t_field ;


t_field create_field(int player_pos, int gap);
t_field tick(t_field field);
void field_to_bytes(t_field field, unsigned char* b);

void print_bits (unsigned char a);

void print_field (t_field field);
void add_row(t_field* field, int gap, int shift);


#ifdef __cplusplus
}
#endif

#endif
