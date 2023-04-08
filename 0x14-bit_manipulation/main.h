#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int print_character(char c);

unsigned int convert_binary_to_uint(const char *b);

void print_binary_number(unsigned long int n);

int get_bit_value(unsigned long int n, unsigned int index);

int set_bit_value(unsigned long int *n, unsigned int index);

int clear_bit_value(unsigned long int *n, unsigned int index);

unsigned int flip_binary_bits(unsigned long int n, unsigned long int m);

int get_system_endianness(void);

#endif
