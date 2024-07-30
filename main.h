#ifndef MAIN_H
#define MAIN_H
#include <stdio>
#include <unistd.h>

int _printf(const char *format, ...);

/*These are functions to print chars and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
        int flags, int width, int precision, int size);


int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);


#endif
