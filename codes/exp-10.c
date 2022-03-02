#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#define INTERVAL 5

void callme(int sig_no) { // print the follwing messages on the reception of signal SIGALRM
	printf("Time interval elapsed!\n");
	printf("WAKEUP!\n");
}

int main(void) {
	struct sigaction action;
	action.sa_handler = callme; // set signal handler routine
	sigemptyset(&action.sa_mask); // clear all signals in mask
	
	// set course for handling SIGALRM
	if (sigaction(SIGALRM, &action, 0) == -1) { // course could not be set
		perror("sigaction");
	}
	else { // course set
		alarm(INTERVAL); // set alarm of INTERVAL seconds 
		pause(); // wait until signal SIGALRM is received
	}
	return 0;
}
