#include "shell.h"

/**
 * _printf - prints the string passed in any
 *              function
 * @fd: file descriptor to print to be printed on
 * @format: string being passed to be printed
 *
 * Return: always returns the char count on succeess
 */

int _printf(int fd, const char *format, ...)
{

	va_list vat;
	int len;

	len = 0;
	if (format == NULL || vat == NULL)
		return (-1);
	va_start(vat, format);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			_putchar(fd, *format);
			format++;
			len++;
			continue;
		}
		else if (*format == '\0')
			break;
		len += print_conv(fd, format, vat);
		format++;
		format++;
	}
	va_end(vat);
	return (len);
}

/**
 * _puts - Prints the subject string using _putchar
 * @fd: it is the file descriptor to print to
 * @str:	Input string
 *
 * Return: always returning the string printed on success
 */
void _puts(int fd, char *str)
{
	while (*str != '\0')
	{
		_putchar(fd, *str);
		str++;
	}
}

/**
 * _putchar - writes char to stdout better known
 *              as standard output
 * @fd: file descriptor you have
 *          to print to
 * @c: input character
 *
 * Return: Char printed to stdout;
 */
int _putchar(int fd, char c)
{
	return (write(fd, &c, 1));
}

/**
 * print_conv - takes string and
 *              use correct conversion
 * @fd: file descriptor to print to
 * @str: input string
 * @arg: input argument from list
 *
 * Return: It will always return the count
 *          on success
 */

int print_conv(int fd, const char *str, va_list arg)
{
	int count, c;
	char *s = malloc(sizeof(str));

	count = 0;
	str++;
	switch (*str)
	{
		case 's':
			count = (print_s(fd, arg));
			free(s);
			return (count);
		case 'c':
			c = va_arg(arg, int);
			_putchar(fd, c);
			count++;
			free(s);
			return (count);
		case 'd':
			s = _itoa(va_arg(arg, int), s, 10);
			_puts(fd, s);
			count += _strlen(s);
			free(s);
			return (count);
		case 'i':
			s = _itoa(va_arg(arg, int), s, 10);
			_puts(fd, s);
			count += _strlen(s);
			free(s);
			return (count);
		default:
			_putchar(fd, '%');
			_putchar(fd, *str);
			count = 2;
			free(s);
			return (count);
	}
}

/**
 * print_s - prints the string
 *          after conversion specifier
 * @fd: subject file descriptor to print to
 * @arg: input argument
 *
 * Return: always returns
 *          length of string on success
 */

int print_s(int fd, va_list arg)
{
	char *s;
	int count;

	s = va_arg(arg, char *);
	if (s == NULL)
		return (0);
	_puts(fd, s);
	count = _strlen(s);
	return (count);
}
