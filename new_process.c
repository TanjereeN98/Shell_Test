#include "shell.h"
/**
 * new_process - function to create a new process and execute within
 * @buff: buffer which contains the command and argument
 * @argv: veriable vector needed to print error with program name.
 */

void new_process(char **args, char **argv)
{
	pid_t my_pid;

	if (access(args[0], X_OK) == -1)
	{
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	my_pid = fork();
	if (my_pid == -1)
	{
		perror("Error happened\n");
		exit(EXIT_FAILURE);
	}
	if (my_pid == 0)
	{
		execvp(args[0], args);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}