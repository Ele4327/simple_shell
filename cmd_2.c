#include "shell.h"

/**
 * _setenv - Dysplay Information on the Shell Builder Command setenv
 * @command: line of the command tokenizer
 * @status_er: Name Of The Program
 * Return: 1 in Case this command is NULL or 0 wrong command Execute
*/

int _setenv(char **command, __attribute__((unused)) int status_er)
{
	char *msg = "setenv: setenv [VARIABLE][VALUE]\n\tInitializes a new";

	_PRINT(msg);
	msg = "environment variable, or modifies an existing one.\n\n";
	_PRINT(msg);
	msg = "\tUpon failure, prints a message to stderr.\n";
	_PRINT(msg);
	(void)command;
	return (0);
}
