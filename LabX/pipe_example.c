#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
	int fd[2];
	pipe(fd);
	if(fork() == 0) {
		close(fd[1]);
		char msg[20];
		read(fd[0], msg, sizeof(msg));
		printf("Child received: %s\n", msg);
	} else {
		close(fd[0]);
		char msg[] = "Hello, Child!";
		write(fd[1], msg, strlen(msg) + 1);
	}
	return 0;
}
