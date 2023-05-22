#include "shell.h"
/**
 * fork_process - creates a new process and execute within
 * @args: tokenized input (commands + arguments)
 * @argv: argv from main passed
 * @env: environment variables
 */

void fork_process(char **args, char **argv, char **env)
{
	pid_t my_pid;
	paths current_paths = handle_path(env, args);
	size_t i, flag = access(current_paths.my_paths[i - 1], X_OK) != 0;
	int len_2;

	for (i = 0 ; i < current_paths.size ; i++)
	{
		if (access(current_paths.my_paths[i], X_OK) == 0)
		{
			my_pid = fork();
			if (my_pid == -1)
			{
				perror("Error happened\n");
				exit(EXIT_FAILURE);
			}
			if (my_pid == 0)
			{
				execve(current_paths.my_paths[i], args, env);
			}
			else
			{
				wait(NULL);
				break;
			}
		}
	}
	len_2 = _strlen(argv[0]);
	if (i == current_paths.size && flag)
		perror(argv[0]);
	qol_free(current_paths.my_paths, current_paths.size);
}

/**
*history_s = _itoa(history);len = _strlen(argv[0]) + 
*_strlen(history_s) + _strlen(args[0]) + 24;
*last = malloc(sizeof(char) * (len + 1));
*p_name = _strdup(argv[0]);
*args_dup = _strdup(args[0]);
*last = _strcat(last, history_s);
*last = _strcat(last, ": ");
*last = _strcat(last, args[0]);
*last = _strcat(last, ": not found\n");
*p_name = _strcat(p_name, last);
*len_2 = _strlen(p_name) + 1;
*/
