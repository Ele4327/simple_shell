#include "shell.h"

/**
 * check_command - Running simple commands of the shell
 * @command: line of the command tokenizer
 * @input: User Input
 * @counter: Excecution Time in case of command not found
 * @argv: Name Of The Program
 * Return: 1 in Case this command is NULL or 0 wrong command Execute
*/

int check_command(char **command, char *input, int counter, char **argv)
{
	int status;
	pid_t pid;

	if (*command == NULL)
		return (-1);
	pid = pids_Son(*command);
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (strncmp(*command, "./", 2) != 0 && strncmp(*command, "/", 1) != 0)
			path(command);

		if (execve(*command, command, environ) == -1)
		{
			errors_print(command[0], counter, argv);
			free(input);
			free(command);
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
