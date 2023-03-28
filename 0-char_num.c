#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

/**
 * count_format - counts the number of format specifiers in a string
 * format: string param
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
 * _printf - returns the number of characters printed (excluding the null byte used to end output to strings)
 * @format: string param containing all the format specifiers
 * Return: the number of characters
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, formatCount = count_format(format), countWithoutData = 0, totalCount = 0, dataCount = 0, formatState = 0;

	countWithoutData = strlen(format) - (2 * formatCount);

	va_start(ap, format);

	while (format[i] != '\0')
	{
			if (format[i] == '%')
			{
				if (format[i + 1] != '\0')
				{
					switch(format[i + 1])
					{
						case 'c':
							puts("Encountered a char\n");
							dataCount += 1;
							break;
						case 's':
						{
							int stringCount = 0;
							char *str_ptr = va_arg(ap, char *);

							puts("Encountered a string\n");


							while (*str_ptr != '\0')
							{
								str_ptr++;
								stringCount++;
							}

							dataCount += stringCount;
							break;
						}
					}
				}
			}

		i++;
	}

	totalCount = dataCount + countWithoutData;
	va_end(ap);

	printf("Count without data: %d\n", countWithoutData);
	printf("Data count: %d\n", dataCount);

	return (totalCount);
}

/* int main(void)
{
	int char_num = _printf("Hello %s%s%c", "world", "amazing", 'c');

	printf("Number of characters: %d\n", char_num);

	return (0);
} */
