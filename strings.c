#include "shell.h"

/* Integer to ASCII for signed decimal integers. */
static int next;
static char qbuf[8];

/**
 * _itoa - Functions changes un number to strings
 * @n: numberto change
 * Return: qbuf
 */

char *_itoa(int n)
{
	register int r, k;
	int flag = 0;

	next = 0;
	if (n <= 0)
	{
		qbuf[next++] = '-';
		n = -n;
	}
	if (n == 0)
	{
		qbuf[next++] = '0';
	}
	else
	{
		k = 10000;
		while (k > 0)
		{
			r = n / k;
			if (flag || r > 0)
			{
				qbuf[next++] = '0' + r;
				flag = 1;
			}
			n -= r * k;
			k = k / 10;
		}
	}
	qbuf[next] = '\n';
	return (qbuf);
}

/**
 * strlenR - Functions copy values
 * @str: Destine of de buffer.
 * @counter: addres of the string search.
 * Return: If size == 0 or the function fails - NULL.
 *         Otherwise - a pointer to the array.
 */

int strlenR(char *str, int counter)
{

	if (!(*str))
	{
		return (counter);
	}
	else
	{
		return (strlenR(str + 1, counter + 1));
	}
}

/**
 * _strcmp - Compare two strings
 * @strings: Buffer 1.
 * @string: Buffer 2 to compare.
 * Return: Pointer whit object the compare.
 */

int _strcmp(char *strings, char *string)
{
	int i = 0;
	int compare = 0;

	if (strings == NULL || string == NULL)
		return (1);

	if (strlen(strings) != strlen(string))
		return (1);

	for (i = 0; strings[i]; i++)
	{
		if (strings[i] != string[i])
		{
			compare = strings[i] - string[i];
			break;
		}
		else
		{
			continue;
		}
	}
	return (compare);
}

/**
 * _isalpha - Compare strings if this is uppercase
 * @c: Buffer counter.
 * Return: 0
 */

int _isalpha(int c)
{
	if (((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122)))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}