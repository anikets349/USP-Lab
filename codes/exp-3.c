#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

int main(int argc, char *argv[]) {
	char buf[50];
	struct flock lock;
	
	if (argc != 2) {
		printf("usage: %s <filename>\n", argv[0]);
		exit(0);
	}
	
	int fd = open(argv[1], O_RDWR);
	
	if (fd == -1) {
		perror("open");
		exit(0);
	}
	
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_END;
	lock.l_start = 0;
	lock.l_len = 100;
	
	fcntl(fd, F_GETLK, &lock); // get lock details if any, set by a process
	
	if (lock.l_type == F_RDLCK) {
		printf("%u has set a read lock\n", lock.l_pid);
		exit(0);
	}
	else if (lock.l_type == F_WRLCK) {
		printf("%u has set a write lock\n", lock.l_pid);
		exit(0);
	}
	
	lock.l_type = F_WRLCK;
	lock.l_pid = getpid();
	
	if (fcntl(fd, F_SETLKW, &lock) == -1) {
		perror("fcntl");
		exit(0);
	}
	else {
		printf("Write lock successfully set by process with PID %u.\n", getpid());
		lseek(fd, -50, SEEK_END);
		int rc = read(fd, buf, 50);
		if (rc > 0) {
			printf("Last 50 bytes of the file : \n");
			printf("%s\n", buf);
		}
	}
	
	lock.l_type = F_UNLCK;
	lock.l_whence = SEEK_CUR;
	lock.l_start = 0;
	lock.l_len = 100;
	
	if (fcntl(fd, F_SETLKW, &lock) == -1) {
		perror("fcntl");
		exit(0);
	}
	printf("File successfully unlocked!\n");
	
	return 0;
}
