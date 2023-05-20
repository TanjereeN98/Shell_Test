#include "shell.h"

int main(int argc, char *argv[])
{
	pid_t my_pid;
	char *buff = NULL;
	char **args;
	
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		buff = read_line();
		if (buff == NULL)
		{
			continue;
		}
		args = token_line(buff);
		new_process(args, argv);
		free(buff);
		free(args);
		if (!isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
	}
	exit(EXIT_FAILURE);
}
