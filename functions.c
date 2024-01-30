#include "main.h"

/**
 * _putchar - prints a character
 *
 * @c: char param
 *
 * Return: 1
 */
int _putchar(int c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string
 *
 * @s: pointer to first character of string
 *
 * Return: number of chars printed
 */
int _puts(char *s)
{
	int count = 0;

	if (s)
	{
		while (*s)
		{
			_putchar(*s);
			s++;
			count++;
		}
	}

	return (count);
}

/**
 * printChar - handles %c
 *
 * @args: argument pointer
 *
 * Return: 1
 */
int printChar(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}

/**
 * printStr - handles %s
 *
 * @args: argument pointer
 *
 * Return: num of chars printed
 */
int printStr(va_list args)
{
	char *s = va_arg(args, char *);

	return (_puts(s));
}
