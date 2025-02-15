#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig) {
    printf("Child received signal %d\n", sig);
}

int main() {
    pid_t pid = fork();
    if (pid == 0) { // Child
        signal(SIGUSR1, handler);
        pause(); // Περιμένει σήμα
    } else { // Parent
        sleep(1);
        kill(pid, SIGUSR1);
    }
    return 0;
}
