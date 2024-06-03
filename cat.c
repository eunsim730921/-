#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "방법: %s <파일1> <파일2> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            perror(argv[i]);
            continue;
        }

        int ch;
        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch);
        }

        fclose(fp);
    }

    return 0;
}

