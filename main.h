#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct type - conversion specifiers
 * @print: pointer to print
 * @identifier: conversion specifier
 */
typedef struct type
{
	char *identifier;
	int (*print)(va_list);
} type_t;

int _printf(const char *format, ...);
int (*get_char(const char *specifier))(va_list);
int _putchar(char c);
int c_print(va_list args);
int s_print(va_list args);
/**int o_print(va_list args);*/
int d_print(va_list args);
int b_print(va_list args);
int x_print(va_list args);
int X_print(va_list args);
/*int p_print(va_list args);*/
int u_print(va_list args);
/*int print_F(va_list args);*/
int countOctal(unsigned int num);
int countDigits(unsigned int num);
int countBinary(unsigned int numb);
int numb_print(unsigned int n);
/*int rot13(va_list args);
int rev_print(va_list args);
int _strlen(char *);*/
void lowerHex_print(unsigned int numb, int *num_bytes);
void upperHex_print(unsigned int numb, int *num_bytes);
/*void print_pointer(unsigned long ptr, int *count);
*/
#endif
