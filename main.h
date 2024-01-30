#ifndef MAIN_H
#define MAIN_H


#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _putchar();
int _puts();
int _printf(const char *format, ...);
int printChar(va_list args);
int printStr(va_list args);


#endif
