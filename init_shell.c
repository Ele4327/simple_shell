#include "shell.h"

/**
 * main - Simple Shell
 * @argc: argument count
 * @argv: argument values
 * Return: Value For Exit By Status
*/

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int counter = 0, statue = 1, st = 0;

	if (argv[1] != NULL)
		_read(argv[1], argv);
	signal(SIGINT, signal_line);
	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			prompter();
		input = _getline();
		if (input[0] == '\0')
		{
			continue;
		}
		history(input);
		cmd = _parsed(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_bul(cmd, input, argv, counter);
		}
		else if (check_builder(cmd) == 0)
		{
			st = builder_handling(cmd, st);
			all_free(cmd, input);
			continue;
		}
		else
		{
			st = check_command(cmd, input, counter, argv);
		}
		all_free(cmd, input);
	}
	return (statue);
}
