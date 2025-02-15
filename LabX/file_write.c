#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd = open("pids.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    pid_t pid = fork();
    dprintf(fd, "PID: %d\n", getpid());
    close(fd);
    return 0;
}
