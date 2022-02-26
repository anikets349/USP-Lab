#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#define INTERVAL 5

void callme(int sig_no) {
	alarm(INTERVAL);
	printf("WAKEUP!\n");
}

int main(void) {
	struct sigaction action;
	action.sa_handler = callme;
	sigaction(SIGALRM, &action, 0);
	alarm(2);
	sleep(5);
	return 0;
}
