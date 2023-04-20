#ifndef MAIN_H
#define MAIN_N

#include <elf.h>                // library that provides definitions for the ELF file format
#include <stdlib.h>             // library for general purpose functions such as memory allocation and exit()
#include <stdio.h>              // library for standard input and output functions such as printf()
#include <unistd.h>             // library for various constant, type and function declarations that provide access to POSIX compliant API
#include <fcntl.h>              // library for performing various operations on files like open(), read(), write() etc.
#include <sys/types.h>          // library for various data types used in system calls
#include <sys/stat.h>           // library for defining the structure of data returned by system calls

ssize_t read_textfile(const char *filename, size_t letters);           // function to read and print a text file
int create_file(const char *filename, char *text_content);             // function to create a file and write text content to it
int append_text_to_file(const char *filename, char *text_content);     // function to append text content to an existing file

/**
 * ELF header functions
*/
void check_elf(unsigned char *e_ident);                   // function to check if a given file is an ELF file
void print_magic(unsigned char *e_ident);                  // function to print the magic numbers in the ELF header
void print_class(unsigned char *e_ident);                  // function to print the class of the ELF file
void print_data(unsigned char *e_ident);                   // function to print the data encoding of the ELF file
void print_version(unsigned char *e_ident);                // function to print the version of the ELF file
void print_abi(unsigned char *e_ident);                     // function to print the ABI of the ELF file
void print_osabi(unsigned char *e_ident);                   // function to print the OSABI of the ELF file
void print_type(unsigned int e_type, unsigned char *e_ident); // function to print the type of the ELF file
void print_entry(unsigned long int e_entry, unsigned char *e_ident); // function to print the entry point of the ELF file
void close_elf(int elf);                                    // function to close an ELF file

#endif

