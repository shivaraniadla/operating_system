#include <unistd.h> 
#include <sys/wait.h>
#include <stdio.h>
int main()
{
	pid_t child_pid;
	child_pid = fork(); //create new process
	if (child_pid < 0 ) {
		printf("fork failed");
		return 1;
	} else if (child_pid == 0) {
		printf("\nchild process successfully created!\n");
		printf("\nchild_pid = %d,parent_pid = %d\n", getpid(), getppid());
	} else {
		wait(NULL);
		printf("\nparent process successfully created!\n");
		printf("\nchild_pid = %d, parent_pid = %d\n", getpid(), getppid());
	}
	return 0;
}
