#include<iostream>
#include<unistd.h>
using namespace std;

static void charatatime(char *);

int main(void) {
	pid_t pid;
	pid = fork();
	if (pid < 0) 
		perror("fork error");
	else if (pid == 0) {
		// inside the child 
		charatatime("Output from child\n");
	}
	else {
		// inside the parent
		charatatime("Output from parent\n");
	}
	return 0;
}

static void charatatime(char *str) {
	char *ptr;
	int c;
	setbuf(stdout, NULL);
	for (ptr = str; (c = *ptr++) != 0; ) {
		putc(c, stdout);
	}
}
