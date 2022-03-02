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
	int readfd, writefd, fd;
	ssize_t n;
	char buf[512];
	
	if (mkfifo(FIFO1, PERMS) < 0 || mkfifo(FIFO2, PERMS))
		perror("Cannot create FIFO files");
	printf("Waiting for connection request...\n");
	readfd = open(FIFO1, O_RDONLY, 0);
	writefd = open(FIFO2, O_WRONLY, 0);
	printf("Connection estabilished...\n");
	read(readfd, fname, 255);
	printf("Client requested for file: %s\n", fname);
	fd = open(fname, O_RDWR);
	if (fd < 0) {
		strcpy(buf, "File does not exist!\n");
		write(writefd, buf, strlen(buf));
	}
	else {
		while ((n = read(fd, buf, 512)) > 0) {
			write(writefd, buf, n);
		} 
	}
	close(readfd); unlink(FIFO1);
	close(writefd); unlink(FIFO2);
	return 0;
}

