#include "shell.h"

/**
 * errors_print - Dysplay Error Based in your command
 * @command: User Input
 * @counter: Excecution Time Loop
 * @argv: Name Of The Program
 * Return: Void
 */

void errors_print(char *command, int counter, char **argv)
{
	char *errors;

	_PRINT(argv[0]);
	_PRINT(": ");
	errors = _itoa(counter);
	_PRINT(errors);
	free(errors);
	_PRINT(": ");
	_PRINT(command);
	_PRINT(": not found\n");
}

/**
 * Exit_Shell - Exit Shell in Case Of File
 * @command: line of the command tokenizer
 * @buff: Buff from File Descriptor
 * @fd: File Descriptor
 * Return: In case Of Exit in A File Line
 */

void Exit_Shell(char **command, char *buff, FILE *fd)
{
	int status, i = 0;

	if (command[1] == NULL)
	{
		free(buff);
		free(command);
		fclose(fd);
		exit(errno);
	}
	while (command[1][i])
	{
		if (_isalpha(command[1][i++]) < 0)
			perror("illegal number");
	}
	status = atoi(command[1]);
	free(buff);
	free(command);
	fclose(fd);
	exit(status);
}

/**
 * exit_bul - Exit Status Shell
 * @command: line of the command tokenizer
 * @buff: Buff from File Descriptor
 * @argv: Name from Program
 * @counter: Execute counter
 * Return: Void
 */

void exit_bul(char **command, char *buff, char **argv, int counter)
{
	int status, i = 0;

	if (command[1] == NULL)
	{
		free(buff);
		free(command);
		exit(EXIT_SUCCESS);
	}
	while (command[1][i])
	{
		if (_isalpha(command[1][i++]) != 0)
		{
			_perror(argv, counter, command);
			break;
		}
		else
		{
			status = atoi(command[1]);
			free(buff);
			free(command);
			exit(status);
		}
	}
}

/**
 * _perror - Printer Customizer Errors
 * @argv: Name from Program
 * @command: line of the command tokenizer
 * @counter: Execute error counter
 * Return: Void
 */

void _perror(char **argv, int counter, char **command)
{

	char *errors = _itoa(counter);

	_PRINT(argv[0]);
	_PRINT(": ");
	_PRINT(errors);
	_PRINT(": ");
	_PRINT(command[0]);
	_PRINT(": illegal number: ");
	_PRINT(command[1]);
	_PRINT("\n");
	free(errors);
}
