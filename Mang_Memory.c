#include "shell.h"

/**
 * free_env - Free Enviroment Variable Array
 * @env:  Environment variables.
 * Return: Void
 */

void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}

/**
 * all_free - Free Enviroment Variable Array
 * @cmd:  array Pointer.
 * @line: char pointer
 * Return: Void
 */

void all_free(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}

/**
 * _realloc - Reallocate your Memory
 * @ptr: Pointer
 * @old_size: previus Size Of the Pointer
 * @new_size: New Size Of the Pointer
 * Return: Void Pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		ptr = malloc(new_size);

	if (new_size == old_size)
		return (ptr);

	free(ptr);
	ptr = malloc(new_size);

	return (ptr);
}
