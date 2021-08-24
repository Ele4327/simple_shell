#include "shell.h"

/**
 * check_builder - Builder Function Checker
 * @command: Line of the commmand to check.
 * Return: 0 Succes -1 fail
*/

int check_builder(char **command)
{
	const_t func[] = {
		{"cd", NULL},
		{"env", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}};

	int _check = 0;

	if (*command == NULL)
		return (-1);
	while ((func + _check)->command)
	{
		if (_strcmp(command[0], (func + _check)->command) == 0)
			return (0);
		_check++;
	}
	return (-1);
}
