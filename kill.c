#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "방법: %s <pid>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    int result = kill(pid, SIGKILL);

    if (result == 0) {
        printf("과제 드디어 %d끝났다!!!!!!.\n", pid);
    } else {
        perror("실패홤");
        return 1;
    }

    return 0;
}

