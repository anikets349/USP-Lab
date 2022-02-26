#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(void) {
	pid_t child_pid;
	child_pid = fork();
	
	if (child_pid == 0) {
		// inside the parent
		exit(0);
	}
	else {
		sleep(3);
		system("ps -e -o pid,ppid,stat,cmd");
	}
	return 0;
}
