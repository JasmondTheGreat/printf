#include "main.h"

/**
 * _printf - produces output according to a format
 *
 * @format: format string
 *
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	unsigned int count = 0;
	va_list args;


	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == 'c')
			{
				count += printChar(args);

				format++;
			}
			else if (*(format + 1) == 's')
			{
				count += printStr(args);

				format++;
			}
			else if (*(format + 1) == '%')
			{
				count += _putchar('%');

				format++;
			}
		}
		else
			count += _putchar(*format);

		format++;
	}

	va_end(args);

	return (count);
}
