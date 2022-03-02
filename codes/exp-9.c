#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>

int system1(const char *cmdstring) {
	pid_t pid;
	int status;
	
	if (cmdstring == NULL) 
		return 1;
	else if ((pid = fork()) < 0) 
		status = -1;
	else if (pid == 0) {
		execl("/bin/sh", "sh", "-c", cmdstring, (char*)0);
		_exit(127);
	}
	else {
		while(waitpid(pid, &status, 0) < 0) {
			if (errno != EINTR) 
				status = -1;
		}
	}
	return status;
}

int main(void) {
	int status;
	if ((status = system1("date")) < 0) 
		perror("system");
	if ((status = system1("who")) < 0) 
		perror("system");
	if ((status = system1("whoami")) < 0) 
		perror("system");
	return 0;
}
