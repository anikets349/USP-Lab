#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void) {
	int pid = fork();
	if (pid == 0) { 
		// inside the first child
		pid = fork(); // creates the second child or grandchild
		if (pid == 0) {
			// inside the second child
			sleep(1);
			printf("Grandchild PID : %d\n", getpid());
			printf("Child PID : %d\n", getppid());
		}
	}
	else {
		wait(NULL);
		system("ps -o pid,ppid,stat,tty,command");
	}
	return 0; 
}
