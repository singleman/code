#include "apue.h"
#include <sys/wait.h>
#include "error.c"

int main(void)
{
	char	buf[MAXLINE];
	pid_t	pid;
	int	status;

	printf("%% ");
	while (fgets(buf,MAXLINE,stdin) != NULL)  //how to change break chapter 18?
	{
		if (buf[strlen(buf) - 1] == '\n')
			buf[strlen(buf) - 1] = 0; //what's meaning of '0'?
		if ((pid = fork()) < 0)
		{
			err_sys("fork error");
		}else if (pid == 0)
			{
				execlp(buf,buf,(char *)0);
				err_ret("couldn't execute: %s",buf);
				exit(127);	//127?
			}

		if ((pid = waitpid(pid, &status, 0)) < 0)
			err_sys("waitpid error");
		printf("%% ");
	}
	exit(0);
}
