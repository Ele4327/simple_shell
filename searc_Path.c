#include "shell.h"

/**
 * _getenv- Gets all Values of The Environment
 * @name: name of the var of the PATH.
 * Return: 0
*/

char *_getenv(char *name)
{
	size_t nulo, valor;
	char *value;
	int x, y, z;

	nulo = strlen(name);

	for (x = 0; environ[x]; x++)
	{
		if (strncmp(name, environ[x], nulo) == 0)
		{
			valor = strlen(environ[x]) - nulo;
			value = malloc(sizeof(char) * valor);

			if (!value)
			{
				free(value);
				perror("unable to allocate");
				return (NULL);
			}

			z = 0;
			for (y = nulo + 1; environ[x][y]; y++, z++)
			{
				value[z] = environ[x][y];
			}
			value[z] = '\0';

			return (value);
		}
	}
	return (NULL);
}

/**
 * path - Search in the $PATH commands executables
 * @command: Command for execute.
 * Return: 0 if procces is succes or -1 if is failed.
*/

int path(char **command)
{
	char *path_command;
	char *path = _getenv("PATH");
	char *tokenizado = strtok(path, ":");
	struct stat buffer;

	while (tokenizado != NULL)
	{
		path_command = builder(*command, tokenizado);
		if (stat(path_command, &buffer) == 0)
		{
			*command = strdup(path_command);
			free(path_command);
			free(path);
			return (0);
		}
		free(path_command);
		tokenizado = strtok(NULL, ":");
	}
	free(path);

	return (1);
}

/**
 * builder - Building commmand
 * @token: Command Executable.
 * @token_value: Dir what is contain command
 * Return: command
*/

char *builder(char *token, char *token_value)
{
	char *command;
	size_t lenght;

	lenght = strlen(token_value) + strlen(token_value) + 2;
	command = malloc(sizeof(char) * lenght);

	if (command == NULL)
		return (NULL);

	memset(command, 0, lenght);
	command = strcat(command, token_value);
	command = strcat(command, "/");
	command = strcat(command, token);

	return (command);
}

/**
 * new_environ - Create New Array ode Environment
 * @envir: Array of the environ.
 * Return: void
*/

void new_environ(char **envir)
{
	int i = 0;

	while (environ[i])
	{
		envir[i] = strdup(environ[i]);
		i++;
	}
	envir[i] = NULL;
}
