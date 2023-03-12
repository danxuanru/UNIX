#include "apue.h"
#include <sys/wait.h>

static void sig_int(int); /* our signal-catching function */
int main(void)
{
	char buf[MAXLINE]; /* from apue.h */
	pid_t pid;
	int status;

	if (signal(SIGINT, sig_int) == SIG_ERR)
		err_sys("signal error");

	printf("%% "); /* print prompt (printf requires %% to print %) */
	while (fgets(buf, MAXLINE, stdin) != NULL)
	{
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0; /* replace newline with null */

		// split string
		const char *p = strtok(buf, " ");
		const char *argv[4];
		int i = 0;
		while (p != NULL)
		{
			argv[i++] = p;
			p = strtok(NULL, " ");
		}
		argv[i] = NULL; // give a NULL at the end

		// printf("%s\n", argv[0]);

		// cd directory
		if (strcmp(argv[0], "cd") == 0)  // string compare
		{
			chdir(argv[1]);
		}
		else
		{
			if ((pid = fork()) < 0)
			{
				err_sys("fork error");
			}
			else if (pid == 0)
			{ /* child */
				// execlp(buf, buf, (char *)0);

				execvp(argv[0], (char *const *)argv); // (const char**) to (char *const *)
				err_ret("couldn't execute: %s", buf);
				exit(127);
			}

			/* parent */
			if ((pid = waitpid(pid, &status, 0)) < 0)
			{
				err_sys("waitpid error");
			}
		}

		printf("%% ");
	}
	exit(0);
}

void sig_int(int signo)
{
	printf("interrupt\n%% ");
}
