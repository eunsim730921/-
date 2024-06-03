#include <stdio.h>
#include <stdlib.h>

#define LINE_COUNT 5

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "방법: %s <파일 이름>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("실패했음");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    long pos = fileSize;
    int lineCount = 0;
    char c;

    while (pos > 0 && lineCount <= LINE_COUNT) {
        fseek(file, --pos, SEEK_SET);
        c = fgetc(file);
        if (c == '\n') {
            lineCount++;
        }
    }

    if (lineCount > LINE_COUNT) {
        fseek(file, pos + 2, SEEK_SET);
    } else {
        fseek(file, 0, SEEK_SET);
    }

    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    fclose(file);
    return 0;
}

