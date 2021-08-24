#include "shell.h"

/**
 * new_process - Append of the new structure Pids_t
 * @filename: File Descriptor
 * @tx_cont: pointer for string for saving in process.tmp
 * @tx_conten:  pointer for next string for saving in process.tmp
 * Return: -1 if this is Failed
*/

int new_process(const char *filename, char *tx_cont, char *tx_conten)
{
	int o, w, w2, len = 0, len1 = 0;

	if (filename == NULL)
		return (-1);

	if (tx_cont != NULL)
	{
		for (len = 0; tx_cont[len];)
			len++;
	}
	if (tx_conten != NULL)
	{
		for (len1 = 0; tx_conten[len1];)
			len1++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w2 = write(o, tx_conten, len1);
	w = write(o, tx_cont, len);

	if (o == -1 || w == -1 || w2 == -1)
		return (-1);

	close(o);

	return (-1);
}

/**
 * get_process - Dysplay all process one file
 * @c:parameter unused
 * Return: -1 if this is Failed
*/

int get_process(void)
{

	pid_Father_t my_ppid;
	pid_Son_t my_pid;
	ssize_t _fd_tops, append_pids;

	my_ppid.file = "process.tmp";
	my_pid.file = "Process.tmp";
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
			new_process(my_ppid.file, my_ppid.text_pid, my_ppid.text);
		}
	}
	my_pid.pid = getpid();
	if (my_pid.pid != 0)
	{
		my_pid.text_pid = _itoa(my_pid.pid);
		if (my_pid.text_pid != NULL)
		{
			append_pids = new_process(my_pid.file, my_pid.text_pid, my_pid.text);
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
	ssize_t _fd_tops;

	my_pid.file = "Process.tmp";
	my_pid.text = "Process son ----> \t\t\t\t";

	if (cmd == NULL)
	{
		perror("Error");
		return (-1);
	}
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

		_fd_tops = open(my_pid.file, O_CREAT | O_RDWR, 0664);
		if (_fd_tops == -1)
			return (-1);
		my_pid.text_pid = _itoa(my_pid.pid = getpid());
		if (my_pid.text_pid != NULL)
		{
			new_process(my_pid.file, my_pid.text_pid, my_pid.text);
		}

		return (0);
	}

	return (-1);
}

/**
 * history - Fill File By User Input
 * @input: User Input
 * Return: -1 if this is Failed or if this is succes 0
*/

int history(char *input)
{
	char *filename = ".simple_shell_history";
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
