#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    printf("Before fork: parent PID = %d\n", getpid());

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("Child: my PID = %d, parent PID = %d\n", getpid(), getppid());
    } else {
        printf("Parent: my PID = %d, child PID = %d\n", getpid(), pid);
        wait(NULL);
    }
    return 0;
}
