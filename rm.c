#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "방법: %s 파일1.\n", argv[0]);
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++) {
        if (unlink(argv[i]) == -1) {
            perror("실패");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

