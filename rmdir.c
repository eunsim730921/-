#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "방법: %s 디렉토리_이름\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (rmdir(argv[1]) == -1) {
        perror("rmdir");
        return EXIT_FAILURE;
    }

    printf("디렉토리 삭제되었습니다: %s\n", argv[1]);
    return EXIT_SUCCESS;
}

