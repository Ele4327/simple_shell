#include "shell.h"

/**
 * builder_handling - Handler Builder command.
 * @command: Line of the commmand tokenizer.
 * @status_er: Tipe of status of last execute
 * Return: -1 Fail or 0 if is Succes (Execute Building)
*/

int builder_handling(char **command, int status_er)
{
	unsigned int j;

	const_t cmds[] = {
		{"cd", ch_dir},
		{"env", enviro},
		{"help", _helper},
		{"echo", _echo},
		{NULL, NULL}};

	j = 0;

	while ((cmds + j)->command)
	{
		if (_strcmp(command[0], (cmds + j)->command) == 0)
			return ((cmds + j)->func(command, status_er));
		j++;
	}
	return (-1);
}
