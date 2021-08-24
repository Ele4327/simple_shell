#include "shell.h"

/**
 * new_process - Append of the new structure Pids_t
 * @tx_cont: pointer for string for saving in process.tmp
 * Return: -1 if this is Failed
*/

int new_process(char *tx_cont)
{
	char *filename = "/home/.Process.tmp";
	char *tx_conten = "PID Son --> \t\t";
	ssize_t fd, w, w2;
	int len = 0, len2 = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (tx_cont)
	{
		while (tx_cont[len])
			len++;
		while (tx_conten[len2])
			len2++;
		w2 = write(fd, tx_conten, len2);
		w = write(fd, tx_cont, len);
		if (w < 0 || w2 < 0)
			return (-1);
	}
	return (1);
}

/**
 * get_process - Dysplay all process one file
 * Return: -1 if this is Failed
*/

int get_process(void)
{

	pid_Father_t my_ppid;
	pid_Son_t my_pid;
	ssize_t _fd_tops, append_pids;

	my_ppid.file = "/home/.Process.tmp";
	my_pid.file = "/home/Process.tmp";
	my_ppid.text = "Process Father ----> \t\t\t\t";
	my_pid.text = "Process son ----> \t\t\t\t";
	if (!my_ppid.file || !my_pid.file)
		return (-1);
	my_ppid.pid = getppid();
	if (my_ppid.pid != 0)
	{
		_fd_tops = open(my_ppid.file, O_CREAT | O_RDWR, 0664);
		if (_fd_tops < 0)
			return (99);

		my_ppid.text_pid = _itoa(my_ppid.pid);
		if (my_ppid.text_pid != NULL)
		{
			new_process(my_ppid.text_pid);
		}
	}
	my_pid.pid = getpid();
	if (my_pid.pid != 0)
	{
		my_pid.text_pid = _itoa(my_pid.pid);
		if (my_pid.text_pid != NULL)
		{
			append_pids = new_process(my_pid.text_pid);
		}
	}

	close(_fd_tops);

	(void)append_pids;
	return (0);
}

/**
 * pids_Son - Create one New Pid
 * @cmd: Commando for historial
 * Return: -1 if this is Failed or if this is succes 0
*/

int pids_Son(char *cmd)
{
	pid_Son_t my_pid;

	my_pid.file = "/home/.Process.tmp";
	my_pid.text = "Process son ----> \t\t\t\t";

	if (cmd == NULL)
		return (-1);

	if (!my_pid.file)
		return (-1);
	my_pid.pid = fork();
	if (my_pid.pid == -1)
	{
		perror("Error");

		return (-1);
	}
	if (my_pid.pid == 0)
	{
		my_pid.text_pid = _itoa(my_pid.pid = getpid());
		if (my_pid.text_pid != NULL)
		{
			new_process(my_pid.text_pid);
		}
		return (0);
	}

	return (1);
}

/**
 * history - Fill File By User Input
 * @input: User Input
 * Return: -1 if this is Failed or if this is succes 0
*/

int history(char *input)
{
	char *filename = "/home/.simple_shell_history";
	ssize_t fd, w;
	int len = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (input)
	{
		while (input[len])
			len++;
		w = write(fd, input, len);
		if (w < 0)
			return (-1);
	}
	return (1);
}
