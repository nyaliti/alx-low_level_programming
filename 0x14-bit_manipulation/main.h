#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stddef.h>


unsigned int convert_binary_to_uint(const char *x);
int validate_binary_string(const char *x);
int print_character(char y);
void display_binary(unsigned long int z);
int get_bit_at_index(unsigned long int z, unsigned int index);
int set_bit_at_index(unsigned long int *z, unsigned int index);
int clear_bit_at_index(unsigned long int *z, unsigned int index);
unsigned int count_different_bits(unsigned long int z, unsigned long int w);
int determine_endianness(void);


#endif
