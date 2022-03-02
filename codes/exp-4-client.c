#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define FIFO1 "fifo1"
#define FIFO2 "fifo2"
#define PERMS 0666

char fname[256];

int main(void) {
	int readfd, writefd;
	ssize_t n;
	char buf[512];
	
	printf("Trying to connect to server...\n");
	writefd = open(FIFO1, O_WRONLY, 0);
	readfd = open(FIFO2, O_RDONLY, 0);
	printf("Connected!\n");
	printf("Enter the filename to be requested from server : ");
	scanf("%s", fname);
	write(writefd, fname, strlen(fname));
	printf("Waiting for the server to reply...\n");
	while ((n = read(readfd, buf, 512)) > 0)
		write(1, buf, n);
	close(readfd);
	close(writefd);
	return 0;
}
