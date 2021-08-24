#include "shell.h"

/**
 * _parsed - Tokenize the line of Input
 * @input: Pointer to Token or parsed
 * Return: Double Array Of The Pointer
*/

char **_parsed(char *input)
{
	char **tokens;
	char *token;
	int i = 0;

	if (input == NULL)
		return (NULL);

	tokens = malloc(sizeof(char *) * BUFFSIZE);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}
	token = strtok(input, "\n ");
	for (; token; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * print_num -Print Unsigned Int Putchar
 * @n: Unisigned Integer
 * Return: Void
 */
void print_num(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_num(x / 10);

	_putchar(x % 10 + '0');
}
/**
 * print_num_in -Print Number Putchar
 * @n:Integer
 * Return: void
 */
void print_num_in(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_num(x / 10);

	_putchar(x % 10 + '0');
}
