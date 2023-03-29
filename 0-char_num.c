#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

/**
 * count_format - counts the number of format specifiers in a string
 * @format: string param
 * Return: number of format specifiers
 */

int count_format(const char *format)
{
	int formatCount = 0;

	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == 'c' || *(format + 1) == 's')
			{
				formatCount++;
			}
		}

		format++;
	}

	return (formatCount);
}


/**
 * get_str_len - gets the length of a string
 * @str: string param
 * Return: length of string
 */

int get_str_len(char *str)
{
	int stringCount = 0;

	while (*str != '\0')
	{
		str++;
		stringCount++;
	}
	return (stringCount);
}


/**
 * _printf - returns the number of characters printed
 * (excluding the null byte used to end output to strings)
 *
 * @format: string param containing all the format specifiers
 *
 * Return: the number of characters
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, formatCount = count_format(format), countWithoutData = 0,
	totalCount = 0, dataCount = 0, formatState = 0;

	countWithoutData = strlen(format) - (2 * formatCount);

	va_start(ap, format);

	while (format[i] != '\0')
	{
		putchar(format[i]);

		if (format[i] == '%' && format[i + 1] != '\0')
		{
			switch (format[i + 1])
			{
			case 'c':
			{
				dataCount += 1;
				putchar(va_arg(ap, int));

				break;
			}
			case 's':
			{
				char *string = va_arg(ap, char *);
				dataCount += get_str_len(va_arg(ap, char *));

				int i = 0;

				while (string[i] != '\0')
				{
					putchar(string[i]);
					i++;
				}

				break;
			}
			}
		}
		i++;
	}

	totalCount = dataCount + countWithoutData;
	va_end(ap);

	return (totalCount);
}

int main(void)
{
	_printf("Hello, I'm %s and my initial is %c\n", "Obafemi", 'O');
}
