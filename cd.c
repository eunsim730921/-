#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "방법: %s <디렉토리 경로>\n", argv[0]);
        return 1;
    }

    if (chdir(argv[1]) != 0) {
        perror("실패");
        return 1;
    }

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("변경된 디렉토리: %s\n", cwd);
    } else {
        perror("오류");
        return 1;
    }

    return 0;
}

