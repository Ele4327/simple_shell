#ifndef SHELL_H
#define SHELL_H

/**## LIBRARIES*/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/errno.h>
#include <sys/fcntl.h>
#include <linux/limits.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**##Var of the Enviroment */
extern char **environ;

/**##Var MAKROS recordar recomendacion de prototypo es en UPPERCASE*/
#define _PRINT(c) write(STDOUT_FILENO, c, strlen(c))
#define BUFFSIZE 1024
#define DELIMITS "\t\r\a\n"

/**
* struct constructor - singly linked list
* @command: value of the commands in the pointer
* @func: this is pointer to functions
*/

typedef struct constructor
{
	char *command;
	int (*func)(char **va_list, int error);
} const_t;

/**
* struct pid_Father - List process father
* @text: text helper
* @file: name filedescriptor
* @name_command: Name of the command
* @pid: value for new process
* @text_pid: string contain value in text of the pid
* @next: Pointer to next structure
*/

typedef struct pid_Father
{
	char *text;
	char *file;
	char *name_command;
	pid_t pid;
	char *text_pid;
	struct pid_Father *next;

} pid_Father_t;

/**
* struct pid_Son - List process Son
* @text: text helper
* @file: name filedescriptors
* @name_command: Name of the command
* @pid: value for new process
* @text_pid: string contain value in text of the pid
* @next: Pointer to next structure
*/

typedef struct pid_Son
{
	char *text;
	char *file;
	char *name_command;
	pid_t pid;
	char *text_pid;
	struct pid_Son *next;
} pid_Son_t;

/**
* struct __pids_t - Pid var global
* @pid_p: pid Father
* @pid_s: pid Son
*/

typedef struct __pids_t
{
	pid_Father_t **pid_p;
	pid_Son_t **pid_s;
} _pids_t;

/**       PROTOTYPES        **/

/** STRING_FUNCTIONS**/
char *_itoa(int n);
int _atoi(char *s);
char **_parsed(char *input);
int strlenR(char *str, int counter);
int _strlen(char *s);
int len(char *str);
int _strcmp(char *string1, char *string2);
int _isalpha(int c);
void print_num_in(int n);
void print_num(unsigned int n);
int _putchar(char c);
void _puts(char *str);
char *_strtok(char *str, const char *delim);
unsigned int check_delim(char c, const char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strdup(char *str);
int _strncmp(const char *s1, const char *s2, size_t n);

/** PROMPT_FUNCTIONS**/
void prompter(void);
void signal_line(int signal);
void hashtag_handle(char *buff);
char *_getline(void);

/** FILES_MANAGEMENT_FUNCTIONS**/
void manage_file(char *buff, int counter, FILE *fd, char **argv);
void _read(char *filename, char **argv);

int history(char *input);

/** MEMORY_MANAGEMENT_FUNCTIONS**/
void free_env(char **env);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void all_free(char **cmd, char *line);

/** PROCESS_FUNCTIONS**/
int builder_handling(char **command, int status_er);
int get_process(void);
int pids_Son(char *cmd);
int check_builder(char **command);
int new_process(char *text_content);
int check_command(char **command, char *input, int counter, char **argv);

/** Environment Functions */
int ch_dir(char **command, int status_err);
int enviro(char **cmd, int err);
int path(char **command);
int _helper(char **command, __attribute__((unused)) int status_er);
int _setenv(char **command, int status_er);

/** Builders environs */
char *_getenv(char *name);
char *builder(char *token, char *token_value);
int _echo_p(char **cmd);
int _echo(char **cmd, int st);

/** Management Errors */
void errors_print(char *command, int counter, char **argv);
void Exit_Shell(char **command, char *buff, FILE *fd);
void _perror(char **argv, int counter, char **command);
void exit_bul(char **command, char *buff, char **argv, int counter);

#endif /* SHELL_H */
