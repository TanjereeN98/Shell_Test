#include "shell.h"

int main(int argc, char *argv[], char **env)
{
	pid_t my_pid;
	char *buff = NULL;
	char **tokens;
	void (*funptr)(int, char **);
	int exit_status = 0, i = 0;

	history = 1;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		buff = read_line();
		if (buff == NULL)
			continue;
		tokens = token_line(buff, " ");
		exit_status = tokens[1] ? _atoi(tokens[1]) : 0;
		funptr = find_fun(tokens[0]);
		if (funptr != NULL)
		{
			history++;
			funptr(exit_status, env);
		}
		else
			fork_process(tokens, argv, env);
		free(buff);
		if (!isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}
	exit(EXIT_FAILURE);
}
