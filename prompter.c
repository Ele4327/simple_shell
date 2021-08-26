#include "shell.h"

/**
 * prompter - Display Shell Prompt
*/

void prompter(void)
{
	_PRINT("$ ");
}

/**
 * signal_line - Handle ^C
 * @signal: Recept Capture
*/

void signal_line(int signal)
{
	if (signal == SIGINT)
	{
		_PRINT("\n$ ");
	}
}

/**
 * hashtag_handle - Remove Everithing after #
 * @buff: User Input
 * Return: Void
*/

void hashtag_handle(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#')
		{
			buff[i] = '\0';
			break;
		}
	}
}

/**
 * _getline - Read the Input
 * Return: Input
*/

char *_getline(void)
{
	int i, buffsize = BUFFSIZE, rd;
	char c = 0;
	char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[i] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (i >= buffsize)
		{
			buff = _realloc(buff, buffsize, buffsize + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[i] = '\0';
	hashtag_handle(buff);
	return (buff);
}

/**
 * _echo_p - Excute Normal Echo
 * @cmd: Parsed Command
 * Return: 0 Succes -1 Fail
 */
int _echo_p(char **cmd)
{
	pid_t pid;
	int status;

	pid = pids_Son(*cmd);
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
