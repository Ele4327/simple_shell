#include "shell.h"

/**
 * ch_dir -  Change Directory
 * @command: Line of the commmand Parsed.
 * @status_err: Tipe of status of last execute
 * Return: 0 Succes or 1 in case Failed
*/

int ch_dir(char **command, __attribute__((unused)) int status_err)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (command[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(command[1], "-") == 0)
	{
		value = chdir(getenv("OLDPWD"));
	}
	else
		value = chdir(command[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}

/**
 * enviro -  Dysplay Environment
 * @cmd: Line of the commmand Parsed.
 * @err: Tipe of status of last execute
 * Return: 0 Succes always
*/

int enviro(__attribute__((unused)) char **cmd, __attribute__((unused)) int err)
{
	ssize_t i = 0;
	int length;

	while (environ[i] != NULL)
	{
		length = strlen(environ[i]);
		write(1, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}

/**
 * _helper -  Dysplay document of the Help
 * @command: Line of the commmand Parsed.
 * @status_er: Tipe of status of last execute
 * Return: 0 Succes or -1 if failed
*/

int _helper(char **command, __attribute__((unused)) int status_er)
{
	int filename, file_write, read_descriptor = 1;
	char c;

	filename = open(command[1], O_RDONLY);
	if (filename < 0)
	{
		perror("Error");
		return (0);
	}
	while (read_descriptor > 0)
	{
		read_descriptor = read(filename, &c, 1);
		file_write = write(STDOUT_FILENO, &c, read_descriptor);
		if (file_write < 0)
			return (-1);
	}
	_putchar('\n');
	return (0);
}

/**
 * _echo - Excute Echo Cases
 * @st:Statue Of Last Command Excuted
 * @cmd: Parsed Command
 * Return: Always 0 Or Excute Normal Echo
 */
int _echo(char **cmd, int st)
{
	char *path;
	unsigned int pid = getppid();

	if (strncmp(cmd[1], "$?", 2) == 0)
	{
		print_num_in(st);
		_PRINT("\n");
	}
	else if (strncmp(cmd[1], "$$", 2) == 0)
	{
		print_num(pid);
		_PRINT("\n");
	}
	else if (strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		_PRINT(path);
		_PRINT("\n");
		free(path);
	}
	else
		return (_echo_p(cmd));

	return (1);
}
