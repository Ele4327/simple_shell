#include "shell.h"

/**
 * manage_file - Token , check commmand Fork wait execute Line of File.
 * @buff: line of the commmand parced.
 * @counter: counter
 * @fd: file to file descriptor.
 * @argv: Values of the arguments
 * Return: Line Void Exe
*/

void manage_file(char *buff, int counter, FILE *fd, char **argv)
{
	char **command;
	int status = 0;

	command = _parsed(buff);

	if (strncmp(command[0], "exit", 4) == 0)
	{
		Exit_Shell(command, buff, fd);
	}
	else if (check_builder(command) == 0)
	{
		status = builder_handling(command, status);
		free(command);
	}
	else
	{
		status = check_command(command, buff, counter, argv);

		free(command);
	}
}

/**
 * _read - Reading commands From Files
 * @filename: line file descriptor.
 * @argv: Values of the arguments
 * Return: 0
*/

void _read(char *filename, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filename, "r");
	if (!fp)
	{
		while ((getline(&line, &len, fp)) != -1)
		{
			counter++;
			manage_file(line, counter, fp, argv);
		}
		if (line)
			free(line);
		fclose(fp);
		exit(0);
	}
	exit(EXIT_FAILURE);
}
